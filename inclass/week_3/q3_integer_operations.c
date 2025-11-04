#include<stdio.h>

int main(int argc, char** argv){

    float a = 1, b = 2.e-9, c;

    c = a+b;

    printf("a = %17.15f, b = %17.15f, c = %17.15f\n", a, b, c);

    return 0;
}