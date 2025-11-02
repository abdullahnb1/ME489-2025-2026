#include<stdio.h>

int main(int argc, char** argv){

    /* int a, b, c;   it is a trap */
    
    int a = 1, b = 2, c;

    c = a + b;

    printf("%d is product of %d and %d", c, a, b);

    return 0;

}