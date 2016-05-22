#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int hasX(int[],int,int);
/*
 * 13130110075_÷‹”Œ_practice1 
  *1£Æ	Describe a ¶®(n lg n)-time algorithm that, given a set S of n integers and another integer x,
   determines whether or not there exist two elements in S whose sum is exactly x. 
*/ 
int main(){
	
	int s[100],n;
	int x=0;
	
	printf("please input x, numbers of S\n");
	scanf("%d %d",&x,&n);
	printf("please input the set S\n");
	int i=0;
	for(i=0;i<n;++i)
	scanf("%d",s+i);
	
	if(hasX(s,n,x))
	printf("yes , there are x equal sum of two number\n");
	else
	printf("no , there are not\n");
	
	
	
	system("PAUSE");
	return 0;
} 

int hasX(int s[],int n,int x){
	
          int i=0;
          int count=1;
          
          for(;count<n;++count)
          for(i=0;i<n;++i){
          	
          	if(i+count>=n)
          	break;
          	
          	if(s[i]+s[i+count]==x)
          	return 1;
          }
	return 0;
}
