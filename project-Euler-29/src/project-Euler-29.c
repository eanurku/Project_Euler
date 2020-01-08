/*
 ============================================================================
 Name        : project-Euler-29.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SET_SIZE 10000
#define MAX_DIGITS 205

int getDigitsCount(int number) { //number=0 return count=0

	int count = 0;
	while (number) {
		number /= 10;
		count++;
	}

	return count;
}
void copyArray(int *copyTarget, int *copyTargetSize, int *source,
		int *sourceSize) {
	int bigIndex, smallIndex;
	int startIndex = abs(*copyTargetSize - *sourceSize);
	for (bigIndex = startIndex, smallIndex = 0;
			bigIndex < *copyTargetSize && smallIndex < *sourceSize;
			smallIndex++, bigIndex++) {

		*(copyTarget + bigIndex) = *(source + smallIndex);

	}
}

int * getProduct(int *finalNumArray, int *finalNumArraySize, int multiplier) {
	int i, prodSum, digit;
	int carry = 0, digitCounts;

	int *tmpArray = (int *) malloc(sizeof(int) * MAX_DIGITS);
	int tmpArraySize = *finalNumArraySize;

	copyArray(tmpArray, &tmpArraySize, finalNumArray, finalNumArraySize);

	for (i = tmpArraySize - 1; i >= 0; i--) {

		prodSum = *(tmpArray + i) * multiplier + carry;

		digit = prodSum % 10;
		carry = prodSum / 10;

		*(tmpArray + i) = digit;
	}

	if (carry) {
		digitCounts = getDigitsCount(carry);
		i = digitCounts - 1;
		while (carry) {

			*(finalNumArray + i--) = carry % 10;
			carry /= 10;
		}

		*finalNumArraySize += digitCounts;
		copyArray(finalNumArray, finalNumArraySize, tmpArray, &tmpArraySize);
	} else {
		copyArray(finalNumArray, finalNumArraySize, tmpArray, &tmpArraySize);
	}

}

void getPowerForAnyBase(int number, int power, int *productArray, int *productArraySize) {

	int i,j;
	*(productArray + (*productArraySize)++) = 1;

	for (i = 1; i <= power; i++) {
		getProduct(productArray, productArraySize, number);

	}

}

//add to set
void addToSetOfNumbers(char **setOfNumbers,int *setofnumbersSize,int *powerArray,int *powerArraySize){

	int i,found=0;
	char *powerCharArray = (char *) malloc(sizeof(char) * MAX_DIGITS);
	int powerCharArraySize = 0;

	//convert to char array
	for (i = 0; i < *powerArraySize; i++) {

		powerCharArray[powerCharArraySize++] = powerArray[i] + '0';
	}
	powerCharArray[powerCharArraySize++] = '\0';

  //add to set if no duplicate exists
   for(i=0;i< *setofnumbersSize;i++){

	   if(strcmp(powerCharArray,setOfNumbers[i])==0){
		   found=1;break;
	   }

   }
if(!found){
	setOfNumbers[(*setofnumbersSize)++]=powerCharArray;
}

}
int main(void) {

	long long base, exp;
	int i;

	int *powerArray = (int *) malloc(sizeof(int) * MAX_DIGITS);
	int powerArraySize = 0;


//declare a set
	char **setOfNumbers = (char **) malloc(sizeof(char *) * SET_SIZE);
	int setofnumbersSize = 0;


	for (base = 2; base <= 100; base++) {
		for (exp = 2; exp <= 100; exp++) {
			powerArraySize = 0;
			getPowerForAnyBase(base, exp, powerArray, &powerArraySize);

            addToSetOfNumbers(setOfNumbers,&setofnumbersSize,powerArray,&powerArraySize);

		}
	}


/*	for(i=0;i<setofnumbersSize;i++){
		printf("%s\n",setOfNumbers[i]);
	}*/
	printf("%d",setofnumbersSize);
	return EXIT_SUCCESS;
}
