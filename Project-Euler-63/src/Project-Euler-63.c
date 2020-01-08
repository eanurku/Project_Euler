/*
 ============================================================================
 Name        : Project-Euler-63.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int getDigitsCount(long long number) { //number=0 return count=0

	int count = 0;
	while (number) {
		number /= 10;
		count++;
	}

	return count;
}

int isNDigitNumberNthPowerOfAnyNumber(long long number){


	int digitsCount=getDigitsCount(number);
	long long i,tmp;

	for(i=1;(tmp=pow(i,digitsCount))<=number;i++){

		if(tmp==number){
           return 1;
		}
	}

return 0;
}
int main(void) {
/*
long long number,count=0;

	for(number=1;number<=99;number++){

		if(isNDigitNumberNthPowerOfAnyNumber(number)){
			count++;

		}

	}*/

	//9^n<10^n-1 fin n sunch that  digits number cant be written as nth power of 9
		//similarly for 8,7
		int i,count;
		for(i=9;i>=1;i--){

			count+=(1/(1-log10(i)));


		}


	printf("%lld",count);

	return EXIT_SUCCESS;
}
