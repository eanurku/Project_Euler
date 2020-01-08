/*
 ============================================================================
 Name        : Project-Euler-4.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description :

A palindromic number reads the same both ways. The largest palindrome made from the
product of two 2-digit numbers is 9009 = 91 99.
Find the largest palindrome made from the product of two 3-digit numbers.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


long long reverseOfNumber(long long number){

	long long lastDigit;
	long long tmp=number;
	long long reverseNumber= 0;

	while(tmp){

		lastDigit=tmp%10;
		reverseNumber=reverseNumber*10+lastDigit;
		tmp=tmp/10;
	}

	return reverseNumber;
}
long long isPalindrome(long long number){

	long long originalNumber=number;
	long long reverseNumber=reverseOfNumber(number);

return (originalNumber==reverseNumber?1:0);
}

int main(void) {

	long long noOfDigits,biggestNumber,smallestNumber,outerNumber,innerNumber,biggestPalindrome=0;
	scanf("%lld",&noOfDigits);

	biggestNumber=pow(10,noOfDigits)-1;
	smallestNumber=pow(10,noOfDigits-1);

	for(outerNumber=biggestNumber;outerNumber>=smallestNumber;outerNumber--){
       for(innerNumber=outerNumber-1;innerNumber>=outerNumber;innerNumber--)

    	   if(isPalindrome(outerNumber*innerNumber) && biggestPalindrome<outerNumber*innerNumber){

    		   biggestPalindrome=outerNumber*innerNumber;
    		   smallestNumber=innerNumber-1;
    		   break;
    	   }

	}


   printf("%lld",biggestPalindrome);

	return EXIT_SUCCESS;
}
