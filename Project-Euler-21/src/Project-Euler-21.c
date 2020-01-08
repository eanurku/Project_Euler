/*
 ============================================================================
 Name        : Project-Euler-21.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int getProperDivisorsSumFast(int number){
	int sum=0,i;
	int numberSQRT=sqrt(number);

	for(i=2;i*i<number;i++){

		if(number%i==0){
			sum+=i;
			sum+=(number/i);
		}

	}
	if((number!=1) && (numberSQRT*numberSQRT == number)){
		sum+=numberSQRT;
	}
	return sum+1;
}
int getProperDivisorsSum(int number){

	int i,sum=0;

	for(i=1;i<number;i++){
		if(number%i==0)
		sum+=i;
	}

	return sum;
}
int havingAmicablePair(int number) {

	int properDivSum, otherProperDivSum;

	properDivSum = getProperDivisorsSumFast(number);

	if (number != properDivSum) {
		otherProperDivSum = getProperDivisorsSumFast(properDivSum);
		if(number==otherProperDivSum)
			return 1;
	}

return 0;
}
int main(void) {

int i, sum = 0;

for (i = 1; i <= 10000; i++) {

	if (havingAmicablePair(i)) {
		sum += i;
	}
}

printf("sum=%d",sum);

printf("test-%d",getProperDivisorsSumFast(20));
return EXIT_SUCCESS;
}
