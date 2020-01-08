/*
 ============================================================================
 Name        : Project-Euler-99.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 10000000

//copyTargetSize >=so caseurceSize for valid
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

int main(void) {

	int *productArray=(int *)malloc(sizeof(int)*SIZE);
	int  productArraySize=0;

	getPowerForAnyBase( 6,4,productArray,&productArraySize);

	int i,lineNum,maxLineNum;
	long double max,product;
	char *num,*den;

	char *str=(char *)malloc(100);
	char *delim=",";

	FILE *input=fopen("/home/anurag/Desktop/CPROGG/PROJECT-EULER-linuxworkspace/Project-Euler-99/src/input.txt","r");

	lineNum=0;
	while(fgets(str,100,input)){

		lineNum++;
		num=strtok(str,delim);
		den=strtok(NULL,delim);
		product=atof(den)*(long double)log10(atof(num));
		if(max < product){
			max=product;
			maxLineNum=lineNum;
		}


	}

	printf("linenum=%d",maxLineNum);

	return EXIT_SUCCESS;
}
