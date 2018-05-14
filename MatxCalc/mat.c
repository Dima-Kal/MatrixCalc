/*
 ============================================================================
 Name        : mat.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Simple Matrix calculator
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mat.h"

MATS mats[]={
		{"MAT_A",&MAT_A},
		{"MAT_B",&MAT_B},
		{"MAT_C",&MAT_C},
		{"MAT_D",&MAT_D},
		{"MAT_E",&MAT_E},
		{"MAT_F",&MAT_F},
		{"#",NULL}


};


void read_mat (matrix mat,double *values){
	/*The method receives a matrix, and an array of values. the method copies the values to the matrix */

	int i,j;

	for (i = 0 ; i < SIZE ; i++){
		for (j = 0 ; j < SIZE ; j++,values++){
			mat[i][j]=*values;

		}
	}

}

void add_mat (matrix first_mat,matrix second_mat,matrix result_mat){
	/*The method receives 3 matrix's, adds the first one to the second and saves the result in the third matrix */

	int i,j;

	for (i = 0 ; i < SIZE ; i++){
		for (j = 0 ; j < SIZE ; j++){

			result_mat[i][j] = first_mat[i][j] + second_mat[i][j];

		}
	}
}

void sub_mat (matrix first_mat,matrix second_mat,matrix result_mat){
	/*The method receives 3 matrix's, does a subtraction between the first and the second, and saves the result in the third matrix */

	int i,j;

	for (i = 0 ; i < SIZE ; i++){
		for (j = 0 ; j < SIZE ; j++){

			result_mat[i][j] = first_mat[i][j] - second_mat[i][j];

		}
	}
}



void mul_mat (matrix first_mat,matrix second_mat,matrix result_mat){
	/*The method receives 3 matrix's, multiplies the first by the second, and saves the result in the third matrix */

	int i,j;

	for (i = 0 ; i < SIZE ; i++){
		for (j = 0 ; j < SIZE ; j++){

			result_mat[i][j] = first_mat[i][j] * second_mat[i][j];

		}
	}

}

void mul_scalar (matrix mat,double value,matrix result_mat){
	/*The method receives 2 matrix's, does a scalar multiplication on the first matrix and saves the result in the second matrix */

	int i,j;

	for (i = 0 ; i < SIZE ; i++){
		for (j = 0 ; j < SIZE ; j++){

			result_mat[i][j] = mat[i][j] * value;

		}
	}

}

void trans_mat (matrix mat,matrix result_mat){
	/*The method receives a matrix's, does a transformation to the first matrix, and saves the result in the second matrix */

	int i,j;

	for (i = 0 ; i < SIZE ; i++){
		for (j = 0 ; j < SIZE ; j++){
			result_mat[j][i]=mat[i][j];

		}
	}

}



void print_mat (matrix mat){
	/*The method receives a matrix and prints its value */
	int i,j;

	for (i = 0 ; i < SIZE ; i++){
		printf("\n");
		for (j = 0 ; j < SIZE ; j++){
			printf("%g ",mat[i][j]);
		}

	}
	printf("\n");
}

void find_mat (const char* input_name, matrix **mat){
	/*The method receives a string of a matrix name, and a temporary pointer to find and point to an existing matrix from the matrix's array */

	int i;
	for (i = 0 ; mats[i].mat != NULL ; i++){
		if (strcmp(input_name,mats[i].name) == 0){
			*mat = mats[i].mat;
			return;
		}
	}
	fprintf(stderr,"matrix does not exist:%s\n",input_name);



}


