#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>

// ===== DEVICE CODE =====
__global__ void fillKernel(int N, int value, int *d_array)
{
    int idx = blockIdx.x * blockDim.x + threadIdx.x;

    if (idx < N)
        d_array[idx] = value;
}

// ===== HOST CODE =====
int main(void)
{
    int N = 1024;
    int value = 999;

    int *h_array = (int *)calloc(N, sizeof(int));

    int *d_array;
    cudaMalloc((void **)&d_array, N * sizeof(int));

    int threadsPerBlock = 256;
    int blocksPerGrid = (N + threadsPerBlock - 1) / threadsPerBlock;

    fillKernel<<<blocksPerGrid, threadsPerBlock>>>(N, value, d_array);

    // Explicit synchronization
    cudaDeviceSynchronize();

    // Error checking
    cudaError_t err = cudaGetLastError();
    if (err != cudaSuccess)
        printf("CUDA error: %s\n", cudaGetErrorString(err));

    cudaMemcpy(h_array, d_array, N * sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i < N; i++)
        printf("h_array[%d] = %d\n", i, h_array[i]);

    cudaFree(d_array);
    free(h_array);

    return 0;
}
