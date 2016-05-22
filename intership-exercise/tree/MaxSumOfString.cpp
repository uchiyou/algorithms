/*Max Sum of the array. The following are some instances:(-2,11,-4,13,-5,-2), the max sum is 20*/
#include<stdio.h>
#include<stdlib.h>
int getMaxSumOfTwoNumber(int[],int);
int main(){
	int edata[]={-2,11,-4,13,-5,-2};
	int len=6;
	printf("biggest sum = %d\n",getMaxSumOfTwoNumber(edata,len));
	return 0;
}

int getMaxSumOfTwoNumber(int data[],int len){
	int biggest=data[len-1]>data[len-2]?data[len-1]:data[len-2];
	int second=data[len-1]>data[len-2]?data[len-2]:data[len-1];
	len=len-2;
	
	while(--len>=0){
		if(data[len]>biggest){
			second=biggest;
			biggest=data[len];
		}else if(data[len]>second){
			second=data[len];
		}
	}
	return biggest+second;
}
