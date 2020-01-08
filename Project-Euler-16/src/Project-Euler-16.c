/*
 ============================================================================
 Name        : Project-Euler-16.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description :
 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 What is the sum of the digits of the number 2^1000?
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000
//copy from right to left
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
void getMultiplication(int *firstNumberArray, int *firstNumberArraySize,
		int singleDigitNumber) {

	int i, carry = 0, digit, productSum;

	int *tmpArray = (int *) malloc(SIZE * sizeof(int));
	int tmpArraySize = *firstNumberArraySize;

	copyArray(tmpArray, firstNumberArraySize, firstNumberArray,
			firstNumberArraySize);

	for (i = tmpArraySize - 1; i >= 0; i--) {

		productSum = *(tmpArray + i) * singleDigitNumber + carry;

		digit = productSum % 10;
		*(tmpArray + i) = digit;
		carry = productSum / 10;

	}

	if (carry) {
		*(firstNumberArray) = carry;
		(*firstNumberArraySize)++;
		copyArray(firstNumberArray, firstNumberArraySize, tmpArray,
				&tmpArraySize);
	} else {
		copyArray(firstNumberArray, firstNumberArraySize, tmpArray,
				&tmpArraySize);
	}

}
void getPower(int number, int power, int *productArray, int *productArraySize) {

	int i;
	*(productArray + (*productArraySize)++) = 1;

	for (i = 1; i <= power; i++) {
		getMultiplication(productArray, productArraySize, number);
	}

}
int main(void) {

	int number, exponent, i;
	int *finalProduct = (int *) malloc(SIZE * sizeof(int));
	int finalProductSize = 0;
	int sum = 0;

	scanf("%d%d", &number, &exponent);

	getPower(number, exponent, finalProduct, &finalProductSize);

	for (i = 0; i < finalProductSize; i++)
		sum += *(finalProduct + i);

	printf("%d", sum);
	return EXIT_SUCCESS;
}
