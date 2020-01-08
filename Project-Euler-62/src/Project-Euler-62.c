/*
 ============================================================================
 Name        : Project-Euler-62.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define LIMIT 100000



int isPermutationOfeachother(long long   number1, long long  number2) {

	int numArray1[25] = { 0 };
	int numArray2[25] = { 0 };
	int i;

	while (number1) {
		numArray1[number1 % 10]++;
		number1 /= 10;
	}
	while (number2) {
		numArray2[number2 % 10]++;
		number2 /= 10;
	}

	for (i = 0; i < 25; i++) {

		if (numArray1[i] != numArray2[i]) {
			return 0;
		}
	}

	return 1;
}



int getDigitsCount(long long number) { //number=0 return count=0

	int count = 0;
	while (number) {
		number /= 10;
		count++;
	}

	return count;
}
int main(void) {

	//get array of 1000 perfect cubes

	long long   arrayOfCube[LIMIT];
    long long  i,j,count,found;

	for(i=1;i<=LIMIT;i++){
		arrayOfCube[i-1]=i*i*i;
	}

/*	for(i=0;i<LIMIT;i++){
		printf("%lld\n",arrayOfCube[i]);
	}*/

	for (i = 0; i < LIMIT; i++) {

		count = 0;
		found = 0;
		for (j = i; getDigitsCount(arrayOfCube[i])==getDigitsCount(arrayOfCube[j]) && j < LIMIT  ; j++) {

			if (isPermutationOfeachother(arrayOfCube[i], arrayOfCube[j])) {
				count++;

			}
		}

		if (count == 5) {
			break;
		}

	}

	printf("%lld",arrayOfCube[i]);
	return EXIT_SUCCESS;
}

