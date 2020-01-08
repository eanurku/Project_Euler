/*
 ============================================================================
 Name        : Project-Euler-17.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
enum numbers {
	TEN = 3,
	ELEVEN = 6,
	TWELVE = 6,
	THIRTEEN = 8,
	FOURTEEN = 8,
	FIFTEEN = 7,
	SIXTEEN = 7,
	SEVENTEEN = 9,
	EIGHTEEN = 8,
	NINETEEN = 8,
	HUNDRED = 7,
	HUNDERD_AND = 10,
	THOUSAND = 8
};

int SingleDigit[] = { 0, 3, 3, 5, 4, 4, 3, 5, 5, 4 }; //one to nine
int DoubleDigit[] = { 0, 0, 6, 6, 5, 5, 5, 7, 6, 6 }; //twenty to ninety

long long reverseOfNumber(long long number) {

	long long lastDigit;
	long long tmp = number;
	long long reverseNumber = 0;

	while (tmp) {

		lastDigit = tmp % 10;
		reverseNumber = reverseNumber * 10 + lastDigit;
		tmp = tmp / 10;
	}

	return reverseNumber;
}
void getNumberInArrayForm(int number, int *numArray, int *size) {

	int digit;
	while (number) {
		digit = number % 10;
		numArray[(*size)++] = digit;
		number /= 10;

	};
}
int getSumSingleDigitNumber(int *numArray, int size) {
	int sum;
	sum = SingleDigit[numArray[size - 1]];

	return sum;
}

int getSumDoubleDigitNumber(int *numArray, int size) {
	int sum = 0;

	switch (numArray[1] * 10 + numArray[0]) {

	case 10:
		sum = TEN;
		break;
	case 11:
		sum = ELEVEN;
		break;
	case 12:
		sum = TWELVE;
		break;
	case 13:
		sum = THIRTEEN;
		break;
	case 14:
		sum = FOURTEEN;
		break;
	case 15:
		sum = FIFTEEN;
		break;
	case 16:
		sum = SIXTEEN;
		break;
	case 17:
		sum = SEVENTEEN;
		break;
	case 18:
		sum = EIGHTEEN;
		break;
	case 19:
		sum = NINETEEN;
		break;
	default:
		sum = SingleDigit[numArray[0]] + DoubleDigit[numArray[1]];

	};

	return sum;
}

int getSumThreeDigitNumber(int *numberArray, int numberArraySize) {
	int sum;
	int *tmpArray = (int *) malloc(sizeof(int) * 10);
		int tmpArraySize = 0;

	switch (numberArray[1] * 10 + numberArray[0]) {
	case 0:
		sum = SingleDigit[numberArray[2]] + HUNDRED;
		break;
	default:
		getNumberInArrayForm(numberArray[1] * 10 + numberArray[0], tmpArray, &tmpArraySize);

		sum = SingleDigit[numberArray[2]] + HUNDERD_AND
				+ getSumDoubleDigitNumber(tmpArray,tmpArraySize);
	};

	return sum;
}



int getSumFourDigitNumber(int *numberArray, int numberArraySize) {


	return THOUSAND+SingleDigit[1];
}
int main(void) {
	int i, number;
	long long sum = 0;
	int *numberArray = (int *) malloc(sizeof(int) * 10);
	int numberArraySize = 0;

	for (number = 1; number <=1000; number++) {
		numberArraySize = 0;
		getNumberInArrayForm(number, numberArray, &numberArraySize);

		switch (numberArraySize) {

		case 1:
			sum += getSumSingleDigitNumber(numberArray, numberArraySize);
			break;
		case 2:
			sum += getSumDoubleDigitNumber(numberArray, numberArraySize);
			break;
		case 3:
			sum += getSumThreeDigitNumber(numberArray, numberArraySize);
			break;
		case 4:
			sum += getSumFourDigitNumber(numberArray, numberArraySize);
			break;
		}

	}

	printf("%d", sum);
	return EXIT_SUCCESS;
}
