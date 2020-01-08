/*
 ============================================================================
 Name        : Project-Euler-7.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>



int isPrimeFast(long long number) {

	long long  factor,r;
	if(number==1){
		return 0;
	}else if(number<4){
		return 1;
	}else if(number%2==0){
        return 0;
	}else if(number%3==0){
		return 0;
	}

	r=sqrt(number);
	for(factor=5;factor<=r;factor+=6)
         if((number%factor==0)||(number%(factor+2)==0)){
        	 return 0;
         }

	return 1;
}

int isPrimeBasicFast(long long number) {
	long long i;
	int r=sqrt(number);
	for (i = 2; i <= r; i++) {
		if (number % i ==0 ) {
			return 0;
		}
	}
	return 1;
}

int main(void) {

long long i;
int primeAtPosition;
int count=0;

scanf("%d",&primeAtPosition);

for(i=2;i>0 ;i++){



	if(isPrimeFast(i)){
        count++;
		if(count==primeAtPosition){

			break;
		}
	}


}

printf("%dth prime= %lld",primeAtPosition,i);


	return EXIT_SUCCESS;
}
