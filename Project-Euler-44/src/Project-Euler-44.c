/*
 ============================================================================
 Name        : Project-Euler-44.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int isPentagonal(long long x)
{  double p=(1+sqrt(1+24*x))/6;
      long long q=p;
      double t=q;
      if(t==p)
       return 1;
       else
        return 0;

}

int main(void) {


	int n,pentagonalNumber,i,j,minDiff=99999999;
	int *pentagonalNumberArray=(int *)malloc(sizeof(int)*10000);
	int pentagonalNumberArraySize=0;

	for(n=1;n>0;n++){
		pentagonalNumber=(n*(3*n-1))/2;
		if(pentagonalNumber<100000000){
			pentagonalNumberArray[pentagonalNumberArraySize++]=pentagonalNumber;
		}
		else {
			break;
		}

	}

for(i=0;i<pentagonalNumberArraySize;i++){
	for(j=0;j<=i;j++)//loop through in increasing order of sum and diff
		if(isPentagonal(pentagonalNumberArray[i]+pentagonalNumberArray[j]) && isPentagonal(abs(pentagonalNumberArray[j]-pentagonalNumberArray[i]))){
			minDiff=pentagonalNumberArray[i]-pentagonalNumberArray[j];
	        printf("%d\n",minDiff);
		}


}


printf("%d",minDiff);
	return EXIT_SUCCESS;
}
