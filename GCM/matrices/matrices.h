/**
 * This file is part of a studying library.
 * As said it is not meant to be optimal or well-integrated with all the systems.
 *
 * If someone is deciding for a random reason to use it, and founds a problem.
 * Please open an issue.
 * 
 * Interesting sources for studying:
 * - Books:
 *  - The Theory Of Matrices By F.R. Gantmacher Volume One
 * - Sites:
 *  - https://www.mathsisfun.com/algebra/matrix-multiplying.html
 */

#ifndef GCM_MATRICES

#define GCM_MATRICES

#include <stdio.h>
#include <stdlib.h>

/*************************************************
 *                                               *
 *             STRUCT DEFINITIONS                *
 *                                               *
 *************************************************/

/**
 * Struct representing a Matrix.
 */
typedef struct {
    float **data;
    size_t rows;
    size_t cols;
} Matrix;

/*************************************************
 *                                               *
 *              MATRIX LIFECYCLE                 *
 *                                               *
 *************************************************/

/**
 * Function to allocate the memory for a Matrix.
 * 
 * Remember to free the allocated memory when the Matrix is no more used with the function `free_matrix(Matrix matrix)`.
 *
 * Params:
 * - rows: the number of rows of the wanted Matrix
 * - cols: the number of columns of the wanted Matrix
 *
 * Return:
 * A Matrix with the memory for `data` allocated.
 */
Matrix create_matrix(size_t rows, size_t cols) {
    Matrix matrix;
    
    matrix.rows = rows;
    matrix.cols = cols;
    
    matrix.data = malloc(rows * sizeof(float *));
    for (int i = 0; i < rows; i++) {
        matrix.data[i] = malloc(cols * sizeof(float));
    }

    return matrix;
}

/**
 * Function to free the allocated memory of a Matrix.
 *
 * Params:
 * - matrix: the Matrix that needs to free the allocated memory
 */
void free_matrix(Matrix matrix) {
    for (size_t i = 0; i < matrix.rows; i++) {
        free(matrix.data[i]);
    }
    free(matrix.data);
}

/*************************************************
 *                                               *
 *                OPERATIONS                     *
 *                                               *
 *************************************************/

/**
 * Function to add two matrices.
 *
 * Params:
 * - A: the first Matrix.
 * - B: the second Matrix.
 *
 * Return:
 * A Matrix representing the sum of the two passed matrices: A + B.
 */
Matrix matrix_addition(Matrix A, Matrix B) {
    if (A.rows != B.rows || A.cols != B.cols) {
        fprintf(stderr, "MismatchMatrixDimensionError: Matrix dimensions must match for addition. \n");
        fprintf(stderr, "A is %d%d, B is %d%d\n", A.rows, A.cols, B.rows, B.cols);
        exit(EXIT_FAILURE);
    }

    Matrix result = create_matrix(A.rows, A.cols);

    for (size_t i = 0; i < A.rows; i++) {
        for (size_t j = 0; j < A.cols; j++) {
            result.data[i][j] = A.data[i][j] + B.data[i][j];
        }
    }

    return result;
}

/**
 * Function to subtract two matrices.
 *
 * Params:
 * - A: the first Matrix.
 * - B: the second Matrix.
 *
 * Return:
 * A Matrix representing the subtraction of the two passed matrices: A - B.
 */
Matrix matrix_subtraction(Matrix A, Matrix B) {
    if (A.rows != B.rows || A.cols != B.cols) {
        fprintf(stderr, "MismatchMatrixDimensionError: Matrix dimensions must match for subtraction. \n");
        fprintf(stderr, "A is %d%d, B is %d%d\n", A.rows, A.cols, B.rows, B.cols);
        exit(EXIT_FAILURE);
    }

    Matrix result = create_matrix(A.rows, A.cols);

    for (size_t i = 0; i < A.rows; i++) {
        for (size_t j = 0; j < A.cols; j++) {
            result.data[i][j] = A.data[i][j] - B.data[i][j];
        }
    }

    return result;
}

/**
 * Function to scale (scalar multiplication) a Matrix.
 *
 * Params:
 * - matrix: the Matrix to scale.
 * - scalar: a single number used to scale the values in the matrix.
 *
 * Return:
 * A Matrix representing the passed Matrix scaled by the scalar: matrix * scalar.
 */
Matrix matrix_scalar_multiplication(Matrix matrix, double scalar) {
    Matrix result = create_matrix(matrix.rows, matrix.cols);

    for (size_t i = 0; i < matrix.rows; i++) {
        for (size_t j = 0; j < matrix.cols; j++) {
            result.data[i][j] = matrix.data[i][j] * scalar;
        }
    }
    

    return result;
}

/**
 * Function to do the dot product of two matrices.
 *
 * Params:
 * - A: the first Matrix.
 * - B: the second Matrix.
 * 
 * Note, following the rules of the dot product of two matrices with the first dimension being `m x n` and the second dimension being `n x p`:
 * - a.cols and b.rows should be the same number
 * - the resulting Matrix will have the dimension `m x p`
 *
 * Return:
 * A Matrix of dimensions `m x p`(A.rows, B.cols) with the result of the dot product: A x B.
 */
Matrix matrix_dot_product(Matrix A, Matrix B) {
    if(A.cols != B.rows) {
        fprintf(stderr, "MismatchMatrixDimensionError: When doing the dot product the number of columns of the first Matrix should match the number of rows of the second Matrix. \n");
        fprintf(stderr, "A columns number is %d, B rows number is %d\n", A.cols, B.rows);
        exit(EXIT_FAILURE);
    }

    Matrix result = create_matrix(A.rows, B.cols);

    for (size_t i = 0; i < result.rows; i++) {
        for (size_t j = 0; j < result.cols; j++) {
            result.data[i][j] = 0;

            for (size_t k = 0; k < A.cols; k++)
            {
                result.data[i][j] += A.data[i][k] * B.data[k][j] ;
            }
        }
    }

    return result;
}

/*************************************************
 *                                               *
 *              UTILITY FUNCTIONS                *
 *                                               *
 *************************************************/

/**
 * Matrix pretty printer.
 * 
 * Function that pretty print a given Matrix.
 * 
 * Param:
 * - matrix: the Matrix to pretty print
 * - decimals_numbers: the number of decimals to show
 */
void matrix_pretty_print(Matrix matrix, size_t decimals_number) {
    const char top_left = 218;      // ┌
    const char top_right = 191;     // ┐
    const char bottom_left = 192;   // └
    const char bottom_right = 217;  // ┘
    
    printf("%c", top_left);
    for (size_t t = 0; t < matrix.cols + 1; t++) {
        printf("\t");
    }
    printf("%c\n", top_right);

    for(size_t i = 0; i < matrix.rows; i++) {
        printf("|\t");
        for (size_t j = 0; j < matrix.cols; j++) {
            printf("%.*f\t", decimals_number, matrix.data[i][j]);
        }
        printf("|\n");
    }

    printf("%c", bottom_left);
    for (size_t t = 0; t < matrix.cols + 1; t++) {
        printf("\t");
    }
    printf("%c\n", bottom_right);
}

/*************************************************
 *                                               *
 *               INFO FUNCTIONS                  *
 *                                               *
 *************************************************/

/**
 * wit, short for "What Is That"
 * When the function is called, it prints in the terminal a small description about
 * the matrices.
 */
void wit() {
    printf("\n/*************************************************\n");
    printf(" *                                               *\n");
    printf(" *            WIT: What Is That?                 *\n");
    printf(" *                                               *\n");
    printf(" *************************************************/\n\n");

    printf("A matrix is a rectangular array of numbers or other mathematical objects. \n");
    printf("Those elements are arranged in rows and columns, without a constrain regarding the difference of length.\n");
    printf("E.g.: it can have 5 rows and 2 columns \n\n");
    printf("A matrix with the same number of rows and columns is called \"Square matrix\".\n\n");

    printf("E.g. of a matrix: \n");
    
    Matrix m = create_matrix(2, 3);

    m.data[0][0] = 1; m.data[0][1] = 2; m.data[0][2] = 3;
    m.data[1][0] = 6; m.data[1][1] = 5; m.data[1][2] = 4;

    matrix_pretty_print(m, 0);

    free_matrix(m);

    printf("\n");

    printf("For the purposes of the library it's important to note that the rows are expressed as 'm' while the columns as 'n'.\nSo a matrix with 'm' rows and 'n' columns is called an 'm x n' matrix(or m-by-n matrix), where 'm' and 'n' are called the dimensions.\n");
}

/*************************************************
 *                                               *
 *            SHORT FUNCTION NAMES               *
 *                                               *
 *************************************************/
#ifdef GCM_SHORT_FN

// Struct definitions

#define M Matrix

// Matrix lifecycle

#define cm create_matrix
#define mcreate create_matrix

#define fm free_matrix
#define mfree free_matrix

// Operations

#define ma matrix_addition
#define madd matrix_addition

#define ms matrix_subtraction
#define msub matrix_subtraction

#define msm matrix_scalar_multiplication
#define mscale matrix_scalar_multiplication
#define mscalmult matrix_scalar_multiplication
#define matrix_scale matrix_scalar_multiplication

#define mdp matrix_dot_product
#define mprod matrix_dot_product
#define mdotprod matrix_dot_product

// Utility functions

#define mpprint matrix_pretty_print

// Info functions

/**
 * The function wit it is already short, so it doesn't need a shorter version.
 * If it should get the full what_is_that(), please leave a feedback in the issue section.
 */

#endif // GCM_SHORT_FN

#endif // GCM_MATRICES

/**
 * MIT License
 *
 * Copyright (c) 2025 Matteo
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */