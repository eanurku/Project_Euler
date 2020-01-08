/*
 ============================================================================
 Name        : Project-Euler-70.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define CROSSED 1
#define SIZE 1000000
#define MAXLIMIT 10000000
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

int phiFunctionFaster(int number,int *primeArray, int primeArraySize,int *tmpCrossedPrimeArray,int tmpCrossedPrimeArraySize){

   int i,phiFunctionValue=number;

   if(tmpCrossedPrimeArray[number]){

	   return number-1;
   }

    for(i=0; primeArray[i]<number && i<primeArraySize;i++){
         if((number%primeArray[i])==0){
        	 phiFunctionValue=(phiFunctionValue/primeArray[i])*(primeArray[i]-1);

        	 while((number%primeArray[i])==0){
        		 number/=primeArray[i];
        	 }
         }
    }


   if(number>1)
	  phiFunctionValue=(phiFunctionValue/number)*(number-1);

   return phiFunctionValue;
}

int isPermutationOfeachother(int number1, int number2) {

	int numArray1[10] = { 0 };
	int numArray2[10] = { 0 };
	int i;

	while (number1) {
		numArray1[number1 % 10]++;
		number1 /= 10;
	}
	while (number2) {
		numArray2[number2 % 10]++;
		number2 /= 10;
	}

	for (i = 0; i < 10; i++) {

		if (numArray1[i] != numArray2[i]) {
			return 0;
		}
	}

	return 1;
}

int main(void) {

	int number, phiFunctionValue, uniqNumber = 0, i,j;
	double ratio=0, minRatio = MAXLIMIT;

	int *primeSequence = (int *) malloc(SIZE * sizeof(int));
	int primeSeqSize = 0;
	generatePrimesUptoGivenNumberFast(primeSequence, &primeSeqSize, MAXLIMIT);

	int *tmpPrimeArray = (int *) calloc(MAXLIMIT, sizeof(int));
	int tmpPrimeArraySize = MAXLIMIT;
	for (i = 0; i < primeSeqSize; i++) {
		tmpPrimeArray[primeSequence[i]] = 1;
	}
/*
	for (number = 2; number < 10000000; number++) {
		if(tmpPrimeArray[number]){
			continue;
		}
		phiFunctionValue = phiFunctionFaster(number, primeSequence, primeSeqSize,tmpPrimeArray, tmpPrimeArraySize);
		if (isPermutationOfeachother(number, phiFunctionValue)) {
			ratio = number / (double) phiFunctionValue;
			if (ratio < minRatio) {
				minRatio = ratio;
				uniqNumber = number;
			}
		}

	}*/



	for(i=0;i<primeSeqSize;i++){

		for(j=0;j<=i && j<primeSeqSize && (number=(primeSequence[i])*(primeSequence[j])) < MAXLIMIT;j++){

			if (tmpPrimeArray[number]) {
				continue;
			}
			phiFunctionValue = (primeSequence[i] - 1) * (primeSequence[j] - 1);

			if (isPermutationOfeachother(number, phiFunctionValue)) {

				ratio = number / (double) phiFunctionValue;

				if (ratio < minRatio) {
					minRatio = ratio;
					uniqNumber = number;
					break;
				}
			}

		}

	}
	printf("%lf,%d", minRatio, uniqNumber);

	return EXIT_SUCCESS;
}
