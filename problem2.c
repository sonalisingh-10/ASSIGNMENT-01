//Problem 2: Array Transformation Cost Minimization 

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) 
{
    return (*(int *)a - *(int *)b);
}

int minOperations(int A[], int n, int K) 
{

    // Step 1: feasibility check
    int mod = A[0] % K;
    for (int i = 1; i < n; i++) {
        if (A[i] % K != mod) {
            return -1;
        }
    }

    // Step 2: convert array
    int B[n];
    for (int i = 0; i < n; i++) 
    {
        B[i] = A[i] / K;
    }

    // Step 3: sort
    qsort(B, n, sizeof(int), compare);

    // Step 4: median
    int median = B[n / 2];

    // Step 5: count operations
    int operations = 0;
    for (int i = 0; i < n; i++) 
    {
        operations += abs(B[i] - median);
    }

    return operations;
}

int main() {
    int n, K;
    scanf("%d", &n);

    int A[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    scanf("%d", &K);

    int result = minOperations(A, n, K);
    printf("%d\n", result);

    return 0;
}