/*
 ============================================================================
 Name        : Project-Euler-27.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

long long SumOfSquares(int firstTerm,int lastTerm,int commonDiff){

	int i;
	long long sum=0;
	for(i=firstTerm;i<=lastTerm;i+=commonDiff){
		sum+=i*i;

	}
	return sum;
}

int sumOfAP(int firstTerm, int commondiff, int noOfTerms){

	return ((2*firstTerm+commondiff*(noOfTerms-1))*noOfTerms)/2;
}
int main(void) {


	printf("%lld",2*SumOfSquares(3,1001,2)+2*SumOfSquares(2,1000,2)-sumOfAP(2,2,500)-sumOfAP(1,2,500)+500+1);
	return EXIT_SUCCESS;
}
