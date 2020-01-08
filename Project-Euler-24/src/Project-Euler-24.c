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

int count=0;
void swap(char *array,int p1,int p2){

	int tmp=array[p1];
	array[p1]=array[p2];
	array[p2]=tmp;

}
void sortMe(char *array,int start,int end){

	int i,j;
	int t1,t2;
		for(i=start;i<=end;i++){
			for(j=start;j<=end-1;j++){
				t1=array[j];
				t2=array[j+1];
				if(t1-t2>0){
                 swap(array,j,j+1);

				}

			}
		}
}



void getPermutation(char array[],int start,int end){

int i;
if(start==end){
	count++;
/*if(count==1000000)*/
	printf("%s,%d\n",array,count);

return;

}

	for(i=start;i<=end;i++){
		swap(array,start,i);
		//sortMe(array,start+1,end);
		getPermutation(array,start+1,end);
		swap(array,start,i);


	}


}
int main(void) {

	char array[]="1234";



	int start=0;
	int end=3;
	getPermutation(array,start,end);

//sortMe(array,3,6);
//printf("%s\n",array);
		return EXIT_SUCCESS;
}
