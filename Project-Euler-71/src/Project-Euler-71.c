/*
 ============================================================================
 Name        : Project-Euler-71.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXLIMIT 8
#define NUMFIXRATIO 3
#define DENFIXRATIO 7

int GCD(int big,int small){
	if(big<small)
		GCD(small,big);
	if(small==0)
		return big;
	return(GCD(small,big%small));
}

int main(void) {

	int d, n;

	int numMinRatio=0,denMinRatio=1;

	for(d=2;d<=MAXLIMIT;d++){

		n=(NUMFIXRATIO*d-1)/DENFIXRATIO;//n/d<NUM/DEN
		if(n*denMinRatio>numMinRatio*d){
              denMinRatio=d;
              numMinRatio=n;
		}
	}
	printf("%d/%d",numMinRatio,denMinRatio);


	return EXIT_SUCCESS;
}
