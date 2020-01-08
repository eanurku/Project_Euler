/*
 ============================================================================
 Name        : Project-Euler-74.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10000000 //max value =6* fact(9)
#define CHAIN_SIZE_VALUE 60

int getfactorial(int number){
int factorial=1,i;
for(i=1;i<=number;i++){
	factorial*=i;
}

	return factorial;
}
int getSumOfFactorialofDigits(int number){

	int factorialArray[]={1,1,2,6,24,120,720,5040,40320,362880};
	int digit;
	int sum=0;

    while(number){

	digit=number%10;
	sum+=factorialArray[digit];
	number/=10;
}

	return sum;
}

int main(void) {


	int *array=(int *)malloc(MAX *sizeof(int));

	int factorialSum,chainSize,saveNum;
	//printf("%d",array[199]);

	int number,count=0;


	for (number = 1; number < 1000000; number++) {


		if(number==getSumOfFactorialofDigits(number)){
			continue;
		}
		//memset(array, 0, MAX * sizeof(int));
		array=(int *)malloc(MAX *sizeof(int));
		saveNum = number;
		chainSize = 1;
		array[number] = 1;
		while (chainSize<61) {

			factorialSum = getSumOfFactorialofDigits(number);
			array[factorialSum]++;
			if (array[factorialSum] > 1) {
				break;
			}
			chainSize++;
			number=factorialSum;
		}
		number=saveNum;
		if(number!=factorialSum){
			//printf("%d\n",number);
			if(chainSize==CHAIN_SIZE_VALUE){

				count++;

			}
		}

		free(array);
		array=NULL;
}

printf("%d",count);

	return EXIT_SUCCESS;
}
