/*
 ============================================================================
 Name        : Project-Euler-35.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define CROSSED 1
#define MAX_PRIMES 200000

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
	for (i = 0; primeNumberSequence[i] <= sqrt(number); i++) {
		if (number % primeNumberSequence[i] == 0) {

			return 0;
		}
	}

	return 1;
}


int getDigitsCount(int number) { //number=0 return count=0

	int count = 0;
	while (number) {
		number /= 10;
		count++;
	}

	return count;
}
int rotateNumber(int number){

	int lastDigit,finalNumber;
	lastDigit=number%10;
	finalNumber=pow(10,getDigitsCount(number/10))*lastDigit+number/10;

return finalNumber;
}
int isCircularprime(int number,int *primeArray,int primeArraySize){

	int rotation,numberOfRotation;
    numberOfRotation=getDigitsCount(number);

    for(rotation=1;rotation<=numberOfRotation;rotation++){

    	number=rotateNumber(number);
    	if(!prime_check_with_primeArray(number,primeArray,primeArraySize)){
    		return 0;
    	}
    }



	return 1;
}
int main(void) {

	int i,circularPrimeCount=0,maxLimit=1000000;

	int *primeArray=(int *)malloc(sizeof(int)*MAX_PRIMES);
	int primeArraySize=0;

	generatePrimesUptoGivenNumberFast(primeArray, &primeArraySize, maxLimit);

	for(i=0;i<primeArraySize;i++){

		if(isCircularprime(primeArray[i],primeArray,primeArraySize)){

			circularPrimeCount++;

		}


	}


	printf("count=%d",circularPrimeCount);
	return EXIT_SUCCESS;
}
