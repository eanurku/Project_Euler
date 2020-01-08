/*
 ============================================================================
 Name        : Project-Euler-30.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int isSumOfFifthpowerOfeachDigits(long long number){

	long long tmp=number,sum=0;
	int digit;

	while(tmp && sum<number){
		digit=tmp%10;
		tmp=tmp/10;
		sum+=digit*digit*digit*digit*digit;
	}

	if(sum==number && !tmp){
		return 1;
	}

	return 0;
}
int main(void) {


	long long number=2;
	long long sum=0;
while(number>0 && number<1000000){

	if(isSumOfFifthpowerOfeachDigits(number)){

		sum+=number;
		printf("sum=%lld\n",sum);
	}


	number++;
}
	return EXIT_SUCCESS;
}
