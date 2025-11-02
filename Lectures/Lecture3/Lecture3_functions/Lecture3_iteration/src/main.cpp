
#define BLOCK 2

#if BLOCK == 1

#include <iostream>
using namespace std;

// Iterative power function
int powerIter(int x, int n) {
    int result = 1;
    cout << result << " ";
    for (int i = 0; i < n; i++) {
        result *= x; // multiply x n times
        cout << result  << " ";
    }
    return result;
}

int main() {
    int x = 2, n = 8;
    cout << x << "^" << n << endl; 
    // Compute result
    cout << "Result: " << powerIter(x, n) << endl;
    return 0;
}




#elif BLOCK == 2

#include <iostream>
using namespace std;
// Fibonacci number by iteration
int fibonacciIter(int n, bool print) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int a = 0, b = 1, next;
    if (print == 1) cout << b << " ";
    for (int i = 2; i <= n; i++) {
        next = a + b;
        a = b;
        b = next;
        if (print == 1) cout << b << " ";
    }
    return b;
}

int main() {
    int n = 10;
    cout << "Fibonacci(" << n << ") = " 
	<< fibonacciIter(n,true) << endl;

    cout << "First 10 Fibonacci numbers: ";
    for (int i = 0; i < n; i++) {
        cout << fibonacciIter(i,false) << " ";
    }
    cout << endl;
    return 0;
}


#endif