#include <iostream>

using namespace std;

long factorial(const int n)
{
    long f = 1;
    for (int i=1; i<=n; ++i)
        f *= i;
    return f;
}


int main(){
	int facs[10];
	for (int i = 0; i < 10; i++)
		facs[i] = factorial(i);
	for (int i = 0; i < 10; i++)
    	cout << "factorial(" << i << ") is "  << facs[i] << endl;
	return 0;
}

