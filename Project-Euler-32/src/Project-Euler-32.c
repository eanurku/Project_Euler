/*
 ============================================================================
 Name        : Project-Euler-32.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define FINAL_ARRAY_SIZE 30

int getDigitsCount(int number) {

	int count = 0;

	if(number==0){
		return 1;
	}
	while (number) {
		number /= 10;
		count++;
	}

	return count;
}

int pandigitalArrayCheck(int *pandigitalArray,int numberOfDigits){




	int i;
	/*for(i=0;i<=9;i++){
    printf("%d,",pandigitalArray[i]);
	}*/

	for(i=1;i<=numberOfDigits;i++){

		if(pandigitalArray[i]!=1){
			return 0;
		}
	}

	return 1;
}
int isPandigital(long long  number){

	int digit,numberOfDigits,i;
	int pandigitalArray[10]={0};
    numberOfDigits=getDigitsCount(number);

    if(numberOfDigits>9){
    	return 0;
    }

	while(number){
		digit=number%10;
		pandigitalArray[digit]++;
		number/=10;
	}

	if(pandigitalArrayCheck(pandigitalArray,numberOfDigits)){
		return 1;
	}

	return 0;
}

void concatenateAllNumbers(int *finalNumber, int *finalNumberSize,
		unsigned long long product, unsigned long long multiplier,
		unsigned long long multiplicand) {

	while (multiplier) {

		finalNumber[(*finalNumberSize)++] = multiplier % 10;
		multiplier /= 10;
	}

	while (multiplicand) {

		finalNumber[(*finalNumberSize)++] = multiplicand % 10;
		multiplicand /= 10;
	}
	while (product) {

		finalNumber[(*finalNumberSize)++] = product % 10;
		product /= 10;
	}

	/*int i;
	for(i=0;i<*finalNumberSize;i++){

		printf("%d",finalNumber[i]);
	}
*/
}

int oneToNinePandigitalCheckForNumberArray(int *NumberArray,int *NumberArraySize){

int i;
int pandigitalArray[10]={0};
if((*NumberArraySize)!=9){
	return 0;
}

for(i=0;i<*NumberArraySize;i++){

	pandigitalArray[NumberArray[i]]++;
}

/*
printf("\n");
for(i=0;i<=9;i++){

		printf("%d,",pandigitalArray[i]);
	}
*/
if(pandigitalArrayCheck(pandigitalArray,9)){
return 1;
}



	return 0;
}
int main(void) {

unsigned long long product,multiplier,multiplicand,sum=0,found;

int *finalNumber=(int *)malloc(sizeof(int)*FINAL_ARRAY_SIZE);
int finalNumberSize=0;

for(product=1;product<=99999;product++){
found=0;
	for(multiplier=1;multiplier<=99999;multiplier++){
		for(multiplicand=+1;multiplicand*multiplier<=product ;multiplicand++){
			if(multiplier*multiplicand==product){

				finalNumberSize=0;
				concatenateAllNumbers(finalNumber,&finalNumberSize,product,multiplier,multiplicand);

				if(oneToNinePandigitalCheckForNumberArray(finalNumber,&finalNumberSize)){
					sum+=product;
					printf("\n%llu",sum);
					found=1;break;
				}

				}
			}
		if(found){
			break;
		}
	}
}





printf("\n%llu",sum);
	return EXIT_SUCCESS;
}
