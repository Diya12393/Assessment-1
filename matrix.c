#include <stdio.h>
#define MAX_SIZE 10
void inputMatrix(int size, int matrix[size][size]) {
    printf("Enter %dx%d matrix :\n", size, size);
    int i,j;
    for(i=0; i<size; i++) {
        printf("Row %d: ", i + 1);
        for(j=0; j<size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}


void multiplyMatrices(int size, int matrix1[size][size], int matrix2[size][size], int result[size][size]) {
    int i,j,k;
	for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {
            result[i][j] = 0;
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
            printf("%d", matrix[i][j]);
            if (j < size - 1) printf(", ");
        }
        printf(" ]\n");
    }
    printf("]\n");
}

int main() {
    int size;
    
    printf("Enter the size of square matrices : ");
    scanf("%d", &size);
    
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid matrix size! Please enter a value between 1 and %d.\n", MAX_SIZE);
        return 1;
    }
    
    int matrix1[size][size];
    int matrix2[size][size];
    int result[size][size];
    
    printf("\nEnter first matrix:\n");
    inputMatrix(size, matrix1);
    
    printf("\nEnter second matrix:\n");
    inputMatrix(size, matrix2);
    
    multiplyMatrices(size, matrix1, matrix2, result);
    

    printf("\nMatrix 1:\n");
    displayMatrix(size, matrix1);
    
    printf("\nMatrix 2:\n");
    displayMatrix(size, matrix2);
    
    printf("\nResult of matrix multiplication:\n");
    displayMatrix(size, result);
    
    return 0;
}
