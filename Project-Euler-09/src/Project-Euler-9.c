/*
 ============================================================================
 Name        : Project-Euler-9.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description :
 A Pythagorean triplet is a set of three natural numbers, a<b<c, for which,
 a^2 + b^2 = c^2
 For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int perfect_square_check(int z) {
	int x;
	x = pow(z, .5);
	if (x * x == z)
		return x;
	else
		return 0;
}

int GCD(int big,int small){
	if(big<small)
		GCD(small,big);
	if(small==0)
		return big;
	return(GCD(small,big%small));
}


int main(void) {

	int requiredSum, a, b, c, found = 0;

	scanf("%d", &requiredSum);
//implementation 1
/*

	for (a = 1; a < requiredSum; a++) {
		for (b = a + 1; b < requiredSum; b++) {
			if (c = perfect_square_check(a * a + b * b)) {
				if ((a + b + c) == requiredSum) {
					found = 1;
					break;
				}
			}
		}
		if (found) {
			break;
		}
	}
*/

//implementation 2
/*

	for (a = 4; a < requiredSum / 3; a++) {
		for (b = a + 1; b < (requiredSum - a) / 2; b++) {
			c = requiredSum - a - b;
			if (c * c == a * a + b * b) {
				if (a + b + c == requiredSum) {
					found = 1;
					break;
				}
			}
		}
		if (found) {
			break;
		}
	}
*/
//implementation 3
// primitive triplet (a,b,c) can be represented as
//a=m^2-n^2,b=2mn,c=m^2+n^2 ;gcd(m,n)=1 and exactly one out of m,n is even
//s=2*m*(m+n)*d ->s/2=m*k*d
//k=odd as exactly one out of m,n is even
//k<2m,k<s/2m

int  m, mLimit, halfRequiredSum, prodKD, k,n,gcdOfabc;

	halfRequiredSum = requiredSum / 2;

	mLimit = sqrt(halfRequiredSum);

	for (m = 4; m <=mLimit; m++) {
		if (halfRequiredSum % m == 0) {
			prodKD = halfRequiredSum / m;
		}else {
			continue;
		}

		for (k = ((m % 2 == 0) ? m + 1 : m + 2); k < 2 * m && k <= prodKD; k +=2) {
			if (prodKD % k == 0 && GCD(m, k) == 1) {
                n=k-m;
                gcdOfabc=prodKD/k;
                found=1;
                break;


			}
		}
		if(found){
			break;
		}

	}

	a= (m*m-n*n)*gcdOfabc;
	b=2*m*n*gcdOfabc;
	c= (m*m+n*n)*gcdOfabc;


	printf("a=%d,b=%d,c=%d,a*b*c=%lld",a,b,c, a * b * c);

	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
