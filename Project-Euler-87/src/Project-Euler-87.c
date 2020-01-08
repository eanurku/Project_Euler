/*
 ============================================================================
 Name        : Project-Euler-87.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define CROSSED 1
#define SIZE 10000
#define MAXLIM 10000

#define MAX_DIGITS 10
#define SET_SIZE 10000000
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
//add to set
void addToSetOfNumbers(char **setOfNumbers,int *setofnumbersSize,char *str){

	int i,found=0;
	char *copystr = (char *) malloc(sizeof(char) * MAX_DIGITS);

   for(i=0;i< *setofnumbersSize;i++){

	   if(strcmp(str,setOfNumbers[i])==0){
		   found=1;break;
	   }

   }
if(!found){
	strcpy(copystr,str);
	setOfNumbers[(*setofnumbersSize)++]=copystr;
	return;
}

}



int main(void) {

	int *primeArray=(int *)malloc(sizeof(int)*SIZE);
	int primeArraySize=0;
	generatePrimesUptoGivenNumberFast(primeArray,&primeArraySize,MAXLIM);

	int i,j,k,count=0,sum;

	//declare a set
		char **setOfNumbers = (char **) malloc(sizeof(char *) * SET_SIZE);
		int setofnumbersSize = 0;


		char *str = (char *) malloc(sizeof(char) * MAX_DIGITS);
		int square[7071],cube[368],quad[84];

		for(i=0;i<7071;i++){
			square[i]=primeArray[i]*primeArray[i];
		}
		for(j=0;j<368;j++){

			cube[j]=primeArray[j]*primeArray[j]*primeArray[j];
		}
		for(k=0;k<84;k++){
			quad[k]=primeArray[k]*primeArray[k]*primeArray[k]*primeArray[k];
		}



	for(i=0;primeArray[i]<7071;i++)
		for (j = 0; primeArray[j] < 368; j++) {
			if (square[i] + cube[j] >= 50000000)
				break;
			for (k = 0; primeArray[k] < 84; k++) {
				sum = square[i] + cube[j] + quad[k];
				if (sum < 50000000) {
					sprintf(str, "%d", sum);

					addToSetOfNumbers(setOfNumbers, &setofnumbersSize, str);
					count++;
				} else {
					break;
				}
			}
}
	printf("count=%d,set size=%d",count,setofnumbersSize);
	return EXIT_SUCCESS;
}
