/*
 ============================================================================
 Name        : Project-Euler-6.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description :

The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385
The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 385 = 2640.
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int maxNaturalNumberLimit,n;
	long long diff;

	scanf("%d",&maxNaturalNumberLimit);

	n=maxNaturalNumberLimit;

	diff=(n*(n*n-1)*(3*n+2))/12;

	printf("diffrence=%lld",diff);
	return EXIT_SUCCESS;
}
