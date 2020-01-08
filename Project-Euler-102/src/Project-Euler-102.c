/*
 ============================================================================
 Name        : Project-Euler-102.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 200
#define COL 6
#define ROW 1000

int isOriginAndThirdPointOnsameSide(int x1,int y1,int x2,int y2,int px,int py){

	int fp=(py-y1)*(x2-x1)-(y2-y1)*(px-x1);
	int fo=(0-y1)*(x2-x1)-(y2-y1)*(0-x1);
	if((fo<0 && fp<0)||(fo>0 && fp>0)){
		return  1;
	}
	return 0;
}
int main(void) {

	int A_x1,A_y1,B_x2,B_y2,C_x3,C_y3;
	int i,j,count=0;
	int array[1000][200];
	char *str=(char *) malloc(sizeof(char) * 200);
	char *token;

	FILE* inputFile=fopen("/home/anurag/Desktop/CPROGG/PROJECT-EULER-linuxworkspace/Project-Euler-102/src/input.txt","r");

	i=0;
	while(fgets(str,MAXSIZE,inputFile)){

		j=0;
		token=strtok(str,",");

		while(token){

			array[i][j++]=atoi(token);
			token=strtok(NULL,",");
		}
		i++;
	}


/*	for(i=0;i<ROW;i++){
		for(j=0;j<COL;j++){
			printf("%d ",array[i][j]);
		}
		printf("\n");

	}*/


	for (i = 0; i < ROW; i++) {

		A_x1=array[i][0];A_y1=array[i][1];
		B_x2=array[i][2];B_y2=array[i][3];
		C_x3=array[i][4];C_y3=array[i][5];

		if(isOriginAndThirdPointOnsameSide(A_x1,A_y1,B_x2,B_y2,C_x3,C_y3)&& isOriginAndThirdPointOnsameSide(B_x2,B_y2,C_x3,C_y3,A_x1,A_y1)&&isOriginAndThirdPointOnsameSide(C_x3,C_y3,A_x1,A_y1,B_x2,B_y2)){

		count++;

		}

	}

	printf("%d",count);
	return EXIT_SUCCESS;
}
