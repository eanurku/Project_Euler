/*
 ============================================================================
 Name        : Project-Euler-27.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

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


int getCountOfPrimeNumbersForConsecutiveValueOfN(int a,int b){

	int n=0;
	int count=0;

	while((n*n+n*a+b)>=0 && isPrimeFast(n*n+n*a+b)){

		count++;
		n++;
	}

	return count;
}
int main(void) {

	clock_t t1, t2;
	t1 = clock();
	double run_time;
int a,b;
int count=0;

int maxA=-1000,maxB=-1000,maxN=0;

	for(a=-999;a<=999;a++){
		for(b=-999;b<=999;b++){

			count=getCountOfPrimeNumbersForConsecutiveValueOfN(a,b);
			if(count>=maxN){
				maxA=a;
				maxB=b;
				maxN=count;



			}

		}
	}


	printf("maxA=%d,maxB=%d,maxN=%d,maxproduct%d\n",maxA,maxB,maxN,maxA*maxB);
    //end
t2=clock();
run_time=(t2-t1)/(double)CLOCKS_PER_SEC;
printf("%lf",run_time);

	return EXIT_SUCCESS;
}
