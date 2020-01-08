/*
 ============================================================================
 Name        : project-Eeuler-39.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>



int GCD(int big,int small){
	if(big<small)
		GCD(small,big);
	if(small==0)
		return big;
	return(GCD(small,big%small));
}

int main(void) {


int perimter,savep;
int count,maxCount=0;
int  a,b,c,m, mLimit, halfRequiredSum, prodKD, k,n,gcdOfabc;


for(perimter=2;perimter<=1000;perimter+=2){

    count=0;
	halfRequiredSum = perimter / 2;

	for (m = 1; 2*m*m <=perimter; m++) {
		if (halfRequiredSum % m == 0) {
			prodKD = halfRequiredSum / m;
		}
		else {
			continue;
		}

		for (k = ((m % 2 == 0) ? m + 1 : m + 2); k < 2 * m && k <= prodKD; k +=2) {
			if (prodKD % k == 0 && GCD(m, k) == 1) {
                n=k-m;
                gcdOfabc=prodKD/k;
                count++;
/*					a = (m * m - n * n) * gcdOfabc;
					b = 2 * m * n * gcdOfabc;
					c = (m * m + n * n) * gcdOfabc;

					printf("a=%d,b=%d,c=%d,a*b*c=%lld", a, b, c, a * b * c);*/




			}
		}

	}

	if(count>=maxCount){
		maxCount=count;
		savep=perimter;
	}

}





printf("%d,%d",savep,maxCount);



	return EXIT_SUCCESS;
}
