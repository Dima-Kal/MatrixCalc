/*
 ============================================================================
 Name        : mat.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mat.h"


CMDS cmd[] = {
			{"read_mat"},
			{"print_mat"},
			{"add_mat"},
			{"sub_mat"},
			{"mul_mat"},
			{"mul_scalar"},
			{"trans_mat"},
			{"not_valid"}
	};


int main(void) {
	char command[MAX_COMMAND_LENGTH];
	char input[MAX_INPUT];
	char *inptr; /*pointer to input stream */
	double values[SIZE*SIZE]; /* total amount of values the matrix can hold */
	matrix *matPt1,*matPt2,*matPt3; /* pointers to matrixes */

	int i;
	int j;

	while(1){
		fgets(input,MAX_INPUT,stdin);
		for (j = 0; input[j] != '\0' ; j++){
			if ((input[j] == ',') && (input[j+1] == ',')){ /* locate wrong format input of parameters */
				fprintf(stderr,"wrong parameters input format\n");
				break;
			}
		}
		inptr = strtok(input," \n"); /*get only the command string */
		for (i = 0; *inptr!='\0' ; i++,inptr++){
			command[i] = *inptr; /* temporary command string */
		}
		command[i] = '\0';
			if (strcmp(command,"stop")==0)
				break;
			for (i=0 ; (strcmp(cmd[i].name, "not_valid") != 0) ; i++)
				if(strcmp(command,cmd[i].name) == 0) /* find the command in the commands list */
					break;

			if(strcmp(cmd[i].name, "not_valid") == 0)
				fprintf(stderr,"command does not exist:%s\n",command);

			switch (i) {
			case READ_MAT:
				memset(values, 0, sizeof(double)*(SIZE*SIZE)); /* turn the array into 0's */

				inptr = strtok(NULL,","); /* get the name of the matrix from input */
				find_mat(inptr,&matPt1); /* find it from the list and point to it */

				inptr = strtok(NULL,",\n");
				for ( i = 0 ; inptr != NULL ; i++ ){


					values[i] = strtod(inptr,NULL); /* convert number from string to double */
					inptr = strtok(NULL,",\n"); /* next word */
				}

				read_mat(*matPt1, values);

				break;
			case PRINT_MAT:
				inptr = strtok(NULL,",\n");

				find_mat(inptr,&matPt1);
				print_mat(*matPt1);

				break;
			case ADD_MAT:
				inptr = strtok(NULL,",\n");

				find_mat(inptr,&matPt1);
				inptr = strtok(NULL,",\n");
				find_mat(inptr,&matPt2);
				inptr = strtok(NULL,",\n");
				find_mat(inptr,&matPt3);
				add_mat(*matPt1,*matPt2,*matPt3);

				break;
			case SUB_MAT:

				inptr = strtok(NULL,",\n");
				find_mat(inptr,&matPt1);
				inptr = strtok(NULL,",\n");
				find_mat(inptr,&matPt2);
				inptr = strtok(NULL,",\n");
				find_mat(inptr,&matPt3);

				sub_mat(*matPt1,*matPt2,*matPt3);


				break;

			case MUL_MAT:
				inptr = strtok(NULL,",\n");
				find_mat(inptr,&matPt1);
				inptr = strtok(NULL,",\n");
				find_mat(inptr,&matPt2);
				inptr = strtok(NULL,",\n");
				find_mat(inptr,&matPt3);
				mul_mat(*matPt1,*matPt2,*matPt3);
				break;

			case MUL_SCALAR:
				inptr = strtok(NULL,",\n");
				find_mat(inptr,&matPt1);
				inptr = strtok(NULL,",\n");
				values[0] = strtod(inptr,NULL);
				inptr = strtok(NULL,",\n");
				find_mat(inptr,&matPt2);
				mul_scalar(*matPt1,values[0],*matPt2);

				break;
			case TRANS_MAT:
				inptr = strtok(NULL,",\n");
				find_mat(inptr,&matPt1);

				inptr = strtok(NULL,",\n");
				find_mat(inptr,&matPt2);

				trans_mat(*matPt1,*matPt2);
				break;

			}


	}

	return 0;

}




