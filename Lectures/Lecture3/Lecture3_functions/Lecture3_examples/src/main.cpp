
#define BLOCK 9

#if BLOCK == 1
#include <iostream>

using namespace std;
void swap(int a, int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main(){
  int i = 10;
  int j = 20;
  cout << "Before swap(): i: "<<i<<" j: "<<j<<endl;
  swap(i,j);
  cout << "After swap(): i: "<<i<<" j: "<<j<<endl;
}


#elif BLOCK == 2

#include <iostream>

using namespace std;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
  int i = 10;
  int j = 20;
  cout << "Before swap(): i: "<<i<<" j: "<<j<<endl;
  swap(&i,&j);
  cout << "After swap(): i:  "<<i<<" j: "<<j<<endl;
}


#elif BLOCK == 3

#include <iostream>
using namespace std;
void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main(){
  int i = 10;
  int j = 20;
  cout << "Before swap(): i: "<<i<<" j: "<<j<<endl;
  swap(i,j);
  cout << "After swap(): i: "<<i<<" j: "<<j<<endl;
}


#elif BLOCK == 4

#include <iostream>

using namespace std;

// Helper function 
void printArray(int* start, unsigned int size){
 for(unsigned int i = 0; i < size; i++)
    cout << *(start+i) << " ";
 cout << endl << endl;
}

int main (){
    int i, *p;
    int numbers[6];
    p = numbers;
    for (i = 0; i < 6; i++)
        *(p+i)=i;
    
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


#elif BLOCK == 5

#include <iostream>

using namespace std;

// Helper function to print values
void printValues(int *a, int *b, int c, int d){
  cout << "*a: " << *a << " *b: " << *b  << " c: " << c << " d: " << d << endl;
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

#elif BLOCK == 6

#include <iostream>

using namespace std;

void triple(double &num){
	num = 3*num;
}

int main(){
   double d = 10.0;
   triple(d);
   cout << "d: " << d << endl;
   return 0;
}


#elif BLOCK == 7

#include <iostream>

using namespace std;

void triple(double &num){
	num = 3*num;
}

int main(){
	double d = 10.0;
	triple(&d);
	cout << "d: " << d << endl;
	return 0;
}


#elif BLOCK == 8

#include <iostream>

using namespace std;

void triple(double *num){
	*num = 3**num;
}

int main(){
	double d = 10.0;
	triple(&d);
	cout << "d: " << d << endl;
	return 0;
}


#elif BLOCK == 9

#include <iostream>

using namespace std;

void triple(double num){
	num = 3*num;
}

int main(){
	double d = 10.0;
	triple(d);
	cout << "d: " << d << endl;
	return 0;
}

#endif