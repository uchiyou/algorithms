/*Max Sum of the subarray. The following are some instances:(-2,11,-4,13,-5,-2), the max sum is 20*/
#include<stdio.h>
#include<stdlib.h>
int getMaxSumOfSubarray(int[],int);
int main(){
	int edata[]={-2,11,-4,13,-5,-2};
	int len=6;
	printf("biggest sum = %d\n",getMaxSumOfTwoNumber(edata,len));
	return 0;
}
int getMaxSumOfSubarray(int data[],int len){
	int record[][len];
	int begin[len],end[len];// record the position of subarray
	int i=0,j=0;
	int temp=0;
	
	for(i=0;i<len;++i){
	record[i][i]=data[i];
	begin[i]=end[j]=i;
}
	
	for(i=1;i<len;++i){
		
	}
	
}
