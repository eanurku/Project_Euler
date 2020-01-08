/*
 ============================================================================
 Name        : Project-Euler-20.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000
int getDigitsCount(int number) { //number=0 return count=0

	int count = 0;
	while (number) {
		number /= 10;
		count++;
	}

	return count;
}
void copyArray(int *copyTarget, int *copyTargetSize, int *source,
		int *sourceSize) {
	int bigIndex, smallIndex;
	int startIndex = abs(*copyTargetSize - *sourceSize);
	for (bigIndex = startIndex, smallIndex = 0;
			bigIndex < *copyTargetSize && smallIndex < *sourceSize;
			smallIndex++, bigIndex++) {

		*(copyTarget + bigIndex) = *(source + smallIndex);

	}
}

int * getProduct(int *finalNumArray, int *finalNumArraySize, int multiplier) {
	int i, prodSum, digit;
	int carry = 0, digitCounts;

	int *tmpArray = (int *) malloc(sizeof(int) * SIZE);
	int tmpArraySize = *finalNumArraySize;

	copyArray(tmpArray, &tmpArraySize, finalNumArray, finalNumArraySize);

	for (i = tmpArraySize - 1; i >= 0; i--) {

		prodSum = *(tmpArray + i) * multiplier + carry;

		digit = prodSum % 10;
		carry = prodSum / 10;

		*(tmpArray + i) = digit;
	}

	if (carry) {
		digitCounts = getDigitsCount(carry);
		i = digitCounts - 1;
		while (carry) {

			*(finalNumArray + i--) = carry % 10;
			carry /= 10;
		}

		*finalNumArraySize += digitCounts;
		copyArray(finalNumArray, finalNumArraySize, tmpArray, &tmpArraySize);
	} else {
		copyArray(finalNumArray, finalNumArraySize, tmpArray, &tmpArraySize);
	}

}
int main(void) {
	int i,sum=0;
	int *numArray = (int *) malloc(sizeof(int) * SIZE);
	int numArraySize = 1;
	int array[] = { 1 };
	copyArray(numArray, &numArraySize, array, &numArraySize); //initialize numArray

	for (i = 1; i <= 100; i++) {
		getProduct(numArray, &numArraySize, i);
	}

	for (i = 0; i < numArraySize; i++) {
		sum+= *(numArray + i);
	}

	printf("%d",sum);
	return EXIT_SUCCESS;
}
