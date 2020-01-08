/*
 ============================================================================
 Name        : Project-Euler-55.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000


void copyArray(int *copyTarget, int *copyTargetSize, int *source,
		int *sourceSize) {
	int bigIndex,smallIndex;
	int startIndex = abs(*copyTargetSize - *sourceSize);
	for (bigIndex = startIndex, smallIndex = 0; bigIndex < *copyTargetSize && smallIndex < *sourceSize;
			smallIndex++, bigIndex++) {

		*(copyTarget + bigIndex) = *(source + smallIndex);

	}
}
int* getSumOfTwoBigNumbers(int *bigNumber, int bigNumberSize, int *smallNumber,int smalNumberSize,int *finalSum, int *finalSumSize,int *tmp) {

	if (bigNumberSize < smalNumberSize) {
		getSumOfTwoBigNumbers(smallNumber, smalNumberSize, bigNumber,
				bigNumberSize,finalSum, finalSumSize,tmp);
	}



	int smalNumberIndex, bigNumberIndex;

	int carry = 0;
	int tmpSum;

	for (smalNumberIndex = smalNumberSize - 1, bigNumberIndex = bigNumberSize
			- 1; smalNumberIndex >= 0 && bigNumberIndex >= 0;
			bigNumberIndex--, smalNumberIndex--) {

		tmpSum = *(bigNumber + bigNumberIndex)
				+ *(smallNumber + smalNumberIndex) + carry;

		*(finalSum + bigNumberIndex) = tmpSum % 10;
		carry = tmpSum / 10;
	}

	while (bigNumberIndex >= 0) {

		tmpSum = *(bigNumber + bigNumberIndex) + carry;
		*(finalSum + bigNumberIndex) = tmpSum % 10;
		carry = tmpSum / 10;
		bigNumberIndex--;
	}

	if (carry) {
		*finalSumSize = bigNumberSize + 1;
		copyArray(tmp, finalSumSize, finalSum, &bigNumberSize);
		*tmp = carry;
		copyArray(finalSum,finalSumSize,tmp,finalSumSize);

	} else {
		*finalSumSize = bigNumberSize;
	}

	return finalSum;
}


int isPalindromeInArrayForm(int *NumberArray,int NumberArraySize){

	int i,j;
	for(i=0,j=NumberArraySize-1;i<j;i++,j--){
            if(NumberArray[i]!=NumberArray[j]){
                  return 0;
            }
	}


	return 1;
}


int islycheralNumber(int number,int *numberArray,int numberArraySize,int *revNumberArray,int revNumberArraySize,
		 int *finalNumberArray,int finalNumberArraySize,int *tmp){

int i,iterationCount=0;
	while(number){
		revNumberArray[revNumberArraySize++]=number%10;
		number/=10;
	}
for(i=revNumberArraySize-1;i>=0;i--){
	numberArray[numberArraySize++]=revNumberArray[i];
}

/*for(i=0;i<numberArraySize;i++){
	printf("%d",numberArray[i]);
}
  printf("\n");*/

while(iterationCount<=55){
	finalNumberArraySize=0;
	revNumberArraySize=0;
	for(i=numberArraySize-1;i>=0;i--){
		revNumberArray[revNumberArraySize++]=numberArray[i];
	}

	/*for(i=0;i<numberArraySize;i++){
		printf("%d",numberArray[i]);
	}
	  printf(" + ");

	for (i = 0; i < revNumberArraySize; i++) {
		printf("%d", revNumberArray[i]);
	}
		printf(" = ");*/

	getSumOfTwoBigNumbers(numberArray,numberArraySize,revNumberArray,revNumberArraySize,finalNumberArray,&finalNumberArraySize,tmp);

	/*for (i = 0; i < finalNumberArraySize; i++) {
			printf("%d", finalNumberArray[i]);
		}
    printf("\n");*/
	if(isPalindromeInArrayForm(finalNumberArray,finalNumberArraySize)){
              return 1;
	}

	numberArraySize=finalNumberArraySize;
	copyArray(numberArray,&numberArraySize,finalNumberArray,&finalNumberArraySize);
	iterationCount++;
}


	return 0;
}

int main(void) {
int number,count=0;

int *numberArray=(int *)malloc(sizeof(int)*SIZE);
int numberArraySize=0;

int *revNumberArray=(int *)malloc(sizeof(int)*SIZE);
int revNumberArraySize=0;

int *finalNumberArray=(int *)malloc(sizeof(int)*SIZE);
int finalNumberArraySize=0;

int *tmp=(int *)malloc(sizeof(int)*SIZE);


for(number =1;number<=10000;number++){
	numberArraySize=0;
	revNumberArraySize=0;
	finalNumberArraySize=0;
     if(islycheralNumber(number,numberArray,numberArraySize,revNumberArray,revNumberArraySize,
    		 finalNumberArray,finalNumberArraySize,tmp)){
    	 count++;

    	/* printf("%d\n",number);*/
     }
}

printf("%d\n",10000-count);

	return EXIT_SUCCESS;
}
