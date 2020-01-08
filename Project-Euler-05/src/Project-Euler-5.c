/*
 ============================================================================
 Name        : Project-Euler-5.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description :
 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int isPrime(long long number) {
	long long i;
	for (i = 2; i < number; i++) {
		if (number % i ==0 ) {
			return 0;
		}
	}
	return 1;
}
int getAllPrimeUptoMaxLimit(long long primeArray[], long long maxLimit) {
	long long i, arrayIndex = 0;

	for (i = 2; i <= maxLimit; i++)
		if (isPrime(i)) {
			primeArray[arrayIndex++] = i;
		}

	return arrayIndex;
}

int main(void) {

	long long maxLimit, primeArray[1000],lcm;
	int arraySize, i;

	scanf("%lld", &maxLimit);

	arraySize = getAllPrimeUptoMaxLimit(primeArray, maxLimit);

	lcm=1;

	for(i=0;i<arraySize;i++){

		lcm*=pow(primeArray[i],(int)(log10(maxLimit)/log10(primeArray[i])));
	}


	printf("LCM=%lld\n",lcm);



/*	for (i = 0; i < arraySize; i++)
		printf("%lld\n", *(primeArray + i));*/

	return EXIT_SUCCESS;
}
