/*
 ============================================================================
 Name        : Project-Euler-83.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int minOfTwo(int a, int b) {
	if(a<b)
		return a;
	else
		return b;

}
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
int minOfFour(int a, int b, int c, int d) {

	int minofthree = minOfThree(a, b, c);
	if (d < minofthree) {
		return d;
	} else {
		return minofthree;
	}
}
int main(void) {


	int array[100][100];
	int i,j,num;

	FILE * inputFile=fopen("/home/anurag/Desktop/CPROGG/PROJECT-EULER-linuxworkspace/Project-Euler-83/src/input.txt","r");
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			fscanf(inputFile,"%d",&num);
			array[i][j]=num;
		}
	}


	for (j = 0; j < SIZE; j++) {
		for (i = 0; i < SIZE; i++) {

			if(i==0 && j==0){
				;
			}else if(i==0 && j==SIZE-1){
				array[i][j]+=minOfTwo(array[i][j]+array[i][j-1],array[i][j]+array[i+1][j]);

			}else if(i==SIZE-1 && j==0){
				array[i][j]=minOfTwo(array[i][j]+array[i][j+1],array[i][j]+array[i-1][j]);
			}else if(i==SIZE-1 && j==SIZE-1){
				array[i][j]=minOfTwo(array[i][j]+array[i][j-1],array[i][j]+array[i-1][j]);
			}else if(i==0){
				array[i][j]=minOfThree(array[i][j]+array[i][j-1],array[i][j]+array[i][j+1],array[i][j]+array[i+1][j]);
			}else if(j==0){
				array[i][j]=minOfThree(array[i][j]+array[i][j+1],array[i][j]+array[i-1][j],array[i][j]+array[i+1][j]);
			}else if(i==SIZE-1){
				array[i][j]=minOfThree(array[i][j]+array[i][j+1],array[i][j]+array[i-1][j],array[i][j]+array[i][j+1]);
			}else if(j==SIZE-1){
				array[i][j]=minOfThree(array[i][j]+array[i][j-1],array[i][j]+array[i-1][j],array[i][j]+array[i+1][j]);

			}else {
				array[i][j]=minOfFour(array[i][j]+array[i][j-1],array[i][j]+array[i-1][j],array[i][j]+array[i+1][j],array[i][j]+array[i][j+1]);
			}


			}
		}

			for(i=0;i<SIZE;i++){
				for(j=0;j<SIZE;j++){
					printf("%d ",array[i][j]);

				}
				printf("\n");
			}
	return EXIT_SUCCESS;
}
