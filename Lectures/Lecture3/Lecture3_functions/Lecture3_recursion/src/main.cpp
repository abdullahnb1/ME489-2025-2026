
#define BLOCK 2

#if BLOCK == 1

#include <iostream>
using namespace std;

// Recursive power function
int powerRec(int x, int n) {
    cout << n << " ";
    if (n == 0)  return 1;         // base case
    return x * powerRec(x, n-1);  // recursive step
}


int main() {
    int x = 2, n = 8, result;
    result = powerRec(x, n);
    cout << endl; 
    cout << x << "^" << n << " = " << result << endl;
    return 0;
}






#elif BLOCK == 2


#include <iostream>
#include <chrono>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

using namespace std::chrono;

typedef int DataType;
const int num=10000;
const int rep=10000;



int SeqSearch(DataType list[ ], int n, DataType key)
{		// note DataType must be defined earlier
		// e.g., typedef int DataType;
		// or typedef float DataType; etc.
	for (int i=0; i<n; i++)
		if (list[i]==key)
			return i;
	return -1;
}

int BinarySearch(DataType list[], int low, int high, DataType key)
{
	int mid;
	DataType midvalue;
	while (low<=high)
	{
		mid=(low+high)/2;   // note integer division, middle of array
		midvalue=list[mid];
		if (key==midvalue) return mid;
		else if (key<midvalue) high=mid-1;
			else low=mid+1;
	}
	return -1;
}

int BinSearchR(int A[], int low, int high, int key)
{
    int mid;
    int midvalue;

    // key not found is a stopping condition
    if (low > high)
        return(-1);

    // compare against list midpoint and subdivide
    // if a match does not occur. apply binary
    // search to the appropriate sublist
    else{
        mid = (low+high)/2;
        midvalue = A[mid];
        // stopping condition if key matched
        if (key == midvalue)
            return(mid);    // key found at index mid

        // look left if key < midvalue; otherwise, look right
        else if (key < midvalue)
            // recursive step
            return BinSearchR(A,low,mid-1,key);
        else
            // recursive step
            return BinSearchR(A,mid+1,high,key);
    }
}


int Power (int a[], int n, int x){
    int xpower=1;
    int result=a[0]*xpower;
    for(int i=1;i<=n;i++){
        xpower=x*xpower;
        result+=a[i]*xpower;
    }
    return result;
}

int Factorial (int n){
    if (n==0)//stopping condition is 0!
        return 1;
    else//recursive step
        return n*Factorial(n-1);
}

int Fibonacci (int n){
    int sum;
    int prev=-1;
    int result=1;
    for(int i=0;i<=n;i++){
        sum=result+prev;
        prev=result;
        result=sum;
    }
    return result;
}


int FibonacciR (int n){
    if(n==0||n==1)
        return n;
    else
        return FibonacciR(n-1)+FibonacciR(n-2);
}


int main(){
    DataType arr[num];
    int i,k;

    cout << "========================" << endl;
    cout << "======= Search =========" << endl;
    cout << "========================" << endl;
    // Insert values in array
    for(i=0; i<num; i++)
        arr[i] = i;
    // Print values in array
    if(num < 100){
        for(i=0; i<num; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    DataType key;
    int ix_seq, ix_bin, ix_binR;
    key=num+1;
    cout<<" key:"<<key<<"\n";

    auto start = high_resolution_clock::now();
    for(k=1;k<rep;k++)
        ix_seq=SeqSearch(arr, num, key);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by seq search: "
         << duration.count()/num << " microseconds" << endl;

    start = high_resolution_clock::now();
    for(k=1;k<rep;k++)
        ix_bin= BinarySearch(arr, 0, num-1, key);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by binary search: "
         << duration.count()/num << " microseconds" << endl;

    start = high_resolution_clock::now();
    for(k=1;k<rep;k++)
        ix_binR= BinSearchR(arr, 0, num-1, key);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by recursive binary search: "
         << duration.count()/num << " microseconds" << endl;

    cout << ix_seq<< " "<<ix_bin<< " "<<ix_binR;
    cout << endl;

    cout << "========================" << endl;
    cout << "======= Power =========" << endl;
    cout << "========================" << endl;
    int a[5];
    for(i=0;i<5;i++)
        a[i]=1;

    int z=Power (a, 5, 2);
    cout<<"power result: "<<z<<"\n";

    cout << "========================" << endl;
    cout << "====== Factorial =======" << endl;
    cout << "========================" << endl;
    int F=Factorial(5);
    cout<<"factorial result: "<<F<<"\n";

    cout << "========================" << endl;
    cout << "===== Fibonnacci =======" << endl;
    cout << "========================" << endl;
    int f = 30;
    start = high_resolution_clock::now();
    int fb=Fibonacci(f);
    stop = high_resolution_clock::now();
    auto durationIt = duration_cast<microseconds>(stop - start);
    start = high_resolution_clock::now();
    int fbR=FibonacciR(f);
    stop = high_resolution_clock::now();
    auto durationRec = duration_cast<microseconds>(stop - start);
    cout<< "fib result: "<<fb<<" "<<fbR<<"\n";
    cout << "Time iterative: " << durationIt.count() << " Time recursive: " << durationRec.count() << endl;

    return 0;

}




#endif