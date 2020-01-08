/*
 ============================================================================
 Name        : Project-Euler-82.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int minOfThree(int a, int b, int c) {

	if (a < b) {
		if (a < c) {
			return a;
		} else
			return c;
	} else {
		if (b < c) {
			return b;
		} else
			return c;

	}

}
int main(void) {

	int array[100][100];
	int i,j,num,minSum=999999;

	FILE * inputFile=fopen("/home/anurag/Desktop/CPROGG/PROJECT-EULER-linuxworkspace/Project-Euler-82/src/input.txt","r");
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			fscanf(inputFile,"%d",&num);
			array[i][j]=num;
		}
	}

	for(j=0;j<SIZE;j++){
		for(i=0;i<SIZE;i++){
			if(i==0 && j==0){
				array[i][j]+=array[i+1][j];

			}else if(i==SIZE-1 && j==0){
				array[i][j]+=array[i-1][j];
			}else if(i==0){
				if(array[i][j]+array[i][j-1]<array[i][j]+array[i+1][j])
					array[i][j]+=array[i][j-1];
				else
					array[i][j]+=array[i+1][j];
			}else if(j==0){
				if(array[i][j]+array[i-1][j]<array[i][j]+array[i+1][j])
					array[i][j]+=array[i-1][j];
				else
					array[i][j]+=array[i+1][j];
			}else if(i==SIZE-1){
				if(array[i][j]+array[i-1][j]<array[i][j]+array[i][j-1])
					array[i][j]+=array[i-1][j];
				else
					array[i][j]+=array[i][j-1];
			}else{

				array[i][j]=minOfThree(array[i][j]+array[i-1][j],array[i][j]+array[i+1][j],array[i][j]+array[i][j-1]);

			}

		}
	}
/*	for(i=0;i<SIZE;i++){

		if(minSum>array[i][SIZE-1]){
			minSum=array[i][SIZE-1];
			printf("%d ",minSum);
		}
	}*/
			for(i=0;i<SIZE;i++){
				for(j=0;j<SIZE;j++){
					printf("%d ",array[i][j]);

				}
				printf("\n");
			}

/*	printf("%d",minSum);*/
	return EXIT_SUCCESS;
}
