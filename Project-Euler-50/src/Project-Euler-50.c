/*
 ============================================================================
 Name        : Project-Euler-50.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define  CROSSED 1
#define SIZE 1000000
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

int prime_check_with_primeArray(int number, int *primeNumberSequence, int sequenceSize) {

	int i;
	if(number<2){
		return 0;
	}
	for (i = 0; primeNumberSequence[i] <= sqrt(number); i++) {
		if (number % primeNumberSequence[i] == 0) {

			return 0;
		}
	}

	return 1;
}
int main(void) {


	    int *primeArray = (int *) malloc(sizeof(int) * SIZE);
		int primeArraySize = 0;
		int maxLimit = 1000000,i,sum=0,j,maxSeqSize=0,maxSum,seqSize;

		generatePrimesUptoGivenNumberFast(primeArray, &primeArraySize, maxLimit);



		for(i=0;i<primeArraySize;i++){
            sum=0;
			for(j=i;j<primeArraySize && sum <1000000;j++){

				sum+=primeArray[j];
				seqSize=j-i+1;
				if(prime_check_with_primeArray(sum,primeArray,primeArraySize) && sum<100000 && maxSeqSize<=seqSize){
                    maxSum=sum;
                    maxSeqSize=seqSize;
				}
			}

		}



		printf("%d",maxSum);
	return EXIT_SUCCESS;
}
