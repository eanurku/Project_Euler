/*
 ============================================================================
 Name        : Project-Euler-66.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


long long isPerfectSquare(long long z)
{  long long x;
    x=sqrt(z);
   if(x*x==z)
   return x;
   else
   return 0;
}
int isNumberHavingFactor(long long number,long long factor){

     long long dividend=number/factor;

     return (factor*dividend ==number);
}
int main(void) {

	int constantD;
	long long parameterX,parameterY,ysquareCrossD,ysquare,maxX=0;

	//printf("%lld",parameterX);

	for (constantD = 2; constantD <= 100; constantD++) {

		if (isPerfectSquare(constantD))
			continue;

		for (parameterX = 2;; parameterX++) {
			printf("x=%lld,D=%d\n",parameterX,constantD);
			ysquareCrossD = parameterX * parameterX - 1;
			ysquare = (parameterX * parameterX - 1) / constantD;
			if (isNumberHavingFactor(ysquareCrossD, constantD) && isPerfectSquare(ysquare)) {

				break;
			}
		}
		if ((parameterX > maxX)) {
			maxX = parameterX;
		}
	}

	printf("x=%lld",maxX);
	return EXIT_SUCCESS;
}
