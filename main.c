#include "matrice.h"

int main(void)
{
	Matrix *ma = build_matrix(5, 5, 0);
	set_value_in_matrix(ma, 0, 0, 5);
	set_value_in_matrix(ma, 0, 1, 28);
	set_value_in_matrix(ma, 0, 2, 7);
	set_value_in_matrix(ma, 0, 3, 8);
	set_value_in_matrix(ma, 0, 4, 9);
	set_value_in_matrix(ma, 1, 0, 4);
	set_value_in_matrix(ma, 1, 1, 5);
	set_value_in_matrix(ma, 1, 2, 6);
	set_value_in_matrix(ma, 1, 3, 15);
	set_value_in_matrix(ma, 1, 4, 8);
	set_value_in_matrix(ma, 2, 0, 3);
	set_value_in_matrix(ma, 2, 1, 4);
	set_value_in_matrix(ma, 2, 2, 10);
	set_value_in_matrix(ma, 2, 3, 6);
	set_value_in_matrix(ma, 2, 4, 7);
	set_value_in_matrix(ma, 3, 0, 2);
	set_value_in_matrix(ma, 3, 1, 3);
	set_value_in_matrix(ma, 3, 2, 4);
	set_value_in_matrix(ma, 3, 3, 5);
	set_value_in_matrix(ma, 3, 4, 6);
	set_value_in_matrix(ma, 4, 0, 1);
	set_value_in_matrix(ma, 4, 1, 2);
	set_value_in_matrix(ma, 4, 2, 3);
	set_value_in_matrix(ma, 4, 3, 4);
	set_value_in_matrix(ma, 4, 4, 5);
	
	Matrix *ca = build_matrix(2, 2, 0);
	set_value_in_matrix(ca, 0, 0, 3);
	set_value_in_matrix(ca, 0, 1, 4);
	set_value_in_matrix(ca, 1, 0, 2);
	set_value_in_matrix(ca, 1, 1, 1);

	Matrix *da = copy_matrix(ca);

	print_matrix(div_matrix_with_matrix(ca, ca));


	/*
	Matrix *ba = build_matrix(3, 3, 0);
	set_value_in_matrix(ba, 0, 0, 9);
	set_value_in_matrix(ba, 0, 1, 8);
	set_value_in_matrix(ba, 0, 2, 7);
	set_value_in_matrix(ba, 1, 0, 6);
	set_value_in_matrix(ba, 1, 1, 10);
	set_value_in_matrix(ba, 1, 2, 4);
	set_value_in_matrix(ba, 2, 0, 3);
	set_value_in_matrix(ba, 2, 1, 2);
	set_value_in_matrix(ba, 2, 2, 1);
	*/
}