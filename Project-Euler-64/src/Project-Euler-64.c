/*
 ============================================================================
 Name        : Project-Euler-64.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int perfect_square_check(int z)
{  int x;
    x=pow(z,.5);
   if(x*x==z)
   return x;
   else
   return 0;
}

int main(void) {

int number_limit,numeratorOfFractionP,denominatoreQ,denominatorR,sqrtOfNumber,nonFractionalValue,period;

   int number=2, saveNumeratorOfFractionP,saveDenominatoreR,count=0;


while(number<=10000){
   if(perfect_square_check(number)==0){
	   sqrtOfNumber=sqrt(number);
	      //first step result A0,P/sqrt(Q)-R

	      numeratorOfFractionP=1,denominatoreQ=number,denominatorR=sqrtOfNumber;
	      saveNumeratorOfFractionP=numeratorOfFractionP,saveDenominatoreR=denominatorR;
	      period=0;

	      while(1){

	   	   //next step A1,P/sqrt(Q)-R
	   	   nonFractionalValue=(numeratorOfFractionP*(sqrt(denominatoreQ)+denominatorR))/(denominatoreQ-denominatorR*denominatorR);

	   	   numeratorOfFractionP=(denominatoreQ-denominatorR*denominatorR)/numeratorOfFractionP;
	   	   denominatorR=(nonFractionalValue*numeratorOfFractionP)-denominatorR;

	   	   if(saveDenominatoreR==denominatorR && saveNumeratorOfFractionP==numeratorOfFractionP){
	   		   period++;

	   		   break;
	   	   }
	   	   else{
	   		   period++;
	   	   }
	      }

          if(period%2)
	      count++;
   }

   number++;
}

printf("count=%d",count);
	return EXIT_SUCCESS;
}
