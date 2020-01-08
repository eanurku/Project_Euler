/*
 ============================================================================
 Name        : Project-Euler-22.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define SEPARATOR ','
int getSumOfLetters(char *string){
int sum=0;
	while(*string!='\0'){
      sum+=*string-'A'+1;
      string++;
	}

	return sum;
}
void swap(char **string,int i,int j){
char  *tmp=string[i];
string[i]=string[j];
string[j]=tmp;
}

void getSortedCharPointerArray(char **listOfCharPointers,int listOfCharPointersSize){

int i,j,n=listOfCharPointersSize;
char *t1,*t2,*tmp;
	for(i=0;i<=n-1;i++){
		for(j=0;j<=n-2-i;j++){
			if(strcmp(listOfCharPointers[j],listOfCharPointers[j+1])>0){
				swap(listOfCharPointers,j,j+1);

			}

		}
	}

}

int main(void) {

	int character, totalCharacterCount = 0, totalSeparatorCount = 0,totalWordCount=0;

	char *string;
	char *token;
	char *delimiter=",\"";//set delimiter

	char **listOfCharPointers;
	int listOfCharPointersSize=0;
	int i;

FILE *inputFile=fopen("C:\\Users\\anurag\\Desktop\\CPRGG\\PROJECT-EULER-workspace\\Project-Euler-22\\src\\inputNames.txt","r");
FILE *outputFile=fopen("C:\\Users\\anurag\\Desktop\\CPRGG\\PROJECT-EULER-workspace\\Project-Euler-22\\src\\outputNames.txt","w");


	while ((character = fgetc(inputFile)) != EOF) {

		totalCharacterCount++;

		if (character == SEPARATOR) {
			totalSeparatorCount++;
		}
	}

    totalWordCount=totalSeparatorCount+1;


	string = (char *) malloc(sizeof(char) * totalCharacterCount);
	listOfCharPointers=(char **)malloc(totalWordCount*sizeof(char *));

	rewind(inputFile);//initialize file pointer to start
	fscanf(inputFile, "%s", string);
	//printf("%s",string);

    token=strtok(string,delimiter);

    while(token!=NULL){

    	listOfCharPointers[listOfCharPointersSize++]=token;
    	token=strtok(NULL,delimiter);

    }


   getSortedCharPointerArray(listOfCharPointers,listOfCharPointersSize);



long long sum=0;

	for(i=0;i<listOfCharPointersSize;i++){
		fprintf(outputFile,"%s\n",listOfCharPointers[i]);
		sum+=(i+1)*getSumOfLetters(listOfCharPointers[i]);
	}

printf("%lld",sum);

	fclose(inputFile);
	fclose(outputFile);
	return EXIT_SUCCESS;
}
