/*
 ============================================================================
 Name        : project-Euler-34.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int getfactorial(int number){
int factorial=1,i;
for(i=1;i<=number;i++){
	factorial*=i;
}

	return factorial;
}
long long getSumOfFactorialofDigits(long long number){

	int digit;
	long long sum=0;

    while(number){

	digit=number%10;
	sum+=getfactorial(digit);
	number/=10;
}

	return sum;
}
int isCuriousNumber(long long number){

	long long sum;

	sum=getSumOfFactorialofDigits(number);

	if(sum==number){
		return 1;
	}

	return 0;
}
int main(void) {

long long number=10,sum=0;
//number <= 7 digits numbers
	while(number>0 && number< 10000000){

		if(isCuriousNumber(number)){
			sum+=number;
			fprintf(stdout,"\n%lld",sum);
		}
		number++;
	}













	return EXIT_SUCCESS;
}
