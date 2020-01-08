/*
 ============================================================================
 Name        : Project-Euler-80.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define LIMIT 10000000
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
int main(void) {

	int *primeArray=(int *)malloc(sizeof(int)*SIZE);
	int primeArraySize=0;

	generatePrimesUptoGivenNumberFast(primeArray,&primeArraySize,LIMIT);
/*	for(int i=0;i<primeArraySize;i++)
	printf("%d ",primeArray[i]);*/

	int i,j,k,min=9999999;
	int *ways=(int *)calloc(SIZE,sizeof(int));

	ways[0]=1;
	ways[1]=0;
	int found=0;
	for(i=0; primeArray[i]<1000;i++){

		for(j=primeArray[i];j<SIZE;j++){

			ways[j]+=ways[j-primeArray[i]];
		}

		for(k=0;k<SIZE;k++){

			if(ways[k]>=5000){
				if(min>k)
				min=k;

				break;
			}
		}
	}



	printf("\n%d",k);
	return EXIT_SUCCESS;
}
