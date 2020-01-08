/*
 ============================================================================
 Name        : Project-Euler-3.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description :

 The prime factors of 13195 are 5, 7, 13 and 29.
 What is the largest prime factor of the number 600851475143 ?

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
 #include <time.h>
int main(void) {

	  long long number=600851475143, factor;

	  clock_t startTime,endTime;
	  startTime=clock();
/*	scanf("%lld", &number);*/
	factor = 2;

	while (factor <= number) {

		while (number != factor && (number % factor) == 0) {
			number = number / factor;
		}

		if (factor == 2)
			factor = 3;
		else
			factor += 2;
	};
	factor=number;
	printf("%lld", factor);
	endTime=clock();

	printf("\n%d",(endTime-startTime)/(double)CLOCKS_PER_SEC);
	return EXIT_SUCCESS;
}
