#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "functions.h"

int main(int argc, char *argv[]) 
{
    // Seed the random number generator
    srand(time(0));

    // Check if the number of arguments passed in the command line is valid. Print message if there are under 6 arguments or over 7
    if (argc < 6 || argc > 7) {
        printf("Usage: %s nrows_A ncols_A nrows_B ncols_B <operation> [print]\n", argv[0]);
        return 1;
    }
    
    // Initialize variables for matrix dimensions
    long rowsA;
    long colsA;
    long rowsB;
    long colsB;
    char *p;

    // Retrieve the command line arguments for dimensions of the first Matrix
    rowsA = strtol(argv[1], &p, 10);
    colsA = strtol(argv[2], &p, 10);

    // Retrieve the command line arguments for dimensions of the second Matrix
    rowsB = strtol(argv[3], &p, 10);
    colsB = strtol(argv[4], &p, 10);

    // Check for invalid row/column input from the user
    if (rowsA == 0 || rowsB == 0 || colsA == 0 || colsB == 0) 
    {
        // Print error message to console
        printf("Invalid row/column input. Please make sure to enter a positive integer as row/column number.\n");
        return 1;
    }

    // Initialize the size of the two matrices using the values passed in the command line
    double matrixOne[rowsA][colsA];
    double matrixTwo[rowsB][colsB];

    // Generate the Matrices with random values between -10 and 10 inclusive
    generateMatrix(rowsA, colsA, matrixOne);
    generateMatrix(rowsB, colsB, matrixTwo);

    // Print Matrices to console if user inputs the "print" agrument in terminal
    if(argc > 6 && strcmp(argv[6], "print") == 0)
    {
        // Print the first matrix to console
        printf("Matrix A: \n");
        printMatrix(rowsA, colsA, matrixOne);
        // Print the second matrix to console
        printf("Matrix B: \n");
        printMatrix(rowsB, colsB, matrixTwo);
    }

    // Check if fifth argument is "add" and perform matrix operation for addition
    if (strcmp(argv[5], "add") == 0 && rowsA == rowsB && colsA == colsB) 
    {
        // Declare the size of the result matrix to be populated 
        double resultMatrix[rowsA][colsA];

        // Call the "addMatrices" function to perform the addition of the two matrices
        addMatrices(rowsA, colsA, matrixOne, rowsB, colsB, matrixTwo, resultMatrix);
        
        // Check if the user inputted the argument "print" and print the result matrix to the console
        if (argc > 6 && strcmp(argv[6], "print") == 0) 
        {
            printf("Result of A + B: \n");
            printMatrix(rowsA, colsA, resultMatrix);
        }
             
    }

    // Check if fifth argument is "subtract" and perform matrix operation for subtraction
    else if (strcmp(argv[5], "subtract") == 0 && rowsA == rowsB && colsA == colsB) 
    {
        // Declare the size of the result matrix to be populated 
        double resultMatrix[rowsA][colsA];

        // Call the "subtractMatrices" function to perform the subtraction of the two matrices
        subtractMatrices(rowsA, colsA, matrixOne, rowsB, colsB, matrixTwo, resultMatrix);
        
        // Check if the user inputted the argument "print" and print the result matrix to the console
        if (argc > 6 && strcmp(argv[6], "print") == 0) 
        {
            printf("Result of A - B: \n");
            printMatrix(rowsA, colsA, resultMatrix);
        }
    }

    // Check if fifth argument is "multiply" and perform matrix operation for multiplication
    else if (strcmp(argv[5], "multiply") == 0 && colsA == rowsB) 
    {
        // Declare the size of the result matrix to be populated 
        double resultMatrix[rowsA][colsB];

        // Call the "multiplyMatrices" function to perform the multiplication of the two matrices
        multiplyMatrices(rowsA, colsA, matrixOne, rowsB, colsB, matrixTwo, resultMatrix);

        // Check if the user inputted the argument "print" and print the result matrix to the console
        if (argc > 6 && strcmp(argv[6], "print") == 0) 
        {
            printf("Result of A * B: \n");
            printMatrix(rowsA, colsB, resultMatrix);
        }
        
    }

    // Check if fifth argument is "solve" and perform operations to solve system of linear equations
    else if (strcmp(argv[5], "solve") == 0 && rowsA == rowsB && colsB == 1 && rowsA == colsA)
    {
        // Declare the size of the solution vector x to be populated 
        double resultMatrix[rowsA][1];

        //  Call the "solveLinearSystem" function to solve the system of linear equations
        solveLinearSystem(rowsA, colsA, matrixOne, rowsB, colsB, matrixTwo, resultMatrix);

        // Check if the user inputted the argument "print" and print the result vector to the console
        if (argc > 6 && strcmp(argv[6], "print") == 0) 
        {
            printf("Result of x=B/A: \n");
            printMatrix(rowsA, 1, resultMatrix);
        }
    }

    // Invalid operation
    else 
    {
        // Print error message
        printf("Invalid operation. Please make sure matrix sizes are compatible for add, subtract, multiply, or solving linear systems.\n");
    }

    return 0;
}