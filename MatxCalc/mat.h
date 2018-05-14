#ifndef MAT_H
#define MAT_H

/* defining menu numbers */
#define READ_MAT 0
#define PRINT_MAT 1
#define ADD_MAT 2
#define SUB_MAT 3
#define MUL_MAT 4
#define MUL_SCALAR 5
#define TRANS_MAT 6

#define SIZE 4 /* size of matrix */
#define MAX_COMMAND_LENGTH 10
#define MAX_INPUT 100
typedef double matrix[SIZE][SIZE]; /* defining a matrix type */
matrix MAT_A,MAT_B,MAT_C,MAT_D,MAT_E,MAT_F;

/* structure of matrix name and its adress */
typedef struct {
	char *name;
	matrix *mat;
}MATS;

/* structure of command name */
typedef struct {
	char *name;
}CMDS;

void read_mat (matrix mat,double *values);
/*The method receives a matrix, and an array of values. the method copies the values to the matrix */
void add_mat (matrix first_mat,matrix second_mat,matrix result_mat);
/*The method receives 3 matrix's, adds the first one to the second and saves the result in the third matrix */
void sub_mat (matrix first_mat,matrix second_mat,matrix result_mat);
/*The method receives 3 matrix's, does a substraction between the first and the second, and saves the result in the third matrix */
void mul_mat (matrix first_mat,matrix second_mat,matrix result_mat);
/*The method receives 3 matrix's, multiplies the first by the second, and saves the result in the third matrix */
void mul_scalar (matrix mat,double value,matrix result_mat);
/*The method receives 2 matrix's, does a scalar multiplication on the first matrix and saves the result in the second matrix */
void trans_mat (matrix mat,matrix result_mat);
/*The method receives a matrix's, does a transformation to the first matrix, and saves the result in the second matrix */
void print_mat (matrix mat);
/*The method receives a matrix and prints its value */
void find_mat (const char* input_name, matrix **mat);
/*The receives method a string of a matrix name, and a temporary pointer to find and point to an existing matrix from the matrix's array */

#endif




