/*
 ============================================================================
 Name        : Project-Euler-53.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int isnCrGreaterThanOneMillion(int n,int r){

	int number,indexR=1,prod=1;
	for(number=n,indexR=1;number>=n-r+1 && indexR<=r;number--,indexR++){
         prod*=number;
         prod/=indexR;
         if(prod>1000000){
           return 1;
         }
	}

	return 0;
}
int main(void) {

	int n,r,count=0;

	for(n=1;n<=100;n++){
		for(r=1;r<=n;r++){

			if(isnCrGreaterThanOneMillion(n,r)){

				count+=(n-r)-r+1;

				break;
			}
		}

	}

	printf("count=%d\n",count);
	return EXIT_SUCCESS;
}
