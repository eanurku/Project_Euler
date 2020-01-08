/*
 ============================================================================
 Name        : Project-Euler-206.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


long long perfect_square_check(long long z)
{  long long  x;
    x=(long long)pow(z,.5);
   if(x*x==z)
   return x;
   else
   return 0;
}

long long ArrayToNumber(int *array,int size){

	int i;
	long long number=0;
	for(i=0;i<size;i++){
		number=number*10+array[i];
	}

	return number;
}
int main(void) {

	int array[20]={0};
	int size=19;

	array[0]=1;
	array[2]=2;
	array[4]=3;
	array[6]=4;
	array[8]=5;
	array[10]=6;
	array[12]=7;
	array[14]=8;
	array[16]=9;
	array[18]=0;


	int d1,d2,d3,d4,d5,d6,d7,d8,d9;
	long long found=0, value;

	for(d1=0;d1<10 && !found;d1++)
		for(d2=0;d2<10 && !found;d2++)
			for(d3=0;d3<10 && !found;d3++)
				for(d4=0;d4<10 && !found;d4++)
					for(d5=0;d5<10 && !found;d5++)
						for(d6=0;d6<10 && !found;d6++)
							for(d7=0;d7<10 && !found;d7++)
								for(d8=0;d8<10 && !found;d8++)
									for(d9=0;d9<10 && !found;d9++){
										array[1]=d1;
										array[3]=d2;
										array[5]=d3;
										array[7]=d4;
										array[9]=d5;
										array[11]=d6;
										array[13]=d7;
										array[15]=d8;
										array[17]=d9;
										if(value=isperfectSquare(ArrayToNumber(array,size))){
											found=1;
											break;
										}

									}
	printf("%lld",value);
	return EXIT_SUCCESS;
}
