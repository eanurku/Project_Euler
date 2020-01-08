/*
 ============================================================================
 Name        : Project-Euler-31.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int main(void) {
	clock_t t1,t2;
	  t1=clock();
	  double run_time;
int c1,c2,c3,c4,c5,c6,c7,c8;
int e1=1,e2=2,e3=5,e4=10,e5=20,e6=50,e7=100,e8=200;
int count=0;
for(c1=0;(c1*e1)<=200;c1++){
	for(c2=0;(c1*e1+c2*e2)<=200;c2++){
		for(c3=0;(c1*e1+c2*e2+c3*e3)<=200;c3++){
			for(c4=0;(c1*e1+c2*e2+c3*e3+c4*e4)<=200;c4++){
				for(c5=0;(c1*e1+c2*e2+c3*e3+c4*e4+c5*e5)<=200;c5++){
					for(c6=0;(c1*e1+c2*e2+c3*e3+c4*e4+c5*e5+c6*e6)<=200;c6++){
						for(c7=0;(c1*e1+c2*e2+c3*e3+c4*e4+c5*e5+c6*e6+c7*e7)<=200;c7++){
							for(c8=0;(c1*e1+c2*e2+c3*e3+c4*e4+c5*e5+c6*e6+c7*e7+c8*e8)<=200;c8++){

								if((c1*e1+c2*e2+c3*e3+c4*e4+c5*e5+c6*e6+c7*e7+c8*e8)==200){
									count++;
								}
							}

						}

					}
				}

			}
		}

	}

}


printf("%d",count);
//end
t2=clock();
run_time=(t2-t1)/(double)CLOCKS_PER_SEC;
printf("\n%lf",run_time);
	return EXIT_SUCCESS;
}
