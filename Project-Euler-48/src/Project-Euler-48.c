/*
 ============================================================================
 Name        : Project-Euler-47.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 3500



void copyArray(int *copyTarget, int *copyTargetSize, int *source,
		int *sourceSize) {
	int bigIndex,smallIndex;
	int startIndex = abs(*copyTargetSize - *sourceSize);
	for (bigIndex = startIndex, smallIndex = 0; bigIndex < *copyTargetSize && smallIndex < *sourceSize;
			smallIndex++, bigIndex++) {

		*(copyTarget + bigIndex) = *(source + smallIndex);

	}
}

int getDigitsCount(int number) { //number=0 return count=0

	int count = 0;
	while (number) {
		number /= 10;
		count++;
	}

	return count;
}

int * getProduct(int *finalNumArray, int *finalNumArraySize, int multiplier,int *tmpArray) {
	int i, prodSum, digit;
	int carry = 0, digitCounts;


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


void getPowerForAnyBase(int number, int power, int *productArray, int *productArraySize) {

	int i,j;
	int *tmpArray = (int *) malloc(sizeof(int) * SIZE);
	*(productArray + (*productArraySize)++) = 1;

	for (i = 1; i <= power; i++) {
		getProduct(productArray, productArraySize, number,tmpArray);

	}
}


int* getSumOfTwoBigNumbers(int *bigNumber, int bigNumberSize, int *smallNumber,int smalNumberSize,int *finalSum, int *finalSumSize) {

	if (bigNumberSize < smalNumberSize) {
		finalSum=getSumOfTwoBigNumbers(smallNumber, smalNumberSize, bigNumber,
				bigNumberSize,finalSum, finalSumSize);
		return finalSum;
	}


	int *tmp = (int *) malloc(sizeof(int) * SIZE);
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

    int *productArray=(int *)malloc(sizeof(int)*SIZE);
	int productArraySize=0;

	int *finalSum=(int *)calloc(SIZE,sizeof(int));
	int finalSumSize=1;

	int *totalSum=(int *)calloc(SIZE,sizeof(int));
	int totalSumSize=0;

	int i,number;

	for(number=1;number<=1000;number++){
		totalSumSize=0;
		productArraySize=0;
		getPowerForAnyBase(number,number,productArray,&productArraySize);

		getSumOfTwoBigNumbers(finalSum,finalSumSize,productArray,productArraySize,totalSum,&totalSumSize);

		finalSumSize=totalSumSize;
		copyArray(finalSum,&finalSumSize,totalSum,&totalSumSize);

	}


	for(i=finalSumSize-1-9;i<finalSumSize;i++){
				printf("%d",finalSum[i]);

			}
			printf("\n");





	return EXIT_SUCCESS;
}
