#include <stdio.h>
#include "matrice.h"

int main(void)
{
// Initialising matrix
	printf("{ + } Initializing...");
	Matrix *ma_1 = build_matrix(2, 2, 0);
	
	Matrix *ma_2 = build_matrix(2, 3, 0);

	Matrix *ma_3 = build_matrix(2, 2, 0);
	
// Set values

	set_value_in_matrix(ma_1, 0, 0, 3);
	set_value_in_matrix(ma_1, 0, 1, 4);
	set_value_in_matrix(ma_1, 1, 0, 2);
	set_value_in_matrix(ma_1, 1, 1, 1);

	set_value_in_matrix(ma_2, 0, 0, 9);
	set_value_in_matrix(ma_2, 0, 1, 8);
	set_value_in_matrix(ma_2, 0, 2, 7);
	set_value_in_matrix(ma_2, 1, 0, 6);
	set_value_in_matrix(ma_2, 1, 1, 10);
	set_value_in_matrix(ma_2, 1, 2, 4);

	set_value_in_matrix(ma_3, 0, 0, 5);
	set_value_in_matrix(ma_3, 0, 1, 4);
	set_value_in_matrix(ma_3, 1, 0, 6);
	set_value_in_matrix(ma_3, 1, 1, 7);

// Get value
	printf("Value pos : (%d, %d) : ", 0, 1);
	printf("%d\n", (int)get_value_in_matrix(ma_2, 0, 1)); // 8
	print_matrix(ma_2);
	printf("\n");
// Operations

	// Additions
		printf("{ + } Adding...\n");
		print_matrix(add_matrix_with_coefficient(ma_2, 4)); // add 4 to coefficients in matrix
		printf("\n");
		print_matrix(add_matrix_with_matrix(ma_1, ma_3)); // print result of the addition of the matrix
		printf("\n");

	// Substractions
		// To get back matrices before additions steps
		printf("{ + } Substracting...\n");
		print_matrix(sub_matrix_with_coefficient(ma_2, 4)); // sub 4 to coefficients in matrix
		printf("\n");
		print_matrix(sub_matrix_with_matrix(ma_1, ma_3)); // print result of the substraction of the matrix
		printf("\n");

	// Multiplications
		printf(" { + } Multiplying...\n");
		print_matrix(multiple_matrix_with_coefficient(ma_1, 4));
		printf("\n");
		print_matrix(multiple_matrix_with_matrix(ma_3, ma_2));
		printf("\n");

	// Division
		printf("{ + } Dividing...\n");
		print_matrix(div_matrix_with_coefficient(ma_1, 4));
		printf("\n");
		print_matrix(div_matrix_with_matrix(ma_1, ma_1)); // Get the IDENTITY Matrix.
		printf("\n");

// Rotations
		printf("{ + } Possible rotations...\n");
	// Rotate right
		printf("rotate right : \n");
		print_matrix(rotate_right(ma_2));
		printf("\n");
	// Rotate left
		printf("rotate left : \n");
		print_matrix(rotate_left(ma_2));
		printf("\n");
	// Rotate half
		printf("rotate half : \n");
		print_matrix(rotate_half(ma_2));
		printf("\n");
// Other
	// Get minors of a matrix
		printf("{ + } Getting minors... \n");
		Matrix *ma_4 = build_matrix(3, 3, 0);
		
		set_value_in_matrix(ma_4, 0, 0, 9);
		set_value_in_matrix(ma_4, 0, 1, 8);
		set_value_in_matrix(ma_4, 0, 2, 7);
		set_value_in_matrix(ma_4, 1, 0, 6);
		set_value_in_matrix(ma_4, 1, 1, 10);
		set_value_in_matrix(ma_4, 1, 2, 4);
		set_value_in_matrix(ma_4, 2, 0, 3);
		set_value_in_matrix(ma_4, 2, 1, 2);
		set_value_in_matrix(ma_4, 2, 2, 1);
		
		Matrix **minor_tab = get_minors(ma_4);
		
		for (int i=0;i<get_number_of_minor(ma_4);i++)
		{
			print_matrix(minor_tab[i]);
			printf("\n");
		}

	// Inverse of matrix:
		printf("{ + } Inversed matrix : \n");
		print_matrix(get_inverse(ma_4));
	// See the rest in features...
}