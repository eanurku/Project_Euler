/*
 ============================================================================
 Name        : Project-Euler-41.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define CROSSED 1
#define PRIME_SEQ_LIMIT 10000000

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

int getDigitsCountGeneral(int number) {

	int count = 0;

	if(number==0){
		return 1;
	}
	while (number) {
		number /= 10;
		count++;
	}

	return count;
}
int pandigitalArrayCheck(int *pandigitalArray,int numberOfDigits){




	int i;
	/*for(i=0;i<=9;i++){
    printf("%d,",pandigitalArray[i]);
	}*/

	for(i=1;i<=numberOfDigits;i++){

		if(pandigitalArray[i]!=1){
			return 0;
		}
	}

	return 1;
}

int isPandigital(long long  number){

	int digit,numberOfDigits,i;
	int pandigitalArray[10]={0};
    numberOfDigits=getDigitsCountGeneral(number);

    if(numberOfDigits>9){
    	return 0;
    }

	while(number){
		digit=number%10;
		pandigitalArray[digit]++;
		number/=10;
	}

	if(pandigitalArrayCheck(pandigitalArray,numberOfDigits)){
		return 1;
	}

	return 0;
}

int main(void) {

	int maxLimit=100000000;//10^9 7652413
	int i;
	int *primeArray=(int *)malloc(sizeof(int)*PRIME_SEQ_LIMIT);
	int primeArraySize=0;
	generatePrimesUptoGivenNumberFast(primeArray, &primeArraySize,maxLimit);

	for(i=primeArraySize-1;i>=0;i--){

		if(isPandigital(primeArray[i])){
			break;
		}
	}


	printf("%d",primeArray[i]);





	return EXIT_SUCCESS;
}
