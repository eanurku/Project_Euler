/*
 ============================================================================
 Name        : Project-Euler-42.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define SEPARATOR ','

int isTrinagleNumber(long long number){

int i;
long long sum=0;

for(i=1;i*i+i<= 2*number;i++){
     sum+=i;
	if(number==sum){
		return 1;
	}
}

	return 0;
}


int getAlphabetSumOfword(char *string){
int sum=0;
while(*string !='\0'){

	sum+=*string-'A'+1;

	string++;
}


return sum;
}


int main(void) {

int number=28,i;


int character,charCount=0,wordCount=0;



FILE *inputFile=fopen("C:\\Users\\anurag\\Desktop\\CPRGG\\PROJECT-EULER-workspace\\Project-Euler-42\\src\\words.txt","r");

FILE *outputFile=fopen("C:\\Users\\anurag\\Desktop\\CPRGG\\PROJECT-EULER-workspace\\Project-Euler-42\\src\\out.txt","w");


while( (character=fgetc(inputFile))!=EOF){

	charCount++;
	if(character==SEPARATOR){
         wordCount++;
	}

}
charCount++;//for '\0'
wordCount++;//as no words is one more than separator

char *string=(char *)malloc(sizeof(char)*charCount);
char **wordList=(char **)malloc(sizeof(char*)*wordCount);
int wordListSize=0;
char *token;

rewind(inputFile);
fscanf(inputFile,"%s",string);

token=strtok(string,",\"");

while(token!=NULL){
/*
	fputs(token,outputFile);
	fputs("\n",outputFile);*/
	wordList[wordListSize++]=token;
	token=strtok(NULL,",\"");


}


fclose(inputFile);
fclose(outputFile);

int count=0;
for(i=0;i<wordListSize;i++){


     if(isTrinagleNumber(getAlphabetSumOfword(wordList[i]))){
      count++;
     }

}

 printf("%d",count);
	return EXIT_SUCCESS;
}
