#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <math.h>

void Usage(char* prog_name);
void Trap(double a, double b, int n, double* global_result_p);
double f(double x);

/* The function we're integrating */
double f(double x) {
    return x * x;   // x^2
}

/* Print usage message */
void Usage(char* prog_name) {
    fprintf(stderr, "Usage: %s <number_of_threads>\n", prog_name);
    exit(0);
}

/* Parallel trapezoidal rule */
void Trap(double a, double b, int n, double* global_result_p) {

    double h = (b - a) / n;
    double local_a, local_b;
    int local_n;
    double local_result = 0.0;

    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();

    /* trapezoids per thread */
    local_n = n / thread_count;

    /* each thread’s interval */
    local_a = a + my_rank * local_n * h;
    local_b = local_a + local_n * h;

    /* trapezoidal rule on the subinterval */
    local_result = (f(local_a) + f(local_b)) / 2.0;

    for (int i = 1; i < local_n; i++) {
        double x = local_a + i * h;
        local_result += f(x);
    }

    local_result *= h;

    /* safely update global sum */
    #pragma omp atomic
    *global_result_p += local_result;
}

int main(int argc, char **argv) {

    double global_result = 0.0;
    double a, b;
    int n;
    int thread_count;

    if (argc != 2)
        Usage(argv[0]);

    thread_count = strtol(argv[1], NULL, 10);

    printf("Enter a, b, and n:\n");
    scanf("%lf %lf %d", &a, &b, &n);

    if (n % thread_count != 0) {
        fprintf(stderr, "n must be divisible by number of threads.\n");
        exit(0);
    }

    #pragma omp parallel num_threads(thread_count)
    Trap(a, b, n, &global_result);

    printf("With n = %d trapezoids, our estimate\n", n);
    printf("of the integral from %f to %f = %.14e\n",
           a, b, global_result);

    return 0;
}

