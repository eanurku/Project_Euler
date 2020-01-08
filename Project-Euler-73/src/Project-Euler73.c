/*
 ============================================================================
 Name        : Project-Euler72.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#define MAXLIMIT 12000
struct fraction{
	int num;
	int den;

};


int compare(const void *number1, const void *number2) {

	int num1 = ((struct fraction *) number1)->num;
	int num2 = ((struct fraction *) number2)->num;

	int den1 = ((struct fraction *) number1)->den;
	int den2 = ((struct fraction *) number2)->den;

	if(num1*den2<num2*den1) {
		return -1;
	} else if(num1 * den2 > num2 * den1)
	{
		return 1;

	}

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

	int d,n,index=0,i,start,end;
	struct fraction *fractionArray=(struct fraction *)malloc(MAXLIMIT*MAXLIMIT*sizeof(struct fraction));

/*
	int count=0;
	for(d=5;d<=MAXLIMIT;d++){
		for(n=d/3+1;n<=(d-1)/2;n++){
			if(GCD(n,d)==1){
				count++;
			}

		}
	}
	printf("count=%d",count);
*/

	for (d = 1; d <= MAXLIMIT; d++) {
		for (n = 1; n < d; n++) {
			if (GCD(n, d) == 1) {
				fractionArray[index].num = n;
				fractionArray[index].den = d;
				index++;
			}
		}
	}

	qsort(fractionArray, index, sizeof(struct fraction), compare);

	for (i = 0; i < index; i++) {

		if (fractionArray[i].num == 1 && fractionArray[i].den == 3) {
			start = i;
			printf("%d/%d ", fractionArray[i].num, fractionArray[i].den);
		}
		if (fractionArray[i].num == 1 && fractionArray[i].den == 2) {
			end = i;
			printf("%d/%d ", fractionArray[i].num, fractionArray[i].den);
			break;
		}
	}

	printf("count=%d", end - start - 1);

	return EXIT_SUCCESS;
}
