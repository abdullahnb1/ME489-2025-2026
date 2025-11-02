#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int Ndata;
    int *data;
} array_t;

array_t arrayConstructor(int Ndata){
    array_t a;
    a.Ndata = Ndata;
    a.data = (int *) calloc(Ndata, sizeof(int));

    if(a.data == NULL){
        fprintf(stderr, "Warning: arrayconstructor calloc failed\n");
    }
    return a;
}

int arrayGet(array_t a, int n){

#if ARRAY_DEBUG==1
    if(n<0 || n>=a.Ndata){
        fprintf(stderr, "Warning: arrayGet size %d array bounds error with index %d\n", a.Ndata, n);
        return 0;
    }
     if(a.data == NULL){
        fprintf(stderr, "warning:");
        return 0;
    }
    
#endif

    return a.data[n];
}

void arraySet(array_t a, int n, int val){

#if ARRAY_DEBUG==0
    if(n<0 || n>=a.Ndata){
        fprintf(stderr, "Warning: arrayGet size %d array bounds error with index %d\n", a.Ndata, n);
        return;
    }
    if(a.data == NULL){
        fprintf(stderr, "warning:");
        return;
    }
    
#endif

    a.data[n] = val;
}

array_t arrayDestructor(array_t a){
    if(a.data == NULL){
        fprintf(stderr, "Warning");
    }
    else{
        free(a.data);
    }
    //zero length of array
    a.Ndata = 0;

    return a;
}



/*----------------------------------------------*/


array_t arrayRead(const char *file){

    array_t a;

    FILE *fp = fopen(file, "r");
    if(fp){
        char buffer[BUFSIZ];
        /* skip header line */
        fgets(buffer, BUFSIZ, fp);

        /* read next line */
        int Ndata;
        fgets(buffer, BUFSIZ, fp);
        sscanf(buffer, "%d", &Ndata);

        /* construct array */
        a = arrayConstructor(Ndata);

        /* skip header line */
        fgets(buffer, BUFSIZ, fp);

        /* read array entries */
        int n, m;
        for(n=0;n<a.Ndata;n=n+1){
            fscanf(fp, "%d", &m);
            arraySet(a, n, m); /* a[n] = m */
        }
        fclose(fp);
    }
    else{
        a = arrayConstructor(0);
    }
    return a;
}



void arrayWrite(const char *file, array_t a) {
    FILE *fp = fopen(file, "w");

    if (fp) {
        fprintf(fp, "NUMBER OF ENTRIES IN ARRAY\n");
        fprintf(fp, "%d\n", a.Ndata);

        fprintf(fp, "ENTRIES IN ARRAY\n");
        // read array entries
        int n, b;

        for (n = 0; n < a.Ndata; n++) {
            b = arrayGet(a, n);  // b = a[n]
            fprintf(fp, "%d\n", b);
        }

        fclose(fp);
    } else {
        fprintf(stderr, "WARNING: failed to open %s to write\n", file);
    }
}


int main(int argc, char **argv) {
    int Na = 5;

    /* build array */
    array_t a = arrayConstructor(Na);

    arraySet(a, 3, 1);   /* a[3] = 1 */
    arraySet(a, 11, 2);  /* a[11] = 2 will get warning */

    int a3 = arrayGet(a, 3);  /* set a3 = a[3] */
    printf("a3 = %d\n", a3);

    /* destroy array */
    a = arrayDestructor(a);

    /* -------------------------------------------- */

    int N = 10;
    a = arrayConstructor(N);

    for (int i = 0; i < N; i++) {
        arraySet(a, i, i * i * i);
    }

    /* write array out to copy */
    const char *filename = "file.dat";
    arrayWrite(filename, a);

    /* read array back */
    array_t b = arrayRead("file.dat");

    for (int i = 0; i < N; i++) {
        printf("a[%d] = %d\n", i, b.data[i]);
    }

    arrayDestructor(a);
    arrayDestructor(b);

    return 0;
}