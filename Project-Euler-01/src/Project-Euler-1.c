/*
 ============================================================================
 Name        : Project-Euler-1.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description :
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int main(void) {

	int multiple1, multiple2, limit;
    int noOfterms1,noOfterms2,noOfterms3;
    int s1,s2,s3;
    int multiple3;
    int cd1,cd2,cd3;

	scanf("%d%d%d", &multiple1, &multiple2, &limit);

    multiple3=(multiple1*multiple2)/GCD(multiple1,multiple2);



    cd1=multiple1;
	noOfterms1 = 1;

	while (multiple1 + cd1*(noOfterms1 - 1) < limit) { //if nth term >=limit then n-1 th term is <limit
		noOfterms1++;
	}
	noOfterms1--;

	cd2=multiple2;
	noOfterms2 = 1;
	while (multiple2 + cd2*(noOfterms2 - 1) < limit) { //if nth term >=limit then n-1 th term is <limit
		noOfterms2++;
	}
	noOfterms2--;

	cd3=multiple3;
	noOfterms3 = 1;
	while (multiple3 + cd3*(noOfterms3- 1) < limit) { //if nth term >=limit then n-1 th term is <limit
		noOfterms3++;
	}
	noOfterms3--;

    printf("%d %d %d ",noOfterms1,noOfterms2,noOfterms3);

	s1 = sumOfAP(multiple1, cd1, noOfterms1);
	s2 = sumOfAP(multiple2, cd2, noOfterms2);
	s3 = sumOfAP(multiple3, cd3, noOfterms3);

    printf("final sum=%d",s1+s2-s3);
	return 0;
}
