
#define BLOCK 5

#if BLOCK == 1

#include <iostream>
using namespace std;

// Two functions with same arguments
int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

// Function that accepts a function pointer
void apply(int x, int y, int (*op)(int,int)) {
    cout << "Result: " << op(x, y) << endl;
}

int main() {
    apply(5, 3, add);        // Result: 8
    apply(5, 3, multiply);  // Result: 15
    return 0;
}



#elif BLOCK == 2

#include <iostream>
using namespace std;

int main() {
    // Simple lambda without capture
    auto square = [](int x) -> int { return x * x; };
    cout << square(5) << endl;   // 25
    // Lambda with capture
    int factor = 10;
    auto scale = [=](int x) { return x * factor; };
    cout << scale(3) << endl;    // 30
    // Passing lambda as argument
    auto apply = [](int a, int b, auto f) {
        cout << f(a, b) << endl;
    };
    apply(5, 3, [](int x, int y) {return x + y;}); // 8
}


#elif BLOCK == 3

#include <iostream>
using namespace std;

void apply(int a, int b, int (*f)(int,int)) {
    cout << f(a, b) << endl;
}

int multiply(int x, int y) { return x * y; }

int main() {
    // pass normal function pointer
    apply(3, 4, multiply);    
}



#elif BLOCK == 4

#include <iostream>

using namespace std;

template<typename F>
void apply(int a, int b, F f){
    cout << f(a, b) << endl;
}

int main() {
    apply(3, 4, [](int x, int y){ return x * y; }); // pass inline lambda
}



#elif BLOCK == 5

#include <iostream>

using namespace std;

// Starting from C++20
void apply(int a, int b, auto f){
    cout << f(a, b) << endl;
}

int main() {
    apply(3, 4, [](int x, int y){ return x * y; }); // pass inline lambda
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