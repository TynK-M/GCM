/**
 * This file is part of a studying library.
 * As said it is not meant to be optimal or well-integrated with all the systems.
 *
 * If someone is deciding for a random reason to use it, and founds a problem.
 * Please open an issue.
 */

#ifndef GCM_MATRICES

#define GCM_MATRICES

#include <stdio.h>
#include <stdlib.h>

/**
 * Struct representing a Matrix.
 */
typedef struct {
    float **data;
    size_t rows;
    size_t cols;
} Matrix;

/**
 * wit, short for "What Is That"
 * When the function is called, it prints in the terminal a small description about
 * the matrices.
 */
void wit() {
    printf("A matrix is a rectangular array of numbers or other mathematical objects. \n");
    printf("Those elements are arranged in rows and columns, without a constrain regarding the difference of length.\n");
    printf("E.g.: it can have 5 rows and 2 columns \n");
    printf("A matrix with the same number of rows and columns is called \"Square matrix\".\n");
    printf("E.g. of a matrix: \n");
    printf("%c         %c\n", 218, 191);
    printf("| 1  2  3 |\n");
    printf("| 6  5  4 |\n");
    printf("%c         %c\n", 192, 217);
    printf("For the purposes of the library it's important to note that the rows are expressed as 'm' while the columns as 'n', so a matrix with m rows and n columns is called an m x n matrix(or m-by-n matrix), where m and n are called the dimensions.\n");
}

/**
 * Matrix pretty printer.
 * 
 * Function that pretty print a given Matrix.
 * 
 * Param:
 * - matrix: the Matrix to pretty print
 */
void mpprint(Matrix matrix, size_t decimals_number) {
    const char top_left = 218;   // ┌
    const char top_right = 191;  // ┐
    const char bottom_left = 192; // └
    const char bottom_right = 217; // ┘
    
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

/**
 * Function to allocate the memory for a matrix.
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
 * Function to add two matrices.
 *
 * Params:
 * - a: the first Matrix.
 * - b: the second Matrix.
 *
 * Return:
 * A Matrix representing the sum of the two passed matrices.
 */
Matrix madd(Matrix a, Matrix b) {
    if (a.rows != b.rows || a.cols != b.cols) {
        fprintf(stderr, "MismatchMatrixDimensionError: Matrix dimensions must match for addition. \n");
        fprintf(stderr, "a is %d%d, B is %d%d\n", a.rows, a.cols, b.rows, b.cols);
        exit(EXIT_FAILURE);
    }

    Matrix result = create_matrix(a.rows, a.cols);

    for (size_t i = 0; i < a.rows; i++) {
        for (size_t j = 0; j < a.cols; j++) {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }

    return result;
}

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