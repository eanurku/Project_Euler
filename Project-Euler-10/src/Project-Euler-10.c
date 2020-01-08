/*
 ============================================================================
 Name        : Project-Euler-10.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define CROSSED 1
#define LIMIT   2000000 //Limit excluded
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
void generatePrimesUptoGivenNumber(int *primeArray, int *primeArraySize,int maxLimit) {

	int  crosserIndex, lastCrosserIndex, nextCrosserIndex, i;

	short *array=(short *)malloc(maxLimit*2);

	for (crosserIndex = 4; crosserIndex < maxLimit; crosserIndex += 2) {
		array[crosserIndex] = CROSSED;
	}

	lastCrosserIndex = sqrt(maxLimit-1)+1;

	for (crosserIndex = 3; crosserIndex <= lastCrosserIndex; crosserIndex += 2) {
		if (array[crosserIndex] != CROSSED) {

			for (nextCrosserIndex = crosserIndex * crosserIndex;
					nextCrosserIndex < maxLimit; nextCrosserIndex += (2 * crosserIndex)) {
				array[nextCrosserIndex] = CROSSED;
			}
		}

	}

	for (i = 2; i < maxLimit; i++) {
		if (array[i] != CROSSED) {

			primeArray[(*primeArraySize)] = i;
			*primeArraySize+=1;
		}
	}

}

int prime_check_with_primeArray(int number, int *primeNumberSequence, int sequenceSize) {

	int i;
	for (i = 0; primeNumberSequence[i] <= sqrt(number); i++) {
		if (number % primeNumberSequence[i] == 0) {

			return 0;
		}
	}

	return 1;
}
void  generatePrimeNumbersBasic(int *primeNumberSequence,int *sequenceSize,int maxLimit){

	int number;
    primeNumberSequence[0] = 2;
	primeNumberSequence[1] = 3;
	*sequenceSize = 2;
	for (number = 5; number < maxLimit; number += 6) {

		if (prime_check_with_primeArray(number, primeNumberSequence, *sequenceSize)) {
			primeNumberSequence[(*sequenceSize)++] = number;
		}

		if ((number + 2) < maxLimit
				&& prime_check_with_primeArray(number + 2, primeNumberSequence, *sequenceSize)) {
			primeNumberSequence[(*sequenceSize)++] = number + 2;
		}
	}


}
int main(void) {

	int *primeNumberSequence=(int *)malloc(1000000*4);
	int maxLimit, sequenceSize=0, i; //remember to change if changed implementation
     long long sumOfPrimes=0;

     scanf("%d", &maxLimit);

//implementation 1
/*

     generatePrimeNumbersBasic(primeNumberSequence,&sequenceSize,maxLimit);


	for (i = 0; i < sequenceSize; i++) {
		sumOfPrimes+=primeNumberSequence[i];
	}
	printf("sum=%lld",sumOfPrimes);
*/

//implementation 2
/*generatePrimesUptoGivenNumber(primeNumberSequence,&sequenceSize,maxLimit);

for(i=0;i<sequenceSize;i++){
	sumOfPrimes+=primeNumberSequence[i];
}
printf("sum=%lld",sumOfPrimes);*/

//implementation 3
/*

     generatePrimesUptoGivenNumberFast(primeNumberSequence,&sequenceSize,maxLimit);

     for(i=0;i<sequenceSize;i++){
     	sumOfPrimes+=primeNumberSequence[i];
     }
     printf("sum=%lld",sumOfPrimes);
*/

	return EXIT_SUCCESS;
}
