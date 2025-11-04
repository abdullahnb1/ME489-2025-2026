#include<stdio.h>

void asciiPrinter(char *message){
    int n=0;

    while (1)
    {
        printf("char %c => integer %d\n", message[n], (int)message[n]);
        
        if (message[n]=='\0'){break;}
        
        n = n+1;
    }
}

int main(int argc, char** argv){

    asciiPrinter("The quick brown fox Jumped over the lazy dog 5 times!");

    return 0;


}