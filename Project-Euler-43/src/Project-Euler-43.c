/*
 ============================================================================
 Name        : Project-Euler-24.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

long long sum=0;
int isSubStringDivisible(char *array){

	int i,tmp;
	int primeArray[]={0,2,3,5,7,11,13,17};

	for(i=1;i<8;i++){
		tmp=(array[i]-'0')*100+(array[i+1]-'0')*10+(array[i+2]-'0');
         if(tmp==0 || tmp%primeArray[i] !=0){
        	 return 0;
         }
	}


return 1;
}
void swap(char *array,int p1,int p2){

	int tmp=array[p1];
	array[p1]=array[p2];
	array[p2]=tmp;

}
void getPermutation(char array[],int start,int end){

long long i,number=0;
	if (start == end) {

		if (array[0] != '0') {
			for (i = 0; i < 10; i++) {
				number = number * 10 + array[i] - '0';
			}


			if(isSubStringDivisible(array)){
				printf("%lld\n", number);
				sum+=number;
			}
		}

		return;

}

	for(i=start;i<=end;i++){
		swap(array,start,i);
		getPermutation(array,start+1,end);
		swap(array,start,i);


	}


}
int main(void) {

	char array[]="1406357289";

	int start=0;
	int end=9;
	getPermutation(array,start,end);

	printf("sum=%lld",sum);
		return EXIT_SUCCESS;
}
