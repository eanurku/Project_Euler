/*
 ============================================================================
 Name        : Project-Euler-72.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define CROSSED 1
#define MAXLIMIT 1000000
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

long long phiFunctionFaster(int number,int *primeArray, int primeArraySize,int *tmpCrossedPrimeArray,int tmpCrossedPrimeArraySize){

   long long i,phiFunctionValue=number;

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

int main(void) {

	long long i,count=0,d;
	int *primeSeq=(int *)malloc(SIZE*sizeof(int));
	int primeSeqSize=0;
    generatePrimesUptoGivenNumberFast(primeSeq,&primeSeqSize,MAXLIMIT);

    int *tmpCrossedPrimeArray=(int *)calloc(MAXLIMIT,sizeof(int));
    int tmpCrossedPrimeArraySize=MAXLIMIT;

    for(i=0;i<tmpCrossedPrimeArraySize;i++){
    	tmpCrossedPrimeArray[primeSeq[i]]=1;
    }

    for(d=2;d<=100000;d++)
    count+=phiFunctionFaster(d,primeSeq,primeSeqSize,tmpCrossedPrimeArray,tmpCrossedPrimeArray);

    printf("%lld",count);
	return EXIT_SUCCESS;
}
