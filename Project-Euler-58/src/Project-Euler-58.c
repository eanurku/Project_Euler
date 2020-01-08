/*
 ============================================================================
 Name        : Project-Euler-58.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define CROSSED 1
#define NUMBERS_ON_DIAGONAL 4
#define SIZE 10000000


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


int isPrimeFast(long long number) {

	long long  factor,r;
	if(number==1){
		return 0;
	}else if(number<4){
		return 1;
	}else if(number%2==0){
        return 0;
	}else if(number%3==0){
		return 0;
	}

	r=sqrt(number);
	for(factor=5;factor<=r;factor+=6)
         if((number%factor==0)||(number%(factor+2)==0)){
        	 return 0;
         }

	return 1;
}

int main(void) {

int spiralSide;

double cumulativePrimeCount=0,cumulativeDigonalnumbersCount=1;
int maxLimit=100000000;
int *primeArray=(int *)malloc(sizeof(int)*SIZE);
int primeArraySize=0;

//generatePrimesUptoGivenNumberFast(primeArray, &primeArraySize,maxLimit);

//printf("%d",primeArraySize);

for(spiralSide=3;;spiralSide+=2){

	cumulativeDigonalnumbersCount+=NUMBERS_ON_DIAGONAL;

	/*if(prime_check_with_primeArray(spiralSide*spiralSide-(spiralSide-1),primeArray,primeArraySize)){
		cumulativePrimeCount++;
	}

	if(prime_check_with_primeArray(spiralSide*spiralSide-2*(spiralSide-1),primeArray,primeArraySize)){
		cumulativePrimeCount++;
	}
	if(prime_check_with_primeArray(spiralSide*spiralSide-3*(spiralSide-1),primeArray,primeArraySize)){
		cumulativePrimeCount++;
	}
*/


	if(isPrimeFast(spiralSide*spiralSide-(spiralSide-1))){
		cumulativePrimeCount++;
	}

	if(isPrimeFast(spiralSide*spiralSide-2*(spiralSide-1))){
			cumulativePrimeCount++;
		}
	if(isPrimeFast(spiralSide*spiralSide-3*(spiralSide-1))){
			cumulativePrimeCount++;
		}

	if(cumulativePrimeCount/cumulativeDigonalnumbersCount <= 0.1){
		printf("%lf/%lf\n",cumulativePrimeCount,cumulativeDigonalnumbersCount);
		printf("side=%d",spiralSide);
		break;
	}
	//printf("%d/%d\n",cumulativePrimeCount,cumulativeDigonalnumbersCount);



}






	return EXIT_SUCCESS;
}
