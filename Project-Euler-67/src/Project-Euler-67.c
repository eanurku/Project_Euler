/*
 ============================================================================
 Name        : Project-Euler-67.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
int main(void) {
	int i,j,sum,maxSum=0,number;

	int array[100][100]={0};




    FILE *inputFile=fopen("/home/anurag/Desktop/CPROGG/PROJECT-EULER-linuxworkspace/Project-Euler-67/src/input.txt","r");


	for (i = 1; i <= SIZE; i++) {
		for (j = 0; j < i; j++) {
			fscanf(inputFile, "%d", &number);
			array[i-1][j]=number;
		}
	}

/*	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			printf("%d ",array[i][j]);
		}
		printf("\n");
	}*/

/*		int array[4][4]={{3,0,0,0},
				        {7,4,0,0},
						{2,4,6,0},
						{8,5,9,3}};*/

		for(i=1;i<SIZE;i++){
			for(j=0;j<=i;j++){
				if(j==0){
					array[i][j]+=array[i-1][j];
				}else{
					if(array[i][j]+array[i-1][j]>array[i][j]+array[i-1][j-1])
						array[i][j]+=array[i-1][j];
					else
						array[i][j]+=array[i-1][j-1];
				}

			}

		}

		for(j=0;j<SIZE;j++){
			if(array[SIZE-1][j]>maxSum){
						maxSum=array[SIZE-1][j];
		}
		}
			printf("max sum=%d",maxSum);
	return EXIT_SUCCESS;
}
