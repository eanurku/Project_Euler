/*
 ============================================================================
 Name        : Project-Euler-112.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int isIncreasingNumber(int num){

	int maxDigit=10;
	int digit;
	while(num){
		digit=num%10;
		if(digit<=maxDigit){
			maxDigit=digit;
		}else{
			return 0;
		}
		num=num/10;
	}

	return 1;
}

int isDecreasingNumber(int num){

	int minDigit=-1;
	int digit;
	while(num){
		digit=num%10;
		if(digit>=minDigit){
			minDigit=digit;
		}else{
			return 0;
		}
		num=num/10;
	}
	return 1;
}

int main(void) {

	int num,count=0,percent;
	for(num=100;;num++){
		if(!isIncreasingNumber(num) && !isDecreasingNumber(num)){
			count++;
			percent=(count*100)/(num);
			if(percent>=99){
				break;
			}
		}
	}
	printf("num=%d",num);
	return EXIT_SUCCESS;
}
