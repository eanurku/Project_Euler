/*
 ============================================================================
 Name        : Project-Euler-79.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define ROWS 50
#define COLS 3


int searchArray(int digits[],int size,int first){

	int i;
	for(i=0;i<size;i++){
		if(digits[i]==first){
			return i;
		}
	}
}

int minofthree(){

}
updateOrder(int digits[],int size,int first,int second,int third){


	int firstIndex =searchArray(digits,size,first);
	int secondIndex=searchArray(digits,size,second);
	int thirdIndex=searchArray(digits,size,third);
	if(firstIndex<secondIndex){
		if(secondIndex<thirdIndex){
			digits[firstIndex]=first;
			digits[secondIndex]=second;
			digits[thirdIndex]=third;

		}else{

			if(firstIndex<thirdIndex){

				digits[firstIndex]=first;
				digits[thirdIndex]=second;
				digits[secondIndex]=third;
			}else{
				digits[thirdIndex]=first;
				digits[firstIndex]=second;
				digits[secondIndex]=third;
			}

		}

	}else{
		if(secondIndex>thirdIndex){
			digits[thirdIndex]=first;
			digits[secondIndex]=second;
			digits[firstIndex]=third;
		}else {
			if(firstIndex<thirdIndex){
				digits[secondIndex]=first;
				digits[firstIndex]=second;
				digits[thirdIndex]=third;
			}else{
				digits[secondIndex]=first;
				digits[thirdIndex]=second;
				digits[firstIndex]=third;

			}
		}

	}

}

int main(void) {

    int digit,i,j,sizeDigits;
    int array[200]={0};
    int digits[10];

    int array2d[200][200];

	FILE *inpFile=fopen("/home/anurag/Desktop/CPROGG/PROJECT-EULER-linuxworkspace/Project-Euler-79/src/input.txt","r");

	if(inpFile==NULL){

		printf("some error happened");
	}

	i=0;j=0;
	while((digit=getc(inpFile))!=EOF){

		  if(digit!='\n'){
          array[digit-'0']=1;
          array2d[i][j++]=digit-'0';
		  }
		  else{
			  i++;
			  j=0;
		  }
	}

	j=0;
	for(i=0;i<200;i++){
		if(array[i])
		digits[j++]=i;
	}

	sizeDigits=j;
	for(j=0;j<sizeDigits;j++){

		printf("%d",digits[j]);
	}

	/*
	for(i=0;i<ROWS;i++){
		for(j=0;j<COLS;j++){
			printf("%d",array2d[i][j]);
		}
		printf("\n");
	}
*/

	for(i=0;i<ROWS;i++){
		updateOrder(digits,sizeDigits,array2d[i][0],array2d[i][1],array2d[i][2]);
	}
	printf("\n");
	for(j=0;j<sizeDigits;j++){

		printf("%d",digits[j]);
	}
	return EXIT_SUCCESS;
}
