/*
 ============================================================================
 Name        : Project-Euler-85.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int getRectangleFormedCount(int m,int n){


	return (m*(m+1)*n*(n+1))/4;


}


int main(void) {

int m,n,count,maxCount=0,maxN=0,maxM=0;

	for (m = 1; m <= 100; m++) {
		for (n = 1; n <= 100; n++) {

			count = getRectangleFormedCount(m, n);
			if (count <= 2 * 1000000) {
				if (count > maxCount) {
					maxCount = count;
					maxM=m;
					maxN=n;
				}
			} else {

				break;
			}

		}
}
	printf("%d * %d rectangle area=%d, count= %d\n", maxN, maxM, maxN*maxM, maxCount);
	return EXIT_SUCCESS;
}
