/*
 ============================================================================
 Name        : Project-Euler-94.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 It is easily proved that no equilateral triangle exists with integral length sides and integral area. However, the almost equilateral triangle 5-5-6 has
 an area of 12 square units.We shall define an almost equilateral triangle to be a triangle for which two sides are equal and the third differs by no more than one unit.
 Find the sum of the perimeters of all almost equilateral triangles with integral side lengths and area and whose perimeters do not exceed one billion (1,000,000,000).
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define PERIMETER_LIMIT 100000000



int perfect_square_check(long long z)
{  long long  x;
    x=pow(z,.5);
   if(x*x==z)
   return 1;
   else
   return 0;
}

int isperfectSquare(long long number)
{  long double sqrtNumber=sqrt(number);
      long long tmpNumber=sqrtNumber;

      double tmp=tmpNumber;
      if(tmp==sqrtNumber)
       return 1;
       else
        return 0;

}






int isProductDivisibleByFour(long long num1, long long num2) {

	if (num1 % 2 == 0) {
		if (num2 % 2 == 0) {
			return 1;
		} else {
			if (num1 % 4 == 0) {
				return 1;
			} else
				return 0;

		}
	} else {

		if (num2 % 4 == 0) {
			return 1;
		} else
			return 0;

	}


	if(num2%2==0){
		if(num1%2==0){
			return 1;
		}
		else {
			if(num2%4==0){
				return 1;
			}
			else
				return 0;

		}
	}
	else {
		if(num1%4==0){
			return 1;
		}
		else
			return 0;
	}

}
int isAreaInteger(long long  equalSide,long long  otherSide){

long long  value =(2*equalSide-otherSide)*(2*equalSide+otherSide);

long long  sqrtValue;
//long long  sqrtValue=sqrt(value);
if(value && perfect_square_check(value)){
	sqrtValue=sqrt(value);
	if(isProductDivisibleByFour(sqrtValue,otherSide)){
		return 1;
	}
}

return 0;
}
int main(void) {

	long long  equalSide,otherSide,limit=(PERIMETER_LIMIT+1)/3;
	long long sum=0,perimeter=0;

	for (equalSide = 2; equalSide <=limit ; equalSide++) {

		otherSide = equalSide - 1;
		if ((abs(equalSide - otherSide) == 1)
				&& isAreaInteger(equalSide, otherSide)) {
			sum += (2 * equalSide + otherSide);
			printf("%lld,%lld,%lld\n", equalSide, equalSide, otherSide);
		}

		otherSide = equalSide + 1;
		if ((abs(equalSide - otherSide) == 1)
				&& isAreaInteger(equalSide, otherSide)) {
			sum += (2 * equalSide + otherSide);
			printf("%lld,%lld,%lld\n", equalSide, equalSide, otherSide);
		}

}

	printf("sum=%lld\n", sum);

	return EXIT_SUCCESS;
}
