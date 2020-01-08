/*
 ============================================================================
 Name        : Project-Euuler-97.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

long long exponent,product=1,lastTenDigit;

	for(exponent=1;exponent<=7830457;exponent++){

		product=product*2;
		lastTenDigit=product%10000000000ll;
		product=lastTenDigit;
	}
	printf("%lld\n",lastTenDigit);
	lastTenDigit=(28433*product+1)%10000000000ll;


printf("%lld",lastTenDigit);
	return EXIT_SUCCESS;
}
