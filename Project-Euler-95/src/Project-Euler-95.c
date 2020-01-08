/*
 ============================================================================
 Name        : Project-Euler-95.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getProperDivisorsSumFast(int number){
	int sum=0,i;
	int numberSQRT=sqrt(number);

	for(i=2;i*i<number;i++){

		if(number%i==0){
			sum+=i;
			sum+=(number/i);
		}

	}
	if( (number!=1) && (numberSQRT*numberSQRT == number)){
		sum+=numberSQRT;
	}
	return sum+1;
}

int is_perfect_number(int number){

	return (number==getProperDivisorsSumFast(number));
}
int main(void) {

	long long chainSize, saveNum, properDivSum, maxChainSize = 0,
			smallestElementofChain = 0,number;


	int *array=(int *)calloc(1000000,sizeof(int));

	for (number = 2; number <100000; number++) {
		if (is_perfect_number(number)) {
			continue;
		}
		saveNum = number;
		chainSize = 0;
		memset((void *)array,0,1000000*sizeof(int));
		array[number]=1;
		//printf("number=%d\n", number);
		while (1) {


			properDivSum = getProperDivisorsSumFast(number);

			if(properDivSum<1000000)
				array[properDivSum]++;

			//printf("%d\n", properDivSum);
			if (properDivSum == 1 || properDivSum >= 1000000||(array[properDivSum]>1)||is_perfect_number(properDivSum)) {

				break;
			}
			chainSize++;

			number = properDivSum;
		}

		if (saveNum == properDivSum) {


		//	printf("saveNum=%d\n", saveNum);
			if (chainSize > maxChainSize) {
				maxChainSize = chainSize;
				smallestElementofChain = saveNum;
			}

		}
		number = saveNum;
		//printf("number=%d\n", number);
	}
	printf("smallestElementofChain=%d", smallestElementofChain);

	return EXIT_SUCCESS;
}
