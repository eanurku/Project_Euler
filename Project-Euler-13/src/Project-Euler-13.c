/*
 ============================================================================
 Name        : Project-Euler-13.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define DIGITS 50
#define NUMBERS 100
//copy from right to left
void copyArray(int *copyTarget, int *copyTargetSize, int *source,
		int *sourceSize) {
	int bigIndex,smallIndex;
	int startIndex = abs(*copyTargetSize - *sourceSize);
	for (bigIndex = startIndex, smallIndex = 0; bigIndex < *copyTargetSize && smallIndex < *sourceSize;
			smallIndex++, bigIndex++) {

		*(copyTarget + bigIndex) = *(source + smallIndex);

	}
}
void getSumOfTwoNumbers(int * bigNumber, int * bigNumberSize, int * smallNumber,
		int * smallNumberSize) {

	if (*bigNumberSize < *smallNumberSize)
		getSumOfTwoNumbers(smallNumber, smallNumberSize, bigNumber,
				bigNumberSize);

	int carry, smallIndex, remainingIndex,bigIndex;
	int *tmpBigNumber = (int *) malloc((*bigNumberSize) * 4);
	int tmpBigNumberSize = *bigNumberSize;
	int tmpSum = 0;

	copyArray(tmpBigNumber, bigNumberSize, bigNumber, bigNumberSize);
	//printf("\n");
	carry = 0;

	for (smallIndex = *smallNumberSize - 1,bigIndex=*bigNumberSize-1; smallIndex >= 0 && bigIndex>=0 ;bigIndex--, smallIndex--) {

		tmpSum = *(bigNumber + bigIndex) + *(smallNumber + smallIndex)
				+ carry;
		*(tmpBigNumber + bigIndex) = tmpSum % 10;

		carry = tmpSum / 10;
	}

	for (remainingIndex = *bigNumberSize - *smallNumberSize - 1;
			remainingIndex >= 0; remainingIndex--) {

		tmpSum = *(bigNumber + remainingIndex) + carry;
		*(tmpBigNumber + remainingIndex) = tmpSum % 10;
		carry = tmpSum / 10;
	}

	if (carry != 0) {
		*(bigNumber) = carry;
		(*bigNumberSize)++;
		copyArray(bigNumber, bigNumberSize, tmpBigNumber, &tmpBigNumberSize);
	} else {
		copyArray(bigNumber, bigNumberSize, tmpBigNumber, &tmpBigNumberSize);
	}

}

int main(void) {

	int row = 0, col = 0, saveColumn, saveRow, i, j;
	int array[NUMBERS][DIGITS];
	int character;
	FILE *inputFile, *outputFile;

	int *sum = (int *) calloc(2000, 4);
	int sumSize = DIGITS;
	int digits = DIGITS;

	 inputFile =
	 fopen(
	 "C:\\Users\\anurag\\Desktop\\CPRGG\\CPROGG-workspace\\Project-Euler-13\\src\\input.txt",
	 "r");
	 outputFile=fopen("C:\\Users\\anurag\\Desktop\\CPRGG\\CPROGG-workspace\\Project-Euler-13\\src\\output.txt","r");

	 while ((character = fgetc(inputFile)) != EOF) {

	 if (col == DIGITS && character == '\n') {
	 saveColumn = col;
	 col = 0;
	 row++;
	 saveRow = row;
	 continue;
	 }

	 array[row][col++] = character - '0';
	 }
	 saveRow++;

	 fclose(inputFile);
	 fclose(outputFile);

		for (i = 0; i < saveRow; i++) {
			for (j = 0; j < saveColumn; j++)
				printf("%d ", array[i][j]);
			printf("\n");
		}

	for (i = 0; i <NUMBERS; i++) {

	 getSumOfTwoNumbers(sum, &sumSize, array[i], &digits);

	 }

	 for(j=0;j<10;j++)
	 printf("%d",*(sum+j));



	return EXIT_SUCCESS;
}
