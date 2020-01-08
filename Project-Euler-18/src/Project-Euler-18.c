/*
 ============================================================================
 Name        : Project-Euler-18.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 15
int main(void) {
	int i,j,c0,c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13,c14,sum,maxSum=0,number;

	int array[20][20]={0};

/*	int array[4][4]={{3,0,0,0},
			        {7,4,0,0},
					{2,4,6,0},
					{8,5,9,3}};*/

    FILE *inputFile=fopen("/home/anurag/Desktop/CPROGG/PROJECT-EULER-linuxworkspace/Project-Euler-18/src/input.txt","r");


	for (i = 1; i <= SIZE; i++) {
		for (j = 0; j < i; j++) {
			fscanf(inputFile, "%d", &number);
			array[i-1][j]=number;
		}
	}

	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			printf("%d ",array[i][j]);
		}
		printf("\n");
	}

/*	for(c0=0;c0<1;c0++)
	for(c1=0;c1<2;c1++)
		if((c1-c0)==1 || (c1-c0)==0)
	for(c2=0;c2<3;c2++)
		if((c2-c1)==1 || (c2-c1)==0)
	for(c3=0;c3<4;c3++)
		if((c3-c2)==1 ||  (c3-c2)==0){
		sum=array[0][c0]+array[1][c1]+array[2][c2]+array[3][c3];
		if(maxSum<sum){
			maxSum=sum;
			printf("max sum=%d,values=%d,%d,%d,%d\n",maxSum,array[0][c0],array[1][c1],array[2][c2],array[3][c3]);

		}
	}*/

/*

	for(c0=0;c0<1;c0++)
	for(c1=0; c1<2;c1++)
		if(((c1-c0)==1 || (c1-c0)==0))
	for(c2=0;c2<3;c2++)
		if((c2-c1)==1 || (c2-c1)==0)
	for(c3=0; c3<4;c3++)
		if((c3-c2)==1 ||  (c3-c2)==0)
	for(c4=0; c4<5;c4++)
		if((c4-c3)==1 ||  (c4-c3)==0)
	for(c5=0;c5<6;c5++)
		if((c5-c4)==1 ||  (c5-c4)==0)
	for(c6=0;c6<7;c6++)
		if((c6-c5)==1 ||  (c6-c5)==0)
	for(c7=0; c7<8;c7++)
		if((c7-c6)==1 ||  (c7-c6)==0)
	for(c8=0;c8<9;c8++)
		if((c8-c7)==1 ||  (c8-c7)==0)
	for(c9=0;c9<10;c9++)
		if((c9-c8)==1 ||  (c9-c8)==0)
	for(c10=0;c10<11;c10++)
		if((c10-c9)==1 ||  (c10-c9)==0)
	for(c11=0;c11<12;c11++)
		if((c11-c10)==1 ||  (c11-c10)==0)
	for(c12=0;c12<13;c12++)
		if((c12-c11)==1 ||  (c12-c11)==0)
	for(c13=0;c13<14;c13++)
		if((c13-c12)==1 || (c13-c12)==0)
	for(c14=0;c14<15;c14++)
	if((c14-c13)==1 ||  (c14-c13)==0){
		sum=array[0][c0]+array[1][c1]+array[2][c2]+array[3][c3]+array[4][c4]+array[5][c5]+array[6][c6]+array[7][c7]+array[8][c8]+array[9][c9]+array[10][c10]+array[11][c11]+array[12][c12]+array[13][c13]+array[14][c14];
		if(maxSum<sum){
			maxSum=sum;

		}
	}
*/

	for (i = 1; i < SIZE; i++) {
		for (j = 0; j <= i; j++) {
			if (j == 0) {
				array[i][j] += array[i - 1][j];
			} else {
				if (array[i][j] + array[i - 1][j]
						> array[i][j] + array[i - 1][j - 1])
					array[i][j] += array[i - 1][j];
				else
					array[i][j] += array[i - 1][j - 1];
			}

		}

	}

	for (j = 0; j < SIZE; j++) {
		if (array[SIZE - 1][j] > maxSum) {
			maxSum = array[SIZE - 1][j];
		}
	}

	printf("max sum=%d",maxSum);

	return EXIT_SUCCESS;
}
