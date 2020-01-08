/*
 ============================================================================
 Name        : Project-Euler-23.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *array, int start, int end, int searchme) {

	int mid;

	while (start <= end) {
		mid = (start + end) / 2;
		if (array[mid] == searchme) {
			return 1;
		} else if (searchme > array[mid]) {
			start = mid + 1;
		} else
			end = mid - 1;

	}

	return 0;
}

int search(int *arrray, int arraySize, int searchMe) {
	return binarySearch(arrray, 0, arraySize - 1, searchMe);
}

int search1(int *arrray, int arraySize, int searchMe) {
	int i;
	for (i = 0; i < arraySize; i++)
		if (searchMe == arrray[i]) {
			return 1;
		}
	return 0;
}
int getProperDivisorsSumFast(int number) {
	int sum = 0, i;
	int numberSQRT = sqrt(number);

	for (i = 2; i * i < number; i++) {

		if (number % i == 0) {
			sum += i;
			sum += (number / i);
		}

	}
	if ((number != 1) && (numberSQRT * numberSQRT == number)) {
		sum += numberSQRT;
	}

	return sum + 1;
}
int isAbundant(int number) {

	if (getProperDivisorsSumFast(number) > number) {
		return 1;
	}

	return 0;
}

int isSumOfTwoAbundant(int *AbundantNumber, int AbundantNumberSize, int number) {

	int i, j;
	for (i = 0; *(AbundantNumber+i) < number && i < AbundantNumberSize; i++) {

		for (j = i;
				(*(AbundantNumber+j) + *(AbundantNumber+i)) <= number
						&& j < AbundantNumberSize; j++)

			if (number == (*(AbundantNumber+j) + *(AbundantNumber+i)))
				return 1;
	}

	return 0;
}
int main(void) {

	int number, AbundantNumberSize = 0, sumOfTwoAbundantArrraySize = 0,
			sum1 = 0, sum = 0, i, j;
	int *AbundantNumber = (int *) malloc(sizeof(int) * 30000);
	int *sumOfTwoAbundantArrray = (int *) calloc(30000,sizeof(int));

	//generate abundant number upto limit =28123
	for (number = 2; number <= 28123; number++) {

		if (isAbundant(number)) {

			*(AbundantNumber+AbundantNumberSize++)= number;
			printf("%d ", number);

		}
	}


for(i=0;i<AbundantNumberSize;i++){
	for(j=0;j<AbundantNumberSize;j++){

		if(*(AbundantNumber+j) + *(AbundantNumber+i)<=28123 && sumOfTwoAbundantArrray[*(AbundantNumber+j) + *(AbundantNumber+i)]!=1){
			sumOfTwoAbundantArrray[*(AbundantNumber+j) + *(AbundantNumber+i)]=1;
		}

	}
}

for(i=1;i<=28123;i++){
	if(!sumOfTwoAbundantArrray[i]){
		sum+=i;
	}
}

/*

	for (number = 1; number <= 28123; number++) {

		if (!isSumOfTwoAbundant(AbundantNumber, AbundantNumberSize, number)) {
			sum += number;


		}
	}
*/

	printf("\n%d", sum);
	return EXIT_SUCCESS;
}
