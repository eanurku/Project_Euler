/*
 ============================================================================
 Name        : Project-Euler-25.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define DIGITS_SUPPORTED 10000
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

int* getSumOfTwoBigNumbers(int *bigNumber, int bigNumberSize, int *smallNumber,int smalNumberSize,int *finalSum, int *finalSumSize) {

	if (bigNumberSize < smalNumberSize) {
		getSumOfTwoBigNumbers(smallNumber, smalNumberSize, bigNumber,
				bigNumberSize,finalSum, finalSumSize);
	}


	int *tmp = (int *) malloc(sizeof(int) * DIGITS_SUPPORTED);
	int smalNumberIndex, bigNumberIndex;

	int carry = 0;
	int tmpSum;

	for (smalNumberIndex = smalNumberSize - 1, bigNumberIndex = bigNumberSize
			- 1; smalNumberIndex >= 0 && bigNumberIndex >= 0;
			bigNumberIndex--, smalNumberIndex--) {

		tmpSum = *(bigNumber + bigNumberIndex)
				+ *(smallNumber + smalNumberIndex) + carry;

		*(finalSum + bigNumberIndex) = tmpSum % 10;
		carry = tmpSum / 10;
	}

	while (bigNumberIndex >= 0) {

		tmpSum = *(bigNumber + bigNumberIndex) + carry;
		*(finalSum + bigNumberIndex) = tmpSum % 10;
		carry = tmpSum / 10;
		bigNumberIndex--;
	}

	if (carry) {
		*finalSumSize = bigNumberSize + 1;
		copyArray(tmp, finalSumSize, finalSum, &bigNumberSize);
		*tmp = carry;
		copyArray(finalSum,finalSumSize,tmp,finalSumSize);

	} else {
		*finalSumSize = bigNumberSize;
	}

	return finalSum;
}
int main(void) {

	int i;

	int *fibo1 = (int *) malloc(sizeof(int) * DIGITS_SUPPORTED);
	int *fibo2 = (int *) malloc(sizeof(int) * DIGITS_SUPPORTED);
	int *fibo3 = (int *) malloc(sizeof(int) * DIGITS_SUPPORTED);

	int fibo1Size = 1;
	int fibo2Size = 1;
	int fibo3Size;

	*fibo1 = 1;
	*fibo2 = 1;

     int count=2;

	while (1) {

		fibo3 = getSumOfTwoBigNumbers(fibo2, fibo2Size, fibo1, fibo1Size,fibo3,&fibo3Size);
		count++;

		//copyArray(fibo1,&fibo2Size,fibo2,&fibo2Size);//assign 2 to 1
		//copyArray(fibo2,&fibo3Size,fibo3,&fibo3Size);//assign 3 to 2


		fibo1=fibo2;
		fibo2=fibo3;

		fibo1Size=fibo2Size;
		fibo2Size=fibo3Size;


		if (fibo3Size==1000) {
			break;
		}

	}
			printf("count=%d", count);

	return EXIT_SUCCESS;
}
