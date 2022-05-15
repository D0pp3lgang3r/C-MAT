/**
 * @file matrice.h
 * @brief Declare functions and macro for matrices
 * @author D0pp3lgang3r
 * @version 1.0
 * @date 09/05/2022
 * */

#ifndef __MATRICE_H
#define __MATRICE_H
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

/**
 * @struct Matrix
 * 
 * @brief Basically declare a virtual matrix
 * 
 * @var Matrix::rows
 * 
 * Member rows contains number of lines in your matrix
 * 
 * @var Matrix::cols
 * 
 * Member cols contains number of columns in your matrix
 * */
struct Matrix {
    int rows;
    int cols;
    double** matrix;
};

typedef struct Matrix Matrix;

/**
 * @brief Function to initialize matrix dynamically
 * 
 * @param rows
 * Specify the number of rows for the matrix
 * 
 * @param cols
 * Specify the number of columns for the matrix
 * 
 * @param default_value
 * Specify a default value, for coefficients in matrix
 * 
 * @return 
 * Dynamically created matrix pointor structure 
 * */
Matrix *build_matrix(int rows, int cols, double default_value);

/**
 * @brief Use to destroy matrix inside of the memory
 * 
 * @param matrix
 * Pointor to matrix
 * 
 * @return void
 * */
void free_matrix(Matrix *matrix);

/**
 * @brief Get the value at a (row, col) position in the matrix
 * 
 * @param matrix
 * Pointor to matrix
 *   
 * @param row
 * Specify the row, where you want to get the value
 * 
 * @param col
 * Specify the column, where you want to get the value
 * 
 * @return
 * The value, at the (row, col) position
 * */
double get_value_in_matrix(Matrix *matrix, int row, int col);

/**
 * @brief Set the value at a (row, col) position in the matrix
 * 
 * @param matrix
 * Pointor to matrix
 * 
 * @param row
 * Specify the row, where you want to get the value
 * 
 * @param col
 * Specify the column, where you want to get the value
 * 
 * @param value
 * Specify the value, you want to put at the (row, col) position
 * 
 * @return void
 * */
void set_value_in_matrix(Matrix *matrix, int row, int col, double value);

/**
 * @brief Print the content of the matrix
 * 
 * @param matrix
 * Pointor to matrix
 * 
 * @return void
 * */
void print_matrix(Matrix* matrix);

/**
 * @brief Function created to print, more precisely the content of inversed matrix
 *
 * @param matrix
 * Pointor to matrix
 * 
 * @return void
 * */
void print_inverse(Matrix *matrix);

/**
 * @brief Copy the content of a matrix, into a new one
 * 
 * @param matrix
 * Pointor to matrix
 * 
 * @return
 * Give back a new matrix, with the content of the one in parameter
 * */

Matrix *copy_matrix(Matrix *matrix);

/**
 * @brief rotate the elements of the matrix to the right
 * 
 * @param matrix
 * Pointor to matrix
 * 
 * @return 
 * right rotated matrix
 * */
Matrix *rotate_right(Matrix *matrix);

/**
 * @brief rotate the elements of the matrix to the left
 * 
 * @param matrix
 * Pointor to matrix
 * 
 * @return 
 * left rotated matrix
 * */
Matrix *rotate_left(Matrix *matrix);

/**
 * @brief reverse the elements of the matrix
 * 
 * @param matrix
 * Pointor to matrix
 * 
 * @return 
 * half rotated matrix
 * */
Matrix *rotate_half(Matrix *matrix);

/**
 * @brief function to get the comatrix from the minors
 * 
 * @note WARNING if we don't get the minors matrix, will not give you the correct comatrix.
 * 
 * @param matrix
 * Pointor to matrix
 * 
 * @return
 * Comatrix, of the original minors matrix given in parameter
 * */
Matrix *get_comatrix(Matrix *matrix);

/**
 * @brief Get the determinant of matrix
 * 
 * @param matrix
 * Pointor to matrix
 * 
 * @return
 * Determinant of the matrix, given in parameter
 * */
double get_determinant(Matrix *matrix);

/**
 * @brief Get the trace of matrix
 * 
 * @param matrix
 * Pointor to matrix
 * 
 * @return
 * Trace of the matrix, given in parameter
 * */
double get_trace(Matrix *matrix);

/**
 * @brief Get the number of minors (sub matrix), inside the matrix
 * 
 * @param matrix
 * Pointor to a matrix
 * 
 * @return
 * Number of minors
 * */
int get_number_of_minor(Matrix *matrix);

/**
 * @brief Get a minor of the matrix, at a certain position
 * 
 * @param row
 * Specify the row.
 * 
 * @param col
 * Specify the col.
 * 
 * @return
 * Pointor to a new sub matrix
 * */
Matrix  *get_minor(Matrix *matrix, int row, int col);

/**
 * @brief Get all the minors in a matrix, and put them inside a matrix tab
 * 
 * @param matrix
 * Pointor to matrix, where you want to get the minors
 * 
 * @return
 * Matrix table with all the minors inside of it.
 * */
Matrix **get_minors(Matrix *matrix);

/**
 * @brief Get the transposition of the matrix in parameter
 * 
 * @param matrix
 * Pointor to matrix
 * 
 * @return
 * Return the transposed matrix
 * */
Matrix *get_transpose(Matrix *matrix);

/**
 * @brief function used in get_inverse() && print_inverse(), use to set up the inverse matrix.
 * 
 * @note see content to understand better.
 * 
 * @param matrix
 * Pointor to matrix
 * 
 * @return
 * The transposed comatrix of minors.
 * */
static Matrix *set_reversible(Matrix *matrix);

/**
 * @brief Get the inverse of a matrix
 * 
 * @param matrix
 * Pointor to matrix
 * 
 * @retrun
 * Inversed matrix
 * */
Matrix *get_inverse(Matrix *matrix);

/**
 * @brief Multiple a matrix with another one
 * 
 * @param matrix1
 * Pointor to matrix
 * 
 * @param matrix2
 * Pointor to matrix
 * 
 * @return
 * A new matrix created from the two others
 * */
Matrix *multiple_matrix_with_matrix(Matrix *matrix1, Matrix *matrix2);

/**
 * @brief Multiple each coefficient of the matrix with the specified number (coef)
 * 
 * @param matrix
 * Pointor to matrix
 * 
 * @param coef
 * Specify the number to use to multiply each coefficient of the matrix
 * 
 * @return
 * transformed matrix gave in parameters
 * */
Matrix *multiple_matrix_with_coefficient(Matrix *matrix, double coef);

/**
 * @brief Just add matrix with another one
 * 
 * @note matrix can only be added together if they have the same amount of rows and columns
 * 
 * @param matrix1
 * Pointor to matrix
 * 
 * @param matrix2
 * Pointor to matrix
 * 
 * @return
 * New matrix created from matrix1 + matrix2, with same rows and columns
 * */
Matrix *add_matrix_with_matrix(Matrix *matrix1, Matrix *matrix2);

/**
 * @brief Add each coefficient of the matrix with the specified number (coef)
 * 
 * @param matrix
 * Pointor to matrix
 * 
 * @param coef
 * Specify the number to use to add each coefficient of the matrix
 * 
 * @return
 * transformed matrix gave in parameters
 * */
Matrix *add_matrix_with_coefficient(Matrix *matrix, double coef);

/**
 * @brief Just substract matrix with another one
 * 
 * @note matrix can only be substracted together if they have the same amount of rows and columns
 * 
 * @param matrix1
 * Pointor to matrix
 * 
 * @param matrix2
 * Pointor to matrix
 * 
 * @return
 * New matrix created from matrix1 - matrix2, with same rows and columns
 * */
Matrix *sub_matrix_with_matrix(Matrix *matrix1, Matrix* matrix);

/**
 * @brief Substract each coefficient of the matrix with the specified number (coef)
 * 
 * @param matrix
 * Pointor to matrix
 * 
 * @param coef
 * Specify the number to use to sub each coefficient of the matrix
 * 
 * @return
 * transformed matrix gave in parameters
 * */
Matrix *sub_matrix_with_coefficient(Matrix *matrix, double coef);
/**
 * @brief Divise a matrix with another one, using the multiplication by inverse.
 * 
 * @param matrix1
 * Pointor to matrix
 * 
 * @param matrix2
 * Pointor to matrix
 * 
 * @return
 * New matrix pointor, created from the two others in parameters, by the multiplication by inverse.
 * */
Matrix *div_matrix_with_matrix(Matrix *matrix1, Matrix *matrix2);

/**
 * @brief Divide each coefficient of the matrix with the specified number (coef)
 * 
 * @param matrix
 * Pointor to matrix
 * 
 * @param coef
 * Specify the number to use to divise each coefficient of the matrix
 * 
 * @return
 * transformed matrix gave in parameters
 * */
Matrix *div_matrix_with_coefficient(Matrix *matrix, double coef);

#endif