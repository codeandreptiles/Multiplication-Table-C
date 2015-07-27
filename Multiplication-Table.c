/**
A simple times table program that generates a formatted table of size n x n, where n is a two digit number inputed by the user
This is mainly meant as practice in pointer arithmetic and formatting strings in C.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void generate_table(int n, int * list);
int * generate_int_list(int n);

int main (int argc, char * argv[]) {
	if (argc < 2) {
		   fprintf(stderr, "Usage: %s multiplier\n", argv[0]);
		   exit(EXIT_FAILURE);
	   }
	int num = strtol(argv[1], NULL, 0);
	
	if (!num) {
		perror("Number Generator");
	} else {
		int * list = generate_int_list(num);
		generate_table(num, list);
	}
	
}

void generate_table(int n, int * list) {	//Draws the table
	int i;
	int j;
	for (i = 1; i < n + 1; i ++) {
		for (j = 1; j < n + 1; j ++) {
			printf("%d\t", (*(list + j) * *(list + i)));
		}
		printf("\n");
	}
}

int * generate_int_list (int n) {	//Generates a list of ints from 1 to n
	int * list = malloc(sizeof(int) * n);
	int i;
	for (i = 1; i < n + 1; i ++) {
		*(list + i) = i;
	}
	return list;
}
