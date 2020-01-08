/*
 ============================================================================
 Name        : Project-Euler-76.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int ways[101]={0};


int numbers,j,target=100;
ways[0]=1;
	for(numbers=1;numbers<=99;numbers++)
		for(j=numbers;j<=target;j++)
			ways[j]+=ways[j-numbers];

	printf("%d",ways[100]);

	return EXIT_SUCCESS;
}
