/*
 ============================================================================
 Name        : Project-Euler-12.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define CROSSED 1

long long getTriangleNumber(long long number) {

	return (number * (number + 1)) / 2;
}
void generatePrimesUptoGivenNumberFast(int *primeArray, int *primeArraySize,int maxLimit) {

	int indexArraySize, index, nextIndex,i;
	int *indexArray,lastIndex;

	indexArraySize = maxLimit / 2;
	indexArray = (int *) malloc(indexArraySize * 4);

	lastIndex = sqrt(maxLimit) / 2;
	for (index = 1; index <= lastIndex; index++) {
		if (indexArray[index] != CROSSED)
			for (nextIndex = 2*index*(index + 1);nextIndex<indexArraySize; nextIndex+=2*index+1) {
				indexArray[nextIndex]=CROSSED;
			}
	}

	primeArray[(*primeArraySize)++]=2;//add 2 as first prime

	for(i=1;i<indexArraySize;i++){
		if(indexArray[i]!=CROSSED){
			primeArray[(*primeArraySize)++]=2*i+1;
		}

	}

}

int getDivisorsCountBasic(long long trinagleNumber) {

	int divisorsCount=0,i;

	for(i=1;i<=trinagleNumber;i++){
		if(trinagleNumber%i==0){
			divisorsCount++;
		}
	}

	return divisorsCount;
}
int getDivisorsCount(long long number,int *primeSeq,int *primeSeqSize) {

	int divisorsCount=1,i,exponent;

	for(i=0;primeSeq[i]<=number && i<*primeSeqSize ;i++){
		exponent=0;
		while(number%primeSeq[i]==0){
			exponent++;
			number/=primeSeq[i];
		}
		divisorsCount*=(exponent+1);
	}

	return divisorsCount;
}

int main(void) {

	int number, divisorsCount, maxDivisorsCount;
	long long trinagleNumber;

	int *primeSeq=(int *)malloc(100000*4);
	int primeSeqSize=0;
	generatePrimesUptoGivenNumberFast(primeSeq,&primeSeqSize,100000);

	scanf("%d",&maxDivisorsCount);
	number = 1;
	while (1) {

		trinagleNumber = getTriangleNumber(number);
		if(number%2==0){
			divisorsCount = getDivisorsCount(number/2,primeSeq,&primeSeqSize)*getDivisorsCount(number+1,primeSeq,&primeSeqSize);
		}else{
			divisorsCount = getDivisorsCount(number,primeSeq,&primeSeqSize)*getDivisorsCount((number+1)/2,primeSeq,&primeSeqSize);
		}


		if (divisorsCount >= maxDivisorsCount) {

			break;
		}

		number++;
	}

	printf("triangle number=%d,number=%d", trinagleNumber,number);
	return EXIT_SUCCESS;
}
