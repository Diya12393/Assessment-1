#include <stdio.h>
#define MAX_SIZE 10  // Maximum allowed size for the square matrices
void inputMatrix(int size, int matrix[size][size]) {
    printf("Enter %dx%d matrix :\n", size, size);
    int i,j;
    for(i=0; i<size; i++) {
        printf("Row %d: ", i + 1);
        for(j=0; j<size; j++) {
            scanf("%d", &matrix[i][j]);  // Read each element of the matrix
        }
    }
}
void multiplyMatrices(int size, int matrix1[size][size], int matrix2[size][size], int result[size][size]) {
    int i,j,k;
    for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {
            result[i][j] = 0;  // Initialize result element to 0
            // Calculate dot product of row i from matrix1 and column j from matrix2
            for(k=0; k<size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}
void displayMatrix(int size, int matrix[size][size]) {
    printf("[\n");
    int i,j;
    for(i=0; i<size; i++) {
        printf("  [ ");
        for(j=0; j<size; j++) {
            printf("%d", matrix[i][j]);  // Print each element
            if (j < size - 1) printf(", ");  // Add comma separator except for last element
        }
        printf(" ]\n");  // End of row
    }
    printf("]\n");  // End of matrix
}

int main() {
    int size;  // Variable to store the size of matrices
    
    printf("Enter the size of square matrices : ");
    scanf("%d", &size);
    
    // Validate the input size
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid matrix size! Please enter a value between 1 and %d.\n", MAX_SIZE);
        return 1;  // Exit with error code
    }
    
    // Declare three matrices: two for input, one for result
    int matrix1[size][size];
    int matrix2[size][size];
    int result[size][size];
    
    // Input first matrix
    printf("\nEnter first matrix:\n");
    inputMatrix(size, matrix1);
    
    // Input second matrix
    printf("\nEnter second matrix:\n");
    inputMatrix(size, matrix2);
    
    // Multiply the two matrices
    multiplyMatrices(size, matrix1, matrix2, result);
    
    // Display all matrices
    printf("\nMatrix 1:\n");
    displayMatrix(size, matrix1);
    
    printf("\nMatrix 2:\n");
    displayMatrix(size, matrix2);
    
    printf("\nResult of matrix multiplication:\n");
    displayMatrix(size, result);
    
    return 0;  // Successful program termination
}
