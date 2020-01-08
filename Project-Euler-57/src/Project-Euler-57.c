/*
 ============================================================================
 Name        : Project-Euler-57.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

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


void getProduct(int *finalNumArray, int *finalNumArraySize, int multiplier,int *tmpArray) {
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


int* getSumOfTwoBigNumbers(int *bigNumber, int bigNumberSize, int *smallNumber,int smalNumberSize,int *finalSum, int *finalSumSize,int *tmp) {

	if (bigNumberSize < smalNumberSize) {
		getSumOfTwoBigNumbers(smallNumber, smalNumberSize, bigNumber,
				bigNumberSize,finalSum, finalSumSize,tmp);
	}



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


void getFinalFractionSum(int iteration,int *numeratorArray,int *numeratorArraySize,int *denominatorArray,int *denominatorArraySize,int *tmp,int *tmpSize,int *tmpcalc,
		int *tmpfinalSum,int *tmpfinalSumSize){

if(iteration==1){
	numeratorArray[(*numeratorArraySize)++]=1;
	denominatorArray[(*denominatorArraySize)++]=2;

return ;
}

getFinalFractionSum(iteration-1,numeratorArray,numeratorArraySize,denominatorArray,denominatorArraySize,tmp,tmpSize,tmpcalc,tmpfinalSum,tmpfinalSumSize);

//N1 *tmp=*numerator;
*tmpSize=*numeratorArraySize;
copyArray(tmp,numeratorArraySize,numeratorArray,numeratorArraySize);

//N2 *numerator=*denominator;
*numeratorArraySize=*denominatorArraySize;
copyArray(numeratorArray,numeratorArraySize,denominatorArray,denominatorArraySize);

//N2 *denominator=2*(*denominator)+(*tmp);
getProduct(denominatorArray,denominatorArraySize,2,tmpcalc);

getSumOfTwoBigNumbers(denominatorArray,*denominatorArraySize,tmp,*tmpSize,tmpfinalSum,tmpfinalSumSize,tmpcalc);

*denominatorArraySize=*tmpfinalSumSize;

copyArray(denominatorArray,denominatorArraySize,tmpfinalSum,tmpfinalSumSize);
*tmpfinalSumSize=0;



return;
}

int main(void) {

int iteration;
int *numeratorArray=(int *)malloc(sizeof(int)*10000);
int numeratorArraySize=0;

int *denominatorArray=(int *)malloc(sizeof(int)*10000);
int denominatorArraySize=0;

int *tmp=(int *)malloc(sizeof(int)*10000);
int tmpSize=0;

int *tmpCalc=(int *)malloc(sizeof(int)*10000);

int *finalSum=(int *)malloc(sizeof(int)*10000);
int finalSumSize=0;

int i,count=0;

	for(iteration=1;iteration<=1000;iteration++){
		numeratorArraySize=0;
		denominatorArraySize=0;
		finalSumSize=0;
		tmpSize=0;
		getFinalFractionSum(iteration,numeratorArray,&numeratorArraySize,denominatorArray,&denominatorArraySize,tmp,&tmpSize,tmpCalc,finalSum,&finalSumSize);


		//numerator=numerator+denominator;

		getSumOfTwoBigNumbers(denominatorArray,denominatorArraySize,numeratorArray,numeratorArraySize,finalSum,&finalSumSize,tmpCalc);
		numeratorArraySize=finalSumSize;
		copyArray(numeratorArray,&numeratorArraySize,finalSum,&finalSumSize);

		if(numeratorArraySize>denominatorArraySize){
			count++;


		/*for(i=0;i<numeratorArraySize;i++){
                printf("%d",numeratorArray[i]);
		}
		printf("---/---");

		for(i=0;i<denominatorArraySize;i++){
		         printf("%d",denominatorArray[i]);
		}
				printf("\n");*/
		}
	}

	printf("%d",count);
	return EXIT_SUCCESS;
}
