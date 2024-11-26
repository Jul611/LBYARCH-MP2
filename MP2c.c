#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


extern double asm_dot_product(double *A, double *B, int n);


double c_dot_product(double *A, double *B, int n) {
    double sdot = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        sdot += A[i] * B[i];
    }
    return sdot;
}


double get_time_in_ms() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000.0 + ts.tv_nsec / 1.0e6;
}


void initialize_vectors(double *A, double *B, int n) {
    srand(0); // Fixed seed for repeatable results
    int i;
    for (i = 0; i < n; i++) {
        A[i] = (double)(rand() % 100) / 10.0; // Random values between 0.0 and 10.0
        B[i] = (double)(rand() % 100) / 10.0;
    }
}

int main() {
    int exp_N;
    printf("Enter the exponent N (to calculate array size 2^N): ");
    scanf("%d", &exp_N);

    int N = pow(2, exp_N); 
    printf("Array size: %d\n", N);

    
    double *A = (double *)malloc(N * sizeof(double));
    double *B = (double *)malloc(N * sizeof(double));

    if (A == NULL || B == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    
    initialize_vectors(A, B, N);

   
    double start = get_time_in_ms();
    double sdot_c = c_dot_product(A, B, N);
    double end = get_time_in_ms();
    printf("C Dot Product: %f (Time: %f ms)\n", sdot_c, end - start);

    
    start = get_time_in_ms();
    double sdot_asm = asm_dot_product(A, B, N);
    end = get_time_in_ms();
    printf("ASM Dot Product: %f (Time: %f ms)\n", sdot_asm, end - start);

    
    if (sdot_c == sdot_asm) {
        printf("Results match!\n");
    } else {
        printf("Results do not match! C: %f, ASM: %f\n", sdot_c, sdot_asm);
    }

    
    free(A);
    free(B);

    return 0;
}

