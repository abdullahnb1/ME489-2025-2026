#include <iostream>
#include <chrono> // for time measurements
#include <cstring>  // memset
using namespace std;
using namespace std::chrono;

typedef int DataType;

// ============================================================================
// Tunable parameters: define maximum problem size to avoid dynamic allocation
// ============================================================================
const int MAXN  = 256;     // Maximum number of items
const int MAXW  = 10000;   // Maximum capacity of the knapsack

// ============================================================================
// Utility functions
// ============================================================================
inline int imax(int a, int b) { return (a > b) ? a : b; }

// Manual reverse function for arrays
void reverse_array(int a[], int len) {
    for (int i = 0, j = len - 1; i < j; ++i, --j) {
        int t = a[i]; a[i] = a[j]; a[j] = t;
    }
}

// ============================================================================
// 0/1 Knapsack: Tabulation (2D DP)
// Complexity: O(nW), Space: O(nW)
// Produces a complete DP table suitable for backtracking
// ============================================================================
int KnapSackDP2D(const int wt[], const int val[], int n, int W, int dp[][MAXW+1]) {
    // Initialize row 0 and col 0
    for (int w = 0; w <= W; ++w) dp[0][w] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 0;
        for (int w = 1; w <= W; ++w) {
            if (wt[i - 1] <= w) {
                int take = val[i - 1] + dp[i - 1][w - wt[i - 1]];
                int skip = dp[i - 1][w];
                dp[i][w] = imax(skip, take);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

// ============================================================================
// Backtracking on the 2D DP table to reconstruct chosen items
// ============================================================================
void KnapSackBacktrack(const int wt[], const int /*val*/[], int n, int W,
                       int dp[][MAXW+1], int chosenIdx[], int &chosenCount)
{
    int i = n, w = W;
    chosenCount = 0;
    // We will collect in reverse order into a temp buffer, then reverse.
    int tmp[MAXN];
    int tcnt = 0;

    while (i > 0 && w >= 0) {
        if (dp[i][w] == dp[i - 1][w]) {
            // item (i-1) not taken
            --i;
        } else {
            // item (i-1) taken
            tmp[tcnt++] = i - 1;
            w -= wt[i - 1];
            --i;
        }
    }
    // Reverse to ascending indices
    reverse_array(tmp, tcnt);
    for (int k = 0; k < tcnt; ++k) chosenIdx[k] = tmp[k];
    chosenCount = tcnt;
}

// ============================================================================
// 0/1 Knapsack: Space-optimized DP (1D array)
// Complexity: O(nW), Space: O(W)
// Does not support straightforward backtracking
// ============================================================================
int KnapSackDP1D(const int wt[], const int val[], int n, int W) {
    static int dp[MAXW + 1];
    // Initialize to 0
    for (int w = 0; w <= W; ++w) dp[w] = 0;

    for (int i = 0; i < n; ++i) {
        // iterate capacity backwards to avoid reusing same item
        for (int w = W; w >= wt[i]; --w) {
            int take = val[i] + dp[w - wt[i]];
            if (take > dp[w]) dp[w] = take;
        }
    }
    return dp[W];
}

// ============================================================================
// 0/1 Knapsack: Recursive formulation with memoization
// Complexity: O(nW), top-down dynamic programming
// ============================================================================
int KnapSackRecMemoSolve(int i, int w, const int wt[], const int val[],
                         int memo[MAXN][MAXW + 1])
{
    if (i < 0 || w <= 0) return 0;
    int &ans = memo[i][w];
    if (ans != -1) return ans;

    // skip
    ans = KnapSackRecMemoSolve(i - 1, w, wt, val, memo);

    // take
    if (wt[i] <= w) {
        int take = val[i] + KnapSackRecMemoSolve(i - 1, w - wt[i], wt, val, memo);
        if (take > ans) ans = take;
    }
    return ans;
}

int KnapSackRecMemo(const int wt[], const int val[], int n, int W) {
    static int memo[MAXN][MAXW + 1];
    // set to -1 only for the needed ranges
    for (int i = 0; i < n; ++i)
        for (int w = 0; w <= W; ++w)
            memo[i][w] = -1;
    return KnapSackRecMemoSolve(n - 1, W, wt, val, memo);
}

// ============================================================================
// Demonstration and timing experiments
// ============================================================================
int main() {
    // ---- Parameters (you can change freely within MAXN, MAXW) ----
    const int n = 5;
    const int W = 7;
    int wt[MAXN]  = {1, 3, 4, 2, 2};
    int val[MAXN] = {1, 4, 5, 3, 4};
    const int rep = 10000;

    if (n > MAXN || W > MAXW) {
        cerr << "Increase MAXN/MAXW.\n";
        return 1;
    }

    cout << "=================================\n";
    cout << "========= 0/1 Knapsack ==========\n";
    cout << "=================================\n";
    cout << "Items (index: weight,value):\n";
    for (int i = 0; i < n; ++i) {
        cout << "  " << i << ": (" << wt[i] << "," << val[i] << ")\n";
    }
    cout << "Capacity W = " << W << "\n\n";

    // ---------- 2D DP ----------
    static int dp2d[MAXN + 1][MAXW + 1];  // only [0..n][0..W] will be used
    int best2D = 0;
    auto start = high_resolution_clock::now();
    for (int k = 0; k < rep; ++k) {
        best2D = KnapSackDP2D(wt, val, n, W, dp2d);
    }
    auto stop = high_resolution_clock::now();
    auto dur2D = duration_cast<microseconds>(stop - start);

    int chosen[MAXN]; int chosenCount = 0;
    KnapSackBacktrack(wt, val, n, W, dp2d, chosen, chosenCount);

    cout << "DP 2D best value: " << best2D << "\n";
    cout << "Chosen item indices (2D backtrack): ";
    for (int i = 0; i < chosenCount; ++i) cout << chosen[i] << " ";
    cout << "\n";
    cout << "Time (2D DP): " << dur2D.count() << " us total for " << rep
         << " runs (avg " << (double)dur2D.count() / rep << " us)\n\n";

    // ---------- 1D DP ----------
    int best1D = 0;
    start = high_resolution_clock::now();
    for (int k = 0; k < rep; ++k) {
        best1D = KnapSackDP1D(wt, val, n, W);
    }
    stop = high_resolution_clock::now();
    auto dur1D = duration_cast<microseconds>(stop - start);

    cout << "DP 1D best value: " << best1D << "\n";
    cout << "Time (1D DP): " << dur1D.count() << " us total for " << rep
         << " runs (avg " << (double)dur1D.count() / rep << " us)\n\n";

    // ---------- Recursive + Memoization ----------
    int bestRec = 0;
    start = high_resolution_clock::now();
    for (int k = 0; k < rep; ++k) {
        bestRec = KnapSackRecMemo(wt, val, n, W);
    }
    stop = high_resolution_clock::now();
    auto durRec = duration_cast<microseconds>(stop - start);

    cout << "Recursive+Memo best value: " << bestRec << "\n";
    cout << "Time (Recursive+Memo): " << durRec.count() << " us total for " << rep
         << " runs (avg " << (double)durRec.count() / rep << " us)\n";

    // Sanity check
    if (best2D != best1D || best1D != bestRec) {
        cerr << "\n[Warning] Methods disagree! Values: 2D=" << best2D
             << " 1D=" << best1D << " Rec=" << bestRec << "\n";
    }

    return 0;
}
