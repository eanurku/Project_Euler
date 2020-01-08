/*
 ============================================================================
 Name        : Project-Euler-81.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 80
int main(void) {

	int array[100][100];
	int i,j,num;

	FILE * inputFile=fopen("/home/anurag/Desktop/CPROGG/PROJECT-EULER-linuxworkspace/Project-Euler-81/src/input.txt","r");
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			fscanf(inputFile,"%d",&num);
			array[i][j]=num;
		}
	}



	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {

			if(i==0 && j==0){
				;
			} else if(j==0){

				array[i][j]+=array[i-1][j];

			}else if(i==0){

				array[i][j]+=array[i][j-1];

			}else {
				if(array[i][j]+array[i-1][j]<array[i][j]+array[i][j-1])
					array[i][j]+=array[i-1][j];
				else
					array[i][j]+=array[i][j-1];

			}
		}
	}

/*		for(i=0;i<SIZE;i++){
			for(j=0;j<SIZE;j++){
				printf("%d ",array[i][j]);

			}
			printf("\n");
		}*/
	printf("%d ",array[SIZE-1][SIZE-1]);
	return EXIT_SUCCESS;
}
