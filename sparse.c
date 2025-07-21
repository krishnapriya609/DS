#include <stdio.h>

#define MAX_SIZE 100  // Maximum number of non-zero elements

// Function to input a sparse matrix
void inputSparseMatrix(int matrix[], int row[], int col[], int *numElements, int rows, int cols) {
    int r, c, val;
    *numElements = 0;
    printf("Enter non-zero elements (row, column, value):\n");
    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++) {
            printf("Enter value for element (%d, %d): ", r, c);
            scanf("%d", &val);
            if (val != 0) {
                matrix[*numElements] = val;
                row[*numElements] = r;
                col[*numElements] = c;
                (*numElements)++;
            }
        }
    }
}

// Function to add two sparse matrices
void addSparseMatrices(int matrix1[], int row1[], int col1[], int num1, 
                       int matrix2[], int row2[], int col2[], int num2, 
                       int result[], int rowResult[], int colResult[], int *numResult) {
    int i = 0, j = 0;
    *numResult = 0;

    // Merge the elements of the two matrices
    while (i < num1 && j < num2) {
        if (row1[i] < row2[j] || 
            (row1[i] == row2[j] && col1[i] < col2[j])) {
            result[*numResult] = matrix1[i];
            rowResult[*numResult] = row1[i];
            colResult[*numResult] = col1[i];
            i++;
        } else if (row1[i] > row2[j] || 
                   (row1[i] == row2[j] && col1[i] > col2[j])) {
            result[*numResult] = matrix2[j];
            rowResult[*numResult] = row2[j];
            colResult[*numResult] = col2[j];
            j++;
        } else {
            // Same position in both matrices, add the values
            result[*numResult] = matrix1[i] + matrix2[j];
            rowResult[*numResult] = row1[i];
            colResult[*numResult] = col1[i];
            i++;
            j++;
        }
        (*numResult)++;
    }

    // Copy remaining elements from matrix1 if any
    while (i < num1) {
        result[*numResult] = matrix1[i];
        rowResult[*numResult] = row1[i];
        colResult[*numResult] = col1[i];
        i++;
        (*numResult)++;
    }

    // Copy remaining elements from matrix2 if any
    while (j < num2) {
        result[*numResult] = matrix2[j];
        rowResult[*numResult] = row2[j];
        colResult[*numResult] = col2[j];
        j++;
        (*numResult)++;
    }
}

// Function to print a sparse matrix
void printSparseMatrix(int result[], int rowResult[], int colResult[], int numElements) {
    if (numElements == 0) {
        printf("No non-zero elements in the matrix.\n");
    } else {
        printf("Row   Column   Value\n");
        for (int i = 0; i < numElements; i++) {
            printf("%d     %d        %d\n", rowResult[i], colResult[i], result[i]);
        }
    }
}

int main() {
    int rows, cols;
    int matrix1[MAX_SIZE], matrix2[MAX_SIZE], result[MAX_SIZE];
    int row1[MAX_SIZE], col1[MAX_SIZE], row2[MAX_SIZE], col2[MAX_SIZE], rowResult[MAX_SIZE], colResult[MAX_SIZE];
    int num1, num2, numResult;

    // Input the matrix dimensions
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Input two sparse matrices
    printf("Enter elements for first sparse matrix:\n");
    inputSparseMatrix(matrix1, row1, col1, &num1, rows, cols);

    printf("Enter elements for second sparse matrix:\n");
    inputSparseMatrix(matrix2, row2, col2, &num2, rows, cols);

    // Add the matrices
    addSparseMatrices(matrix1, row1, col1, num1, matrix2, row2, col2, num2, result, rowResult, colResult, &numResult);

    // Output the result
    printf("\nResult of Sparse Matrix Addition:\n");
    printSparseMatrix(result, rowResult, colResult, numResult);

    return 0;
}

