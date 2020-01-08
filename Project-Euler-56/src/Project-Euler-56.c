/*
 ============================================================================
 Name        : Project-Euler-56.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 205


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
	int bigIndex,smallIndex;
	int startIndex = abs(*copyTargetSize - *sourceSize);
	for (bigIndex = startIndex, smallIndex = 0; bigIndex < *copyTargetSize && smallIndex < *sourceSize;
			smallIndex++, bigIndex++) {

		*(copyTarget + bigIndex) = *(source + smallIndex);

	}
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

int getSumOfDigits(int *productArray,int productArraySize){

	int i,sum=0;

	for(i=0;i<productArraySize;i++){
       sum+=productArray[i];
	}

	return sum;
}

int isGoogool(int *productArray,int productArraySize){

	if(getSumOfDigits(productArray,productArraySize)==1){
		return 1;
	}

	return 0;
}
int main(void) {


int a,b,i;
int sum=0,maxSum;

int *productArray=(int *)malloc(sizeof(int)*SIZE);
int productArraySize;

	for(a=1;a<100;a++){
		for(b=1;b<100;b++){
			productArraySize=0;
			getPowerForAnyBase(a, b,productArray, &productArraySize);

/*			for(i=0;i<productArraySize;i++){
				printf("%d",productArray[i]);

			}
			printf("\n");*/

			if(maxSum<(sum=getSumOfDigits(productArray,productArraySize))){
				maxSum=sum;
			}


		}


	}

	printf("%d\n",maxSum);
	return EXIT_SUCCESS;
}
