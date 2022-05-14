#include "matrice.h"

Matrix *build_matrix(int rows, int cols, double default_value)
{
	struct Matrix* matrix = malloc(sizeof(Matrix));
	matrix->cols = cols;
	matrix->rows = rows;
	if (!(matrix->matrix = malloc(sizeof(double*) * matrix->rows)))
	{
		fprintf(stderr, " [!] Can't build matrix...");
		exit(EXIT_FAILURE);
	}
	for (int i=0; i<matrix->rows; i++)
	{
		if (!(matrix->matrix[i] = malloc(sizeof(double) * matrix->cols)))
		{
			fprintf(stderr, " [!] Can't build matrix...");
			exit(EXIT_FAILURE);
		}
	}

	if (default_value != 0)
	{
		for (int i=0;i<matrix->rows;i++)
		{
			for (int j=0;j<matrix->cols;j++)
				matrix->matrix[i][j] = default_value;
		}
	}
	return matrix;
}

Matrix *copy_matrix(Matrix *matrix)
{
	Matrix *copy = build_matrix(matrix->rows, matrix->cols, 0);
	for (int i=0;i<matrix->rows;i++)
	{
		for (int j=0;j<matrix->cols;j++)
		{
			copy->matrix[i][j] = matrix->matrix[i][j];
		}
	}
	return copy;
}

double get_value_in_matrix(Matrix *matrix, int row, int col)
{
	if (row <= matrix->rows && col <= matrix->cols-1) // Because we initialise a matrix at zero.
		return matrix->matrix[row][col];
	return 1;
}

void set_value_in_matrix(Matrix *matrix, int row, int col, double value)
{
	if (row <= matrix->rows-1 && col <= matrix->cols-1) // Because we initialise a matrix at zero.
		matrix->matrix[row][col] = value;
}

void print_matrix(Matrix* matrix)
{
	for(int x = 0; x < matrix->rows; x++) 
	{	
		printf("|");
		for(int y = 0; y < matrix->cols; y++) 
		{
			printf(" %.2f ", matrix->matrix[x][y]);
		}
		printf("|\n");
	}
}

Matrix *rotate_left(Matrix *matrix)
{
	return rotate_right(rotate_right(rotate_right(matrix)));
}

Matrix *rotate_right(Matrix *matrix)
{
	int val;
	int l_length = matrix->rows-1;
	Matrix *ma = build_matrix(matrix->cols, matrix->rows, 0);
	for (int i=0;i<matrix->rows;i++)
	{
		for (int j=0;j<matrix->cols;j++)
			ma->matrix[j][l_length - i] = matrix->matrix[i][j];
	}
	return ma;
}

Matrix *rotate_half(Matrix *matrix)
{
	return rotate_right(rotate_right(matrix));
}

Matrix *get_transpose(Matrix *matrix)
{
	Matrix *new_matrix = build_matrix(matrix->cols, matrix->rows, 0);
	for (int i=0;i<matrix->rows;i++)
	{
		for (int j=0;j<matrix->cols;j++)
			new_matrix->matrix[j][i] = matrix->matrix[i][j];
	}
	return new_matrix;
}

Matrix **get_minors(Matrix *matrix)
{
	if (matrix->rows != matrix->cols)
	{
		fprintf(stderr, "[!] Can't get minors, for non square matrix...");
		exit(EXIT_FAILURE);
	}
	Matrix *minor;
	int index=0;
	Matrix **minors_tab = malloc(sizeof(Matrix*) * matrix->rows * matrix->cols);
	for (int i=0;i<matrix->rows;i++)
	{
		for (int j=0;j<matrix->cols;j++)
		{
			minor = get_minor(matrix, i, j);
			minors_tab[index] = minor;
			index++;
		}
	}
	return minors_tab;
}

Matrix *get_minor(Matrix *matrix, int row, int col)
{
	Matrix *minor = build_matrix(matrix->rows-1, matrix->cols-1, 0);
	int minor_row, minor_col;
	for (int i = 0; i < matrix->rows; i++) {
		minor_row = i;
		if (i>row)
			minor_row--;
		for (int j = 0; j < matrix->cols; j++) {
			minor_col = j;
			if (j>col)
				minor_col--;
			if (i != row && j != col)
				minor->matrix[minor_row][minor_col] = matrix->matrix[i][j];
		}
	}
	return minor;
}

int get_number_of_minor(Matrix *matrix)
{
	return matrix->rows * matrix->cols;
}

double get_trace(Matrix *matrix)
{
	int trace=0;
	if (matrix->rows == matrix->cols)
	{
		for (int i=0;i<matrix->rows;i++)
			trace += matrix->matrix[i][i];
	}
	else
	{
		fprintf(stderr, "[!] Can't get the trace, not a square matrix...");
		exit(EXIT_FAILURE);
	}
	return trace;
}

Matrix *get_comatrix(Matrix *matrix)
{
	int switcher_add, switcher_sub;
	Matrix *new_matrix = build_matrix(matrix->rows, matrix->cols, 0);
	for (int i=0;i<matrix->rows;i++)
	{
		switcher_add = 1;
		switcher_sub = 1;
		for (int j=0;j<matrix->cols;j++)
		{
			if (i % 2 == 0)
			{
				if (switcher_add)
				{
					new_matrix->matrix[i][j] = matrix->matrix[i][j];
					switcher_add = 0;
				}
				else
				{
					new_matrix->matrix[i][j] = -matrix->matrix[i][j];
					switcher_add = 1;
				}
			}
			else
			{
				if (switcher_sub)
				{
					new_matrix->matrix[i][j] = -matrix->matrix[i][j];
					switcher_sub = 0;
				}
				else
				{
					new_matrix->matrix[i][j] = matrix->matrix[i][j];
					switcher_sub = 1;
				}
			}
		}
	}
	return new_matrix;
}

double get_determinant(Matrix *matrix)
{
	double result = 0;
	Matrix *comatrix = get_comatrix(matrix);
	if (matrix->rows != matrix->cols)
	{
		fprintf(stderr, " [!] Can't get determinant, when it's not square matrix...");
		exit(EXIT_FAILURE);
	}
	if (matrix->rows == 2 && matrix->cols == 2)
	{
		return matrix->matrix[0][0] * matrix->matrix[1][1] - matrix->matrix[1][0] * matrix->matrix[0][1];
	}
	else
	{
		Matrix *tmp_matrix;
		for (int i=0;i<comatrix->rows;i++)
		{
			tmp_matrix = get_minor(comatrix, 0, i);
			result += (matrix->matrix[0][i] * get_determinant(tmp_matrix)); // get determinant recursively !
		}
	}
	return result;
}

Matrix *multiple_matrix_with_coefficient(Matrix *matrix, double coef)
{
	for (int i=0;i<matrix->rows;i++)
	{
		for (int j=0;j<matrix->cols;j++)
			matrix->matrix[i][j] *= coef;
	}
	return matrix;
}

Matrix *add_matrix_with_coefficient(Matrix *matrix, double coef)
{
	for (int i=0;i<matrix->rows;i++)
	{
		for (int j=0;j<matrix->cols;j++)
			matrix->matrix[i][j] += coef;
	}
	return matrix;
}

Matrix *sub_matrix_with_coefficient(Matrix *matrix, double coef)
{
	for (int i=0;i<matrix->rows;i++)
	{
		for (int j=0;j<matrix->cols;j++)
			matrix->matrix[i][j] -= coef;
	}
	return matrix;
}

Matrix *div_matrix_with_coefficient(Matrix *matrix, double coef)
{
	for (int i=0;i<matrix->rows;i++)
	{
		for (int j=0;j<matrix->cols;j++)
			matrix->matrix[i][j] = ((int) matrix->matrix[i][j] / coef);
	}
	return matrix;
}

Matrix *add_matrix_with_matrix(Matrix *matrix1, Matrix *matrix2)
{
	if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols)
	{
		fprintf(stderr, "Can't add, matrices with different length");
		exit(EXIT_FAILURE);
	}

	for (int i=0;i<matrix1->rows;i++)
	{
		for (int j=0;j<matrix1->cols;j++)
			matrix1->matrix[i][j] += matrix2->matrix[i][j];
	}
	return matrix1;
}

Matrix *sub_matrix_with_matrix(Matrix *matrix1, Matrix *matrix2)
{
	if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols)
	{
		fprintf(stderr, "Can't sub, matrices with different length");
		exit(EXIT_FAILURE);
	}

	for (int i=0;i<matrix1->rows;i++)
	{
		for (int j=0;j<matrix1->cols;j++)
			matrix1->matrix[i][j] -= matrix2->matrix[i][j];
	}
	return matrix1;
}

Matrix *multiple_matrix_with_matrix(Matrix *matrix1, Matrix *matrix2)
{
	if (matrix1->cols != matrix2->rows)
	{
		fprintf(stderr, "Can't multiply matrix, nothing in commun");
		exit(EXIT_FAILURE);
	}
	Matrix *product = build_matrix(matrix1->rows, matrix2->cols, 0);
	for (int i=0;i<matrix1->rows;i++)
	{
		for (int j=0;j<matrix2->cols;j++)
		{
			for (int k=0;k<matrix1->cols;k++)
			{
				product->matrix[i][j] += (matrix1->matrix[i][k] * matrix2->matrix[k][j]);
			}
		}
	}
	return product;
}

Matrix *div_matrix_with_matrix(Matrix *matrix1, Matrix *matrix2)
{
	return multiple_matrix_with_matrix(matrix1, get_inverse(matrix2));
}
static Matrix *set_reversible(Matrix *matrix)
{
	if (matrix->rows != matrix->cols)
	{
		fprintf(stderr, "Can't get the inverse, if not square matrix");
		exit(EXIT_FAILURE);
	}
	double det = get_determinant(matrix);
	if (det == 0)
	{
		fprintf(stderr, "This matrix is not reversible...");
		exit(EXIT_FAILURE);
	}
	if (matrix->rows == 2)
	{
		Matrix *inversible_matrix = build_matrix(matrix->rows, matrix->cols, 0);
		inversible_matrix->matrix[0][0] = matrix->matrix[1][1];
		inversible_matrix->matrix[0][1] = -matrix->matrix[0][1];
		inversible_matrix->matrix[1][0] = -matrix->matrix[1][0];
		inversible_matrix->matrix[1][1] = matrix->matrix[0][0];
		return inversible_matrix;
	}
	int minor_index = 0;
	Matrix **minors_tab = get_minors(matrix);
	Matrix *minor_matrix = build_matrix(matrix->rows, matrix->cols, 0);
	for (int i=0;i<minor_matrix->rows;i++)
	{
		for (int j=0;j<minor_matrix->cols;j++)
		{
			minor_matrix->matrix[i][j] = get_determinant(minors_tab[minor_index]);
			minor_index++;
		}
	}
	Matrix *com_minor_matrix = get_comatrix(minor_matrix);
	Matrix *transposed_minors_comatrix = get_transpose(com_minor_matrix);
	return transposed_minors_comatrix;
}
void print_inverse(Matrix *matrix)
{
	int det = get_determinant(matrix);
	Matrix *rev_matrix = set_reversible(matrix);
	for (int i=0;i<rev_matrix->rows;i++)
	{
		printf("|");
		for (int j=0;j<rev_matrix->cols;j++)
		{
			printf(" %d/%d ", (int)rev_matrix->matrix[i][j], det);
		}
		printf("|\n");
	}
}
Matrix *get_inverse(Matrix *matrix)
{
	double det = get_determinant(matrix);
	double front_coef = 1/det;
	Matrix *transposed_minors_comatrix = set_reversible(matrix);
	return multiple_matrix_with_coefficient(transposed_minors_comatrix, front_coef);
}