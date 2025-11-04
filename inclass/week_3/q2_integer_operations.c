#include<stdio.h>

int main(int argc, char** argv){

    float a = 1, b = 2, c=3, d, e;

    d = a/b;
    e = a/c;

    printf("a=%17.15f, b=%17.15f, c=%17.15f\n, d=%17.15f, e=%17.15f \n",a, b, c, d, e);

    return 0;
}