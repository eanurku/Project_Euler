/*
 ============================================================================
 Name        : Project-Euler-33.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int GCD(int big, int small) {
	if (big < small)
		GCD(small, big);
	if (small == 0)
		return big;
	return (GCD(small, big % small));
}

int isCuriousFraction(int num, int den) {

	int numdigit1, numdigit2, dendigit1, dendigit2, finalNum, finalDen, gcd;

	finalNum = num / GCD(num, den);
	finalDen = den / GCD(num, den);

	numdigit1 = num % 10;
	num /= 10;
	numdigit2 = num % 10;

	dendigit1 = den % 10;
	den /= 10;
	dendigit2 = den % 10;

	if (numdigit1 == dendigit2) {

		gcd = GCD(numdigit2, dendigit1);
		numdigit2 = numdigit2 / gcd;
		dendigit1 = dendigit1 / gcd;

		if (finalNum == numdigit2 && finalDen == dendigit1) {
			return 1;
		}
	}

	return 0;

}
int main(void) {

	int num, den, prodNum = 1, prodDen = 1;

	for (num = 10; num <= 99; num++) {
		for (den = num + 1; den <= 99; den++) {

			if (isCuriousFraction(num, den)) {
				prodNum *= num;
				prodDen *= den;
			}
		}
	}

	printf("%d,%d", prodNum, prodDen);
	return EXIT_SUCCESS;
}
