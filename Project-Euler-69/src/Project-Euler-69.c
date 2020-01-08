/*
 ============================================================================
 Name        : Project-Euler-69.c
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

int phiFunction(int number,int *primeArray, int primeArraySize){

int i,phiFunctionValue=number;

    for(i=0; primeArray[i]<number && i<primeArraySize;i++){
         if((number%primeArray[i])==0){
        	 phiFunctionValue=(phiFunctionValue/primeArray[i])*(primeArray[i]-1);

        	 while((number%primeArray[i])==0){
        		 number/=primeArray[i];
        	 }
         }
    }


if(number>1){
	phiFunctionValue=(phiFunctionValue/number)*(number-1);
}

/*

if(phiFunctionValue==number){
	phiFunctionValue-=1;
}
*/

return phiFunctionValue;
}


int main(void) {
 double maxValue=0,tmp;
int number=2,relativePrimeCount,maxNumber=number,maxLimit = 1000000;


int *primeArray = (int *) malloc(sizeof(int) * SIZE);
int primeArraySize = 0;

generatePrimesUptoGivenNumberFast(primeArray, &primeArraySize, maxLimit);


	while(number<=1000000){


		relativePrimeCount=phiFunction(number,primeArray,primeArraySize);

		tmp=number/(double)relativePrimeCount;

		if(tmp>maxValue){
			maxValue=tmp;
			maxNumber=number;

		}

        number++;

	}
	printf("%lf,%d\n",maxValue,maxNumber);


	return EXIT_SUCCESS;
}
