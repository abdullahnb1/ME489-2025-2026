#include <iostream>
#include <cstring>
#include <cstdlib>   // for atoi
using namespace std;
int main(){
char str1[] = "Hello";         
// length excluding '\0'
cout << " length: " << strlen(str1) <<  endl;
char dest[20];
strcpy(dest, str1); // copies "Hello" into dest
strcat(dest, " World"); // dest = "Hello World"
// equal strings
if (strcmp(str1, "Hello") == 0) 
   cout << " Strings are equal" << endl; 
// convert char numStr[] = "456“ to int     
char numStr[] = "456";     // C-string
int value = atoi(numStr); 
cout << " number: " << value <<  endl;;
return 0;
}  
