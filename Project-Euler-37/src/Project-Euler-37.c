/*
 ============================================================================
 Name        : Project-Euler-37.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define CROSSED 1
#define MAX_PRIMES 10000000

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

long long reverseOfNumber(long long number){

	long long lastDigit;
	long long tmp=number;
	long long reverseNumber= 0;

	while(tmp){

		lastDigit=tmp%10;
		reverseNumber=reverseNumber*10+lastDigit;
		tmp=tmp/10;
	}

	return reverseNumber;
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

int istruncatablePrime(int number ,int *primeArray,int primeArraySize){

int revNum;
int reverseNumber=reverseOfNumber(number);

	while(number){
		if(!prime_check_with_primeArray(number,primeArray,primeArraySize)){
			return 0;
		}
		number/=10;
	}

	while(reverseNumber && reverseNumber/10){

		reverseNumber/=10;
		revNum=reverseOfNumber(reverseNumber);
		if(!prime_check_with_primeArray(revNum,primeArray,primeArraySize)){
					return 0;
				}

	}

return 1;
}
int main(void) {

	int i,maxLimit=10000000;

	int *primeArray=(int *)malloc(sizeof(int)*MAX_PRIMES);
	int primeArraySize=0;

	int sum=0,count=0;
	generatePrimesUptoGivenNumberFast(primeArray, &primeArraySize, maxLimit);


	for(i=4;i<primeArraySize;i++){

		if(istruncatablePrime(primeArray[i],primeArray,primeArraySize) ){
			count++;

			printf("\n%d",primeArray[i]);

			sum+=primeArray[i];

			if (count == 11) {
				break;
			}


		}
    }


		printf("\nsum=%d",sum);
//748317
	return EXIT_SUCCESS;
}
