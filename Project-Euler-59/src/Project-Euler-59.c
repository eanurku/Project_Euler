/*
 ============================================================================
 Name        : Project-Euler-59.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int isXORValid(int arr1[],int arr2[]){

	int i;
	for(i=0;i<3;i++){
		if(!isalpha(arr1[i]^arr2[i])){
			return 0;
		}
	}

	return 1;
}
int * encrypt(int *msg,int msgSize,int *key,int keylength){

	int i;
	for(i=0;i<msgSize;i++){
		msg[i]=msg[i]^key[i%keylength];

	}
	return msg;
}
void getKeyfromEncrypMsg(int *emsg, int emsgSize, int *key, int keylength) {
	int i, k, max, maxRepeatedChar;

	int tmp1[3][256] = { 0 };

	for (k = 0; k < keylength; k++)
		for (i = k; i < emsgSize; i += 3) {
			tmp1[k][emsg[i]]++;
		}

	for (k = 0; k < keylength; k++) {
		max = 0;
		for (i = k; i < 256; i++) {
			if (tmp1[k][i] > max) {
				max = tmp1[k][i];
				maxRepeatedChar = i;
			}
		}
		key[k] = ' ' ^ maxRepeatedChar;
	}



	/*
	int tmp1[256] = { 0 };
	int tmp2[256] = { 0 };
	int tmp3[256] = { 0 };

	max=0;
	for (i = 0; i < emsgSize; i += 3) {
		tmp1[emsg[i]]++;
	}

	for (i = 0; i < 256; i++) {
		if (tmp1[i] > max) {
			max = tmp1[i];
			maxRepeatedChar = i;
		}
	}
	key[0] = ' ' ^ maxRepeatedChar;

	max = 0;
	for (i = 1; i < emsgSize; i += 3) {
		tmp2[emsg[i]]++;
	}

	for (i = 0; i < 256; i++) {
		if (tmp2[i] > max) {
			max = tmp2[i];
			maxRepeatedChar = i;
		}
	}
	key[1] = ' ' ^ maxRepeatedChar;

	max = 0;

	for (i = 2; i < emsgSize; i += 3) {
		tmp3[emsg[i]]++;
	}

	for (i = 0; i < 256; i++) {
		if (tmp3[i] > max) {
			max = tmp3[i];
			maxRepeatedChar = i;
		}
	}
	key[2] = ' ' ^ maxRepeatedChar;

*/
}
int main(void) {

	int i=0,sum=0;;
	int encryptmessage[4000],esize;
	int key[3];
	int keylength=3;
	int *decryptMsg;

	char *inputString=(char *) malloc(sizeof(char) * 4000);
	char *token;
	char *delim=",";

	FILE * inputFile=fopen("/home/anurag/Desktop/CPROGG/PROJECT-EULER-linuxworkspace/Project-Euler-59/src/input.txt","r");
	fscanf(inputFile,"%s",inputString);

	token = strtok(inputString, delim);
	encryptmessage[i++] = atoi(token);


	while (token = strtok(NULL, delim)) {
		encryptmessage[i++] = atoi(token);

	}
	esize = i;


	getKeyfromEncrypMsg(encryptmessage,esize,key,keylength);
	decryptMsg = encrypt(encryptmessage, esize, key, keylength);

	for(i=0;i<esize;i++){
		sum+=decryptMsg[i];
	}
	printf("%c%c%c\n",key[0],key[1],key[2]);
	printf("sum=%d",sum);




	return EXIT_SUCCESS;
}
