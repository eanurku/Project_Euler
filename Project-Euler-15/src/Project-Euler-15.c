/*
 ============================================================================
 Name        : Project-Euler-15.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description :
 Starting in the top left corner of a 22 grid, there are 6 routes (without backtracking) to the bottom right corner.
How many routes are there through a 2020 grid?

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

unsigned long long factorial(int number) {

	unsigned long long prod = 1;
	while (number) {
		prod *= number;
		number--;
	}
	return prod;
}
int main(void) {

	int row, col, i, j;
	scanf("%d%d", &row, &col);

	unsigned long long *array = (unsigned long long *) malloc(
			row * col * sizeof(unsigned long long));

	for (i = 0; i < col; i++) { //fill in first row
		*(array + i) = i + 2;

	}
	for (j = 0; j < row; j++) { //fill in first column
		*(array + j * col) = j + 2;
	}


	for (i = 1; i < row; i++) {
		for (j = 1; j < col; j++) {
			*(array + col * i + j) = *(array + col * i + j - 1)
					+ *(array + col * (i - 1) + j);

		}
	}


	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%lld ", *(array + col * i + j));
		}
		printf("\n");
	}

	return EXIT_SUCCESS;
}
