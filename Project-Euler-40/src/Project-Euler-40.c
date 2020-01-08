/*
 ============================================================================
 Name        : Project-Euler-40.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

int number,i,tmp;

int *numArray=(int *)calloc(10,sizeof(int));
int numArraySize=0;

int *finalArray=(int *)calloc(1000009,sizeof(int));
int finalArraySize=0;

    number=1;
	while(finalArraySize<=1000000){


		numArraySize=0;
		tmp=number;
		while(tmp){

			numArray[numArraySize++]=tmp%10;
			tmp/=10;
		}

		for(i=0;i<numArraySize;i++){

			finalArray[finalArraySize++]=numArray[numArraySize-1-i];
		}





		number++;
	}

/*	printf("\n");
	for(i=0;i<20;i++){

	   printf("%d,",finalArray[i]);
	}*/

	printf("%d",finalArray[0]*finalArray[9]*finalArray[99]*finalArray[999]*finalArray[9999]*finalArray[99999]*finalArray[999999]);
	return EXIT_SUCCESS;
}
