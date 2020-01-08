/*
 ============================================================================
 Name        : Project-Euler-38.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define NINE 9


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

int compareArray(int *maxArray,int maxArraySize,int *numArray,int numArraySize){

int i;
if(maxArraySize>numArraySize){
	return 0;
}
else if(maxArraySize<numArraySize){
	return 1;
}

for(i=0;i<maxArraySize;i++){
if(maxArray[i]>numArray[i]){
	return 0;
}else if(maxArray[i]<numArray[i]){
	return 1;
}
}

return 1;
}

int main(void) {

int number,multiplier,tmp,maxNumber=0,i,revTmp;
int *numArray=(int *)calloc(15,sizeof(int));
int numArraySize=0;
int *maxArray=(int *)calloc(15,sizeof(int));
int maxArraySize=0;

int *unorderedNumArray=(int *)calloc(15,sizeof(int));
int unorderedNumArraySize=0;

	for(number=1;number<=99999;number++){

	   numArraySize=0;
	   unorderedNumArraySize=0;
       multiplier=1;

		while (unorderedNumArraySize<=NINE) {
			tmp = number * multiplier;

			revTmp=reverseOfNumber(tmp);

			while (revTmp) {
				numArray[numArraySize++] = revTmp % 10;
				revTmp /= 10;

			}

			while (tmp) {
				unorderedNumArray[unorderedNumArraySize++] = tmp % 10;
				tmp /= 10;

			}


			if(unorderedNumArraySize==NINE && multiplier!=1){
				break;

			}
			multiplier++;
		}
		if(oneToNinePandigitalCheckForNumberArray(unorderedNumArray,&unorderedNumArraySize) && compareArray(maxArray,maxArraySize,numArray,numArraySize)){

			for(i=0;i<numArraySize;i++){
				maxArray[i]=numArray[i];
			}
			maxArraySize=numArraySize;





		}

	}


	printf("\n");
	for (i = 0; i < maxArraySize; i++) {
	     printf("%d", maxArray[i]);
    }
	printf("\nnumber=%d",number);


	return EXIT_SUCCESS;
}
