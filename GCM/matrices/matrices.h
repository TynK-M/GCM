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

/**
 * wit, short for "What Is That"
 * When the function is called, it prints in the terminal a small description about
 * the matrices.
 */
void wit(){
    printf("A matrix is a rectangular array of numbers or other mathematical objects. \n");
    printf("Those elements are arranged in rows and columns, without a constrain regarding the difference of length. \n");
    printf("E.g.: it can have 5 rows and 2 columns \n");
    printf("A matrix with the same number of rows and columns is called \"Square matrix\".\n");
    printf("E.g. of a matrix: \n");
    printf("%c         %c\n", 218, 191);
    printf("| 1  2  3 |\n");
    printf("| 6  5  4 |\n");
    printf("%c         %c\n", 192, 217);

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