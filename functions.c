#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function that generates a matrix of given size with random values between -10 and 10 inclusive
void generateMatrix(int rows, int cols, double matrix[rows][cols])
{
    // Declare and initialize the values representing the range of the random numbers
    int min = -10;
    int max = 10;

    // Iterate through double for loop to populate the matrix with random values ranging from -10 to 10
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            // Generate a random value between -10 and 10 to be placed in the matrix
            matrix[i][j] = min + ((double)rand() / RAND_MAX) * (max - min);
        }
    }
}

// Function to print the matrix
void printMatrix(int rows, int cols, double matrix[rows][cols])
{
    // Loop through each element of the matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // Adjust spacing to maintain alignment when printing negative numbers
            if (matrix[i][j] >= 0)
            {
                printf(" %f ", matrix[i][j]);
            }

            else
            {
                printf("%f ", matrix[i][j]);
            }
        }
        // Move to the next row after printing all elements in a row
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int N1, int M1, double A[N1][M1], int N2, int M2, double B[N2][M2], double result[N1][M1])
{
    // Check if the matrices are of equal size
    if (N1 != N2 || M1 != M2)
    {
        // Error message
        printf("Incompatible matrix sizes.\n");
    }

    else
    {
        // Loop through the matrix and add corresponding entry values together
        for (int i = 0; i < N1; i++)
        {
            for (int j = 0; j < M1; j++)
            {
                result[i][j] = A[i][j] + B[i][j];
            }
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int N1, int M1, double A[N1][M1], int N2, int M2, double B[N2][M2], double result[N1][M1])
{
    // Check if the matrices are of the same dimensions
    if (N1 != N2 || M1 != M2)
    {
        // Error message
        printf("Incompatible matrix sizes.\n");
    }

    else
    {
        // Loop through each matrix and subtract the values from the corresponding entries
        for (int i = 0; i < N1; i++)
        {
            for (int j = 0; j < M1; j++)
            {
                result[i][j] = A[i][j] - B[i][j];
            }
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int N1, int M1, double A[N1][M1], int N2, int M2, double B[N2][M2], double result[N1][M2])
{
    // Check if the matrix sizes are compatible
    if (M1 != N2)
    {
        // Error message
        printf("Incompatible matrix sizes.\n");
    }

    else
    {
        // Loop through the rows of first matrix and columns of second matrix
        for (int i = 0; i < N1; i++)
        {
            for (int j = 0; j < M2; j++)
            {
                // Multiply every entry in the row of matrix one with the entry in the column of matrix two
                // and add them all together. Then add the result to the final matrix.
                double entry = 0;
                for (int k = 0; k < M1; k++)
                {
                    entry += A[i][k] * B[k][j];
                }
                result[i][j] = entry;
            }
        }
    }
}

// Function to solve a linear system of equations Ax = B
void solveLinearSystem(int N1, int M1, double A[N1][M1], int N2, int M2, double B[N2][M2], double x[N1][M2])
{
    // Check if the size of the matrices are compatible
    if (N1 == M1 && N1 == N2 && M2 == 1)
    {
        // Iterate through each row of matrix A
        for (int i = 0; i < N1; i++)
        {
            // Check if each pivot is valid
            if (A[i][i] == 0)
            {
                printf("Division by zero encountered: No Solution.");
                break;
            }

            // Divide each entry in the row by the pivot value
            // Adjust the corresponding value in matrix B accordingly
            float pivotValue = A[i][i];
            B[i][0] /= pivotValue;
            for (int j = 0; j < M1; j++)
            {
                A[i][j] /= pivotValue;
            }

            // Perform row operations to eliminate entries above and below each pivot
            for (int j = 0; j < N1; j++)
            {
                // Skip the current row
                if (j == i)
                {
                    continue;
                }

                // The elimination factor is the matrix entry directly above or below the pivot
                float eliminationFactor = A[j][i];

                // Multiply the i-th row by the eliminationFactor and then subtract each row.
                for (int k = 0; k < M1; k++)
                {
                    A[j][k] -= A[i][k] * eliminationFactor;
                }
                B[j][0] -= B[i][0] * eliminationFactor;
            }
        }

        // Transfer solved matrix values from matrix B over to the solution matrix.
        for (int i = 0; i < N2; i++)
        {
            x[i][0] = B[i][0];
        }
    }

    // Error message for incompatible matrix
    else
    {
        printf("Invalid matrices. The input must be a square matrix and a vector.\n");
    }
}