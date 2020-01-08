/*
 ============================================================================
 Name        : Project-Euler-92.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int sum_of_square_of_digits_1_or_89(int number){
int digit,tmpNumber;

	while(1){

		if(number == 89 || number==1){
			return number;
		}
		tmpNumber=0;
		while(number>0){

			digit=number%10;
			number/=10;
			tmpNumber+=digit*digit;
		}

		number=tmpNumber;


	}


}
int main(void) {

	int number = 1, count = 0, result;

	while (number <= 10000000) {

		result = sum_of_square_of_digits_1_or_89(number);

		if (result>1) {
			count++;

		}

		number++;
	}

	printf("count=%d", count);
	return EXIT_SUCCESS;
}
