

#define BLOCK 2

#if BLOCK == 1
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    cout << "Number of arguments: " 
	<< argc << endl;

    for (int i = 0; i < argc; i++) {
        cout << "arg[" << i << "] = " 
	<< argv[i] << endl;
    }
    return 0;
}

#elif BLOCK == 2

#include <iostream>
#include <cstdlib>   // for atoi
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] 
	<< " num1 num2 [num3 ...]" << endl;
        return 1; // exit with error
    }
    int sum = 0;
    for (int i = 1; i < argc; i++) {
        sum += atoi(argv[i]);   // convert string → int
    }
    cout << "Sum = " << sum << endl;
    return 0;
}

#endif
