/*
 ============================================================================
 Name        : Project-Euler-14.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description :

The following iterative sequence is defined for the set of positive integers:
n n/2 (n is even) n 3n + 1 (n is odd)
Using the rule above and starting with 13, we generate the following sequence:
13 40 20 10 5 16 8 4 2 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
Which starting number, under one million, produces the longest chain?
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

long long getCollatzCount(long long number){
long long count=0;

    if(number==1) return 4;

	while (number != 1) {

		while (number % 2 == 0) {
			number /= 2;
			count++;
		}
		if (number % 2 && number != 1) {
			number = number * 3 + 1;
			count++;
		}
	}
return count+1;
}
int main(void) {

	long long number,count,maxCount=0,saveNumber=0;

	for(number=1;number<=1000000;number++){

		count=getCollatzCount(number);

		if(count>maxCount){
			saveNumber=number;
			maxCount=count;
		}

	}

	printf("number=%lld,maxCount=%lld",saveNumber,maxCount);
	return EXIT_SUCCESS;
}
