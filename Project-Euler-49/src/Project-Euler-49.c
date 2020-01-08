/*
 ============================================================================
 Name        : Project-Euler-49.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define  CROSSED 1
#define SIZE 10000
void generatePrimesUptoGivenNumberFast(int *primeArray, int *primeArraySize,
		int maxLimit) {

	int indexArraySize, index, nextIndex, i;
	int *indexArray, lastIndex;

	indexArraySize = maxLimit / 2;
	indexArray = (int *) malloc(indexArraySize * 4);

	lastIndex = sqrt(maxLimit) / 2;
	for (index = 1; index <= lastIndex; index++) {
		if (indexArray[index] != CROSSED)
			for (nextIndex = 2 * index * (index + 1);
					nextIndex < indexArraySize; nextIndex += 2 * index + 1) {
				indexArray[nextIndex] = CROSSED;
			}
	}

	primeArray[(*primeArraySize)++] = 2; //add 2 as first prime

	for (i = 1; i < indexArraySize; i++) {
		if (indexArray[i] != CROSSED) {
			primeArray[(*primeArraySize)++] = 2 * i + 1;
		}

	}

}

int isPermutationOfeachother(int number1, int number2) {

	int numArray1[10] = { 0 };
	int numArray2[10] = { 0 };
	int i;

	while (number1) {
		numArray1[number1 % 10]++;
		number1 /= 10;
	}
	while (number2) {
		numArray2[number2 % 10]++;
		number2 /= 10;
	}

	for (i = 0; i < 10; i++) {

		if (numArray1[i] != numArray2[i]) {
			return 0;
		}
	}

	return 1;
}
int main(void) {

	int *primeArray = (int *) malloc(sizeof(int) * SIZE);
	int primeArraySize = 0;
	int maxLimit = 10000, primeStartindexIn4digit, i, j, k;

	generatePrimesUptoGivenNumberFast(primeArray, &primeArraySize, maxLimit);

	for (i = 0; i < primeArraySize; i++) {
		if (primeArray[i] > 999) {
			primeStartindexIn4digit = i;
			break;
		}

	}

	int found = 0;
	for (i = primeStartindexIn4digit; i < primeArraySize; i++) {
		for (j = i + 1; j < primeArraySize; j++) {
			for (k = j + 1; k < primeArraySize; k++) {
				if ((primeArray[j] - primeArray[i]
						== primeArray[k] - primeArray[j])
						&& isPermutationOfeachother(primeArray[j],
								primeArray[i])
						&& isPermutationOfeachother(primeArray[j],
								primeArray[k])) {

					printf("%d,%d,%d\n", primeArray[i],primeArray[j],primeArray[k]);

/*					found = 1;
					break;*/
				}

			}
			/*if (found) {
				break;
			}*/
		}
	/*	if (found) {
			break;
		}*/

	}

	//printf("%d",primeStartindexIn4digit);
	//printf("%d",isPermutationOfeachother(1887,1817));

	return EXIT_SUCCESS;
}
