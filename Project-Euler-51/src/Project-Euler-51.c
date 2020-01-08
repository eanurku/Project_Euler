/*
 ============================================================================
 Name        : test.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define SIZE 1000000
#define MAXLIMIT 10000000
#define CROSSED 1
#define DECIMALBASE 10
#define LIM 1000000

void generatePrimesUptoGivenNumber(int *primeArray, int *primeArraySize,int maxLimit) {

	int  crosserIndex, lastCrosserIndex, nextCrosserIndex, i;

	short *array=(short *)malloc(maxLimit*2);

	for (crosserIndex = 4; crosserIndex < maxLimit; crosserIndex += 2) {
		array[crosserIndex] = CROSSED;
	}

	lastCrosserIndex = sqrt(maxLimit)+1;

	for (crosserIndex = 3; crosserIndex <= lastCrosserIndex; crosserIndex += 2) {
		if (array[crosserIndex] != CROSSED) {

			for (nextCrosserIndex = crosserIndex * crosserIndex;
					nextCrosserIndex < maxLimit; nextCrosserIndex += (2 * crosserIndex)) {
				array[nextCrosserIndex] = CROSSED;
			}
		}

	}

	for (i = 2; i < maxLimit; i++) {
		if (array[i] != CROSSED) {

			primeArray[(*primeArraySize)] = i;
			*primeArraySize+=1;
		}
	}

}


int reverseOfNumber(int number){

	int lastDigit;
	int tmp=number;
	int reverseNumber= 0;

	while(tmp){

		lastDigit=tmp%10;
		reverseNumber=reverseNumber*10+lastDigit;
		tmp=tmp/10;
	}

	return reverseNumber;
}
int isSatisfyPrimePropertyForTwo(int a,int b,int *tmpCrossedPrimeArray){

int reverseA=reverseOfNumber(a);
int reverseB=reverseOfNumber(b);
int numberAB=a,numberBA=b;

while(reverseB){
	numberAB=numberAB*10+reverseB%10;
	reverseB=reverseB/10;
}
while(reverseA){
	numberBA=numberBA*10+reverseA%10;
	reverseA=reverseA/10;
}
if(tmpCrossedPrimeArray[numberAB]==1 && tmpCrossedPrimeArray[numberBA]==1){
	return 1;
}

return 0;

}
int isSatisfyPrimePropertyForThree(int a,int b,int c,int *tmp){

	if(isSatisfyPrimePropertyForTwo(a,b,tmp)&& isSatisfyPrimePropertyForTwo(a,c,tmp) && isSatisfyPrimePropertyForTwo(b,c,tmp)){
		return 1;
	}

	return 0;
}
int isSatisfyPrimePropertyForFour(int a,int b,int c,int d,int *tmp){

	if(isSatisfyPrimePropertyForThree(a,b,c,tmp) && isSatisfyPrimePropertyForTwo(a,d,tmp) && isSatisfyPrimePropertyForTwo(b,d,tmp) && isSatisfyPrimePropertyForTwo(c,d,tmp) ){
		return 1;
	}

	return 0;
}
int isSatisfyPrimePropertyForFive(int a,int b,int c,int d,int e,int *tmp){

	if(isSatisfyPrimePropertyForFour(a,b,c,d,tmp) && isSatisfyPrimePropertyForTwo(a,e,tmp) && isSatisfyPrimePropertyForTwo(b,e,tmp) && isSatisfyPrimePropertyForTwo(c,e,tmp)&& isSatisfyPrimePropertyForTwo(d,e,tmp)){
		return 1;
	}

	return 0;
}
int fun(int *tmpCrossedPrimeArray,int *primeSeq,int primeSeqSize){

	int i;
	for(i=0;i<primeSeqSize;i++){
		tmpCrossedPrimeArray[primeSeq[i]]=1;
	}
}
int main(void) {


	int i,j,k,l,m,sum,minSum=999999999;

	int *primeSeq=(int *)malloc(SIZE*sizeof(int));
	int primeSeqSize=0;

	generatePrimesUptoGivenNumber(primeSeq,&primeSeqSize,MAXLIMIT);

	int *tmpCrossedPrimeArray=(int *)calloc(MAXLIMIT,sizeof(int));

	//fun(tmpCrossedPrimeArray,primeSeq,primeSeqSize);
	for (i = 0; i < primeSeqSize; i++) {
		tmpCrossedPrimeArray[primeSeq[i]] = 1;
	}

	for(i=0; primeSeq[i]<LIM;i++)
		for(j=i+1;primeSeq[j]<LIM;j++)
			if(isSatisfyPrimePropertyForTwo(primeSeq[i],primeSeq[j],tmpCrossedPrimeArray))
			for(k=j+1;primeSeq[k]<LIM;k++)
				if(isSatisfyPrimePropertyForThree(primeSeq[i],primeSeq[j],primeSeq[k],tmpCrossedPrimeArray))
				for(l=k+1;primeSeq[l]<LIM;l++)
					if(isSatisfyPrimePropertyForFour(primeSeq[i],primeSeq[j],primeSeq[k],primeSeq[l],tmpCrossedPrimeArray))
						for(m=l+1;primeSeq[m]<LIM;m++){
							printf("i=%d,j=%d,k=%d,l=%d,m=%d,value=%d\n",i,j,k,l,primeSeq[m],isSatisfyPrimePropertyForFive(primeSeq[i],primeSeq[j],primeSeq[k],primeSeq[l],primeSeq[m],tmpCrossedPrimeArray));
							if(isSatisfyPrimePropertyForFive(primeSeq[i],primeSeq[j],primeSeq[k],primeSeq[l],primeSeq[m],tmpCrossedPrimeArray)==1){
								sum=primeSeq[i]+primeSeq[j]+primeSeq[k]+primeSeq[l]+primeSeq[m];
								if(sum<minSum){
									minSum=sum;
								}
							}
						}

	//printf("minsum=%d\n",isSatisfyPrimePropertyForFour(primeSeq[1],primeSeq[11],primeSeq[18],primeSeq[351],tmpCrossedPrimeArray));
	printf("minsum=%d\n",minSum);


	return EXIT_SUCCESS;
 }
