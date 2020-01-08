/*
 ============================================================================
 Name        : Project-Euler-46.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define CROSSED 1


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


int isperfectSquare(double number)
{  double sqrtNumber=sqrt(number);
      long long tmpNumber=sqrtNumber;

      double tmp=tmpNumber;
      if(tmp==sqrtNumber)
       return 1;
       else
        return 0;

}

int IsGoldbachNumber(double number, int *primeNumberSequence, int sequenceSize){

int i;
	for(i=0;primeNumberSequence[i]<number;i++){

		if(isperfectSquare((number-primeNumberSequence[i])/2)){

			return 1;
		}


	}

	return 0;
}


int main(void) {

int maxLimit=100000000,i;
	int *primeArray=(int *)malloc(sizeof(int)*10000000);
	int primeArraySize=0;
	generatePrimesUptoGivenNumberFast(primeArray, &primeArraySize, maxLimit);
	//printf("%d",primeArraySize);

	for (i = 9; i>0; i += 2) {

		if (!prime_check_with_primeArray(i, primeArray, primeArraySize)) {

			if (!IsGoldbachNumber(i,primeArray, primeArraySize)){

				printf("%d",i);
				break;
			}





		}

	}





	return EXIT_SUCCESS;
}
