
//Assignment 4 : Write a CUDA Program for : Addition of two large vectors 



//CUDA Program for Addition of two large vectors 

#include <iostream>
#include <cuda_runtime.h>
__global__ void addVectors(int* A, int* B, int* C, int n) {
int i = blockIdx.x * blockDim.x + threadIdx.x;
if (i < n) {
C[i] = A[i] + B[i];
}
}
int main() {
int n = 1000000;
int* A, * B, * C;
int size = n * sizeof(int);
// Allocate memory on the host
cudaMallocHost(&A, size);
cudaMallocHost(&B, size);
cudaMallocHost(&C, size);
// Initialize the vectors
for (int i = 0; i < n; i++) {
A[i] = i;
B[i] = i * 2
// Allocate memory on the device
int* dev_A, * dev_B, * dev_C;
cudaMalloc(&dev_A, size);
cudaMalloc(&dev_B, size);
cudaMalloc(&dev_C, size);
// Copy data from host to device
cudaMemcpy(dev_A, A, size, 
cudaMemcpyHostToDevice);
cudaMemcpy(dev_B, B, size, 
cudaMemcpyHostToDevice);
// Launch the kernel
int blockSize = 256;
int numBlocks = (n + blockSize 
- 1) / blockSize
// Copy data from device to host
cudaMemcpy(C, dev_C, size, cudaMemcpyDeviceToHost);
// Print the results
for (int i = 0; i < 10; i++) {
cout << C[i] << " ";
}
cout << endl;
// Free memory
cudaFree(dev_A);
cudaFree(dev_B);
cudaFree(dev_C);
cudaFreeHost(A);
cudaFreeHost(B);
cudaFreeHost(C);
return 0;


In this program, the `addVectors` kernel takes in the two input vectors `A` and `B`, the output vector `C`, and
the size of the vectors `n`. The kernel uses the `blockIdx.x` and `threadIdx.x` variables to calculate the index `i`
of the current thread. If the index is less than `n`, the kernel performs the addition operation `C[i] = A[i] +
B[i]`.
1. In the `main` function, the program first allocates memory for the input and output vectors on the host and
initializes them. Then it allocates memory for the vectors on the device and copies the data from the host to the
device using `cudaMemcpy`
