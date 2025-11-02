#include <iostream>

#define BLOCK 2

#if BLOCK == 1
int main (int argc, char* argv[]) 
{
	std::cout << "Empty main function" << std::endl;
	return 0;
}

#elif BLOCK == 2

namespace Math {
    int add(int x, int y){return x+y;}
    int multiply(int x, int y){return x*y;}
}

int main(int argc, char* argv[]) {
    std::cout << "Simple main function" << std::endl;
    // We open a code block
    {
        // Next, we declare a variable
        int a;
        // Next, we assign a value to the variable
        a = 5;
        double b = 2.5;
        int result = Math::multiply(a,b);
        std::cout << result << std::endl;
    }
    // The variable a is no longer there
    return 0;
}

#elif BLOCK == 3
using namespace std; 

// Function prototype (declaration)
int add(int a, int b);

int main() {              // Main function
    int result = add(2, 3); // Function call statement
    cout << "Result = " << result << endl; // Debug output statement
    return 0; // Return statement
}

// Function definition
int add(int a, int b) {
    return a + b;
}

#elif BLOCK == 4

using namespace std;

int main() {
    int x = 5, y = 10;

    // Comparison examples
    cout << (x == y) << endl;   // 0 (false), 5 != 10
    cout << (x < y) << endl;    // 1 (true), 5 < 10
	
    // Logical operator examples
    bool a = true, b = false;
    cout << (a && b) << endl;   // 0, true AND false
    cout << (a || b) << endl;   // 1, true OR false
    cout << (!a) << endl;       // 0, NOT true
	
    return 0;
}

#elif BLOCK == 5

#include <bitset>
using namespace std;

int main() {
    short a = 30000;   // 0111 0101 0011 0000 
    short b = 12345;   // 0011 0000 0011 1001 
    cout << "a      = " << bitset<16>(a) << endl;
    cout << "b      = " << bitset<16>(b) << endl;
    cout << "a & b  = " << bitset<16>(a & b) << endl;
    // 0011 0000 0011 0000 
    cout << "a ^ b  = " << bitset<16>(a ^ b) << endl;
    // 0100 0101 0000 1001 
    cout << "a << 3 = " << bitset<16>(a << 3) << endl;
    // 1010 1001 1000 0000 
    cout << "a >> 5 = " << bitset<16>(a >> 5) << endl;
    // 0000 0011 1010 1001 
}

#elif BLOCK == 6

#include <iomanip>   // for formatting
using namespace std; // cout belongs to namespace std

int main() {
    int x = 5;
    double y = 2.578;
    // Printing variable values
    cout << "x = " << x << ", y = " << y << endl;
    // Formatting floating-point output
    cout << fixed << setprecision(2); // Display as decimal with two fractional digits 
    cout << "x " << x << " y (2 decimals) = " << y << endl;
    return 0;
}

#elif BLOCK == 7

using namespace std;

int main() {
	int temp;
	cout << "Enter temperature in °C: ";
	cin >> temp; // Terminal input

	if (temp > 30) {
	    cout << "It's hot!" << endl;
	}
	else if (temp > 15) {
	    cout << "It's mild." << endl;
	}
	else
	    cout << "It's cold." << endl;
    return 0;
}

#elif BLOCK == 8

#include <iostream>
using namespace std;

int main() {
    int a, b;
    char op;
    cout << "Enter operation with '+', '-', '*'. E.g. 5 + 3";
    cin >> a >> op >> b;
    switch (op) {
        case '+': // Compare 'op' to '+'
	cout << a << " + " << b << " = " << (a + b) << endl; 
	break;
        case '-': cout << a << " - " << b << " = " << (a - b) << endl; break;
        case '*': cout << a << " * " << b << " = " << (a * b) << endl; break;
        default: cout << "Invalid operator" << endl;
    }
    return 0;
}

#elif BLOCK == 9

using namespace std;

int main() {
    // for loop
    for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    cout << endl;

    // while loop
    int j = 1;
    while (j <= 5) {
        cout << j << " ";
        j++;
    }
    cout << endl;

    // do-while loop
    int k = 1;
    do {
        cout << k << " ";
        k++;
    } while (k <= 5);
    cout << endl;

    return 0;
}

#elif BLOCK == 10

#include <iostream>
using namespace std;

// Function declarations (prototypes)
int add(int a, int b);
double average(double x, double y);

int main() {
    int a = 6, b = 4;

    cout << "Sum: " << add(a, b) << endl;
    cout << "Average: " << 	average(a, b) << endl;

    return 0;
}


// Function definitions (after main)
int add(int a, int b) {
    return a + b;
}

double average(double x, double y) {
    return (x + y) / 2.0;
}

#endif