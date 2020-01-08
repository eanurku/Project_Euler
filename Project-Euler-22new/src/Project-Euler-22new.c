/*
 ============================================================================
 Name        : Project-Euler-22new.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int getSum(char *ptr){

	int val=0;

	while(*ptr!='\0'){

		val+=*ptr-'A'+1;
		ptr++;
	}

	return val;
}
void swap(char **arr,int pos1,int pos2){

	char  *tmp=*(arr+pos1);
	*(arr+pos1)=*(arr+pos2);
	*(arr+pos2)=tmp;


}
void sortArray(char **arr,int size){

	int i,j;
	for(i=1;i<=size;i++){
		for(j=0;j<=size-1-i ;j++){
			if(strcmp(*(arr+j),*(arr+j+1))>0){
				swap(arr,j,j+1);
			}
		}

	}
}
int main(void) {


	char *string,*word,*delim=",\"";
	int  ch;
	int inputFileCharCount=0,wordCount=0;
	char **listOfCharPointers;
	FILE *inputFile=fopen("C:\\Users\\kanurag\\Desktop\\CPRGG\\PROJECT-EULER-workspace\\Project-Euler-22new\\src\\inputNames.txt","r");
	FILE *outputFile=fopen("C:\\Users\\kanurag\\Desktop\\CPRGG\\PROJECT-EULER-workspace\\Project-Euler-22new\\src\\outputFile.txt","w");

	while((ch=fgetc(inputFile))!=EOF){

		inputFileCharCount++;

		if(ch ==',')
			wordCount++;

	}

	string=(char *)malloc(sizeof(char)*inputFileCharCount);
	rewind(inputFile);
	fscanf(inputFile,"%s",string);


	listOfCharPointers=(char **)malloc(wordCount*sizeof(char *));
	int listOfCharPointersSize=0;

	word =strtok(string,delim);
	while(word !=NULL){
		listOfCharPointers[listOfCharPointersSize++]=word;
		word=strtok(NULL,delim);

	}



	sortArray(listOfCharPointers,listOfCharPointersSize);





    int i;
    long long sum=0;
	for( i=0;i<listOfCharPointersSize;i++){
		//printf("%s,",listOfCharPointers[i]);
		sum+=(i+1)*getSum(listOfCharPointers[i]);

	}

	printf("%d",sum);
	return EXIT_SUCCESS;
}
