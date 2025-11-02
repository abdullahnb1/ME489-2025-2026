#include <iostream>

using namespace std;

int main(){
    int arr[7];
    int i;
    // Insert values in arrray
    for(i=0; i<7; i++)
        arr[i] = i;
    // Print values in array
    for(i=0;i<7;i++)
        cout << arr[i] << " ";
    cout << endl;
    // Print addresses
    for(i=0;i<7;i++)
        cout<< &arr[i] << endl;
    // Access values by dereferencing
    for(i=0;i<7;i++)
        cout << *(arr+i) << " ";
    cout << endl;
    // Pointer for first array element
    int *p=arr;
    // Print values using pointer increment
    for(i=0;i<7;i++){
        cout << *p << " ";
        p++;
    }
    cout << endl << endl;


    double d;
    cout << sizeof(d) << endl;
    double *pd;
    double *q = pd+3;
    cout << pd << " " << q << endl;


    return 0;
}
