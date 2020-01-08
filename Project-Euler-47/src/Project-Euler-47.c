/*
 ============================================================================
 Name        : Project-Euler-47.c
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

int getDistinctprimeFacorsCount(int number,int *primeArray,int primeArraySize){

	int count=0,i,tmp;

	tmp=number;
	for(i=0;primeArray[i]<=tmp/2 && i<=primeArraySize;i++){

		if(number%primeArray[i]==0){

			while(number%primeArray[i]==0){
				number/=primeArray[i];
			}
			count++;
		}

	}



	return count;


}
int main(void) {


	int number;
	int *primeArray=(int *)malloc(sizeof(int)*SIZE);
	int primeArraySize=0;
	int maxLimit=10000000;

	generatePrimesUptoGivenNumberFast(primeArray, &primeArraySize, maxLimit);

	for (number = 1; number <= maxLimit; number++) {

		if (getDistinctprimeFacorsCount(number,primeArray,primeArraySize) == 4
				&& getDistinctprimeFacorsCount(number+1,primeArray,primeArraySize) == 4 &&
				getDistinctprimeFacorsCount(number+2,primeArray,primeArraySize)==4 &&
				getDistinctprimeFacorsCount(number+3,primeArray,primeArraySize)==4) {

			printf("%d\n", number);
			printf("%d\n", number + 1);
			printf("%d\n", number + 2);
			break;
		}

	}

	//printf("%d",getDistinctprimeFacorsCount(1,primeArray,primeArraySize));
	return EXIT_SUCCESS;
}
