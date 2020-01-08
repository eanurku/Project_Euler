/*
 ============================================================================
 Name        : Project-Euler-45.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	long long pentagonalIndex, hexagonalIndex, pentagonalNumber,
			hexagonalNumber, found = 0, tringularIndex = 286, tringularNumber =
					1;

	while (1) {

		tringularNumber = (tringularIndex * (tringularIndex + 1)) / 2;
		pentagonalIndex = 1;
		pentagonalNumber = 1;

		while (pentagonalNumber <= tringularNumber) {
			pentagonalNumber = (pentagonalIndex * (3 * pentagonalIndex - 1))
					/ 2;
			if (tringularNumber == pentagonalNumber) {
				hexagonalIndex = 1;
				hexagonalNumber = 1;
				while (hexagonalNumber <= pentagonalNumber) {

					hexagonalNumber = hexagonalIndex * (2 * hexagonalIndex - 1);
					if (hexagonalNumber == pentagonalNumber) {
						found = 1;
						break;
					}
					hexagonalIndex++;
				}
			}

			if (found) {
				break;
			}

			pentagonalIndex++;
		}
		if (found) {
			break;
		}
		tringularIndex++;

	}

	printf("%lld", hexagonalNumber);

	return EXIT_SUCCESS;
}
