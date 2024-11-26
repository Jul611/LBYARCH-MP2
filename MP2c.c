#include <stdio.h>
#include <time.h>



extern double asm_dot_product(double *A, double *B, int n);

double c_dot_product(double *A, double *B, int n) {
	
    double sdot = 0.0;
    int i;
    for (i=0; i < n; i++) {
        sdot += A[i] * B[i];
    }
    return sdot;
}

double get_time_in_ms() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000.0 + ts.tv_nsec / 1.0e6;
}

int main() {
    // Predefined vectors A and B
    double A[] = {1.0, 2.0, 3.0, 4.0, 5.0, 2.0, 3.0, 4.0, 5.0, 2.0, 3.0, 4.0, 5.0, 2.0, 3.0, 4.0, 5.0, 2.0, 3.0, 4.0, 4.0, 5.0, 2.0, 3.0, 4.0, 4.0, 5.0, 2.0, 3.0, 4.0 };
    double B[] = {1.0, 2.0, 3.0, 4.0, 5.0, 2.0, 3.0, 4.0, 5.0, 2.0, 3.0, 4.0, 5.0, 2.0, 3.0, 4.0, 5.0, 2.0, 3.0, 4.0, 4.0, 5.0, 2.0, 3.0, 4.0, 4.0, 5.0, 2.0, 3.0, 4.0};

    int N;
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    
   // C kernel
    double start = get_time_in_ms();
	double sdot = c_dot_product(A, B, N);
	double end = get_time_in_ms();
	
	double sdot_c = sdot;
	
	printf("C Dot Product: %f (Time: %f ms)\n", sdot, end - start);

    // asm kernel
    start = get_time_in_ms();
    sdot = asm_dot_product(A, B, N);
    end = get_time_in_ms();
    
    double sdot_asm = sdot;
    
    printf("ASM Dot Product: %f (Time: %f ms)\n", sdot, end - start);

    
    if (sdot_c == sdot_asm) {
        printf("Results match!\n");
    } else {
        printf("Results do not match!\n");
    }

    return 0;
}

