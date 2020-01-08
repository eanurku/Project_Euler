/*
 ============================================================================
 Name        : Project-Euler-52.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//ishavingSameDigits ~ isPermutationOfEachOther
int ishavingSameDigits(long long  num1,long long num2){

   int i;
   int num1DigitsArray[10]={0};
   int num2DigitsArray[10]={0};

   while(num1){
	   num1DigitsArray[num1%10]++;
	   num1/=10;
   }

   while(num2){
  	   num2DigitsArray[num2%10]++;
  	   num2/=10;
     }

   for(i=0;i<=9;i++){

	   if(num1DigitsArray[i]!=num2DigitsArray[i]){
		   return 0;
	   }
   }
	return 1;
}
int isMultipleshaveSameDigitsExactly(long long number){


	if(ishavingSameDigits(number,2*number)&& ishavingSameDigits(number,3*number) && ishavingSameDigits(number,4*number)
			&& ishavingSameDigits(number,5*number)&& ishavingSameDigits(number,6*number)){

		return 1;

	}


	return 0;
}
int main(void) {

	long long number;



for(number=1;number>0;number++){

if(isMultipleshaveSameDigitsExactly(number)){

	printf("%lld\n",number);
	printf("%lld\n",number*2);
	printf("%lld\n",number*3);
	printf("%lld\n",number*4);
	printf("%lld\n",number*5);
	printf("%lld\n",number*6);

	break;
}
}








	return EXIT_SUCCESS;
}
