#include <iostream>

#define example 6

using namespace std;

#if example == 1

// Helper function for printing array content
void printArray(int* start, unsigned int size){
    for(unsigned int i = 0; i < size; i++)
        cout << *(start+i) << " ";
    cout << endl << endl;
}

int main (){
    int i;
    int numbers[6];
    int *p;
    p = numbers;
    for (i = 0; i < 6; i++){
        *(p+i)=i;
    }
    printArray(numbers,6);
    p = &numbers[2];  *p = 29;
    printArray(numbers,6);
    p = numbers + 3;  *p = 17;
    printArray(numbers,6);
    p = numbers; *p = 21;
    printArray(numbers,6);
    p++;  *p = 32;
    printArray(numbers,6);
    p = numbers;  *(p+4) = 16;
    printArray(numbers,6);
}

#elif example == 2

// Helper function to print values
void printValues(int *a, int *b, int c, int d){
    cout << "*a: " << *a << " *b: " << *b << " c: " << c << " d: " << d << endl;
    cout << "a: " << a << " b: " << b << endl << endl;
}

int main(){
    int *a, c, d = 5;
    int *b = &d;
    c=2;
    a = &c;
    *a = d + 12;
    printValues(a,b,c,d);
    a = b;
    *b = *a + 5;
    printValues(a,b,c,d);
}

#elif example == 3


void triple(double &num){
	num = 3*num;
}

int main(){
	double d = 10.0;
	triple(d);
	cout << "d: " << d << endl;
	return 0;
}

#elif example == 4

void triple(double &num){
	num = 3*num;
}

int main(){
	double d=10.0;
	triple(&d);
	cout << "d: " << d << endl;
	return 0;
}
#elif example == 5

void triple(double *num){
	*num = 3**num;
}

int main(){
	double d = 10.0;
	triple(&d);
	cout << "d: " << d << endl;
	return 0;
}

#elif example == 6

void triple(double num)
{
	num = 3*num;
}
int main()
{
	double d = 10.0;
	triple(d);
	cout << "d: " << d << endl;
	return 0;
}


#endif // example
