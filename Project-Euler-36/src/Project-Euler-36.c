/*
 ============================================================================
 Name        : Project-Euler-36.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE_BINARY_ARRAY   25  //decide limit

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
long long isPalindromeInDecimalForm(long long number){

	long long originalNumber=number;
	long long reverseNumber=reverseOfNumber(number);

return (originalNumber==reverseNumber?1:0);
}

void reverseOfArray(int *binaryNumberArray,int binaryNumberArraySize){
int i,j,tmp;
for(i=0,j=binaryNumberArraySize-1;i<j;i++,j--){
	tmp=binaryNumberArray[i];
	binaryNumberArray[i]=binaryNumberArray[j];
	binaryNumberArray[j]=tmp;
}

}
void convertDecimalNumberToBinaryForm(int number,int *binaryNumberArray,int *binaryNumberArraySize){
//if number is zero then binaryNumberArraySize=0
int binaryDigit,i;
while(number>1){
	binaryDigit=number%2;
	binaryNumberArray[(*binaryNumberArraySize)++]=binaryDigit;
	number/=2;
}
if(number==1){
	binaryNumberArray[(*binaryNumberArraySize)++]=number;
}
//reverse the array
//reverseOfArray(binaryNumberArray,*binaryNumberArraySize);

}
int isPalindromeInBinaryForm(int *binaryNumberArray,int binaryNumberArraySize){

	int i,j;
	for(i=0,j=binaryNumberArraySize-1;i<j;i++,j--){
            if(binaryNumberArray[i]!=binaryNumberArray[j]){
                  return 0;
            }
	}


	return 1;
}
int main(void) {


long long sum=0;
int number,i;
int *binaryNumberArray=(int *)malloc(sizeof(int)*MAX_SIZE_BINARY_ARRAY);
int binaryNumberArraySize;

	for(number=1;number<1000000;number++){

		binaryNumberArraySize=0;
		convertDecimalNumberToBinaryForm(number,binaryNumberArray,&binaryNumberArraySize);

		if(isPalindromeInDecimalForm(number) && isPalindromeInBinaryForm(binaryNumberArray,binaryNumberArraySize)){
			printf("\nnumber=%d\n",number);
			for(i=0;i<binaryNumberArraySize;i++){
						printf("%d,",binaryNumberArray[i]);
					}
			sum+=number;
		}

	}

				printf("\nsum=%lld",sum);

	return EXIT_SUCCESS;
}
