/*Max Sum of the array. 
The following are some instances:(-2,11,-4,13,-5,-2), the max sum is 20*/ 

#include<stdio.h>
#include<stdlib.h>
//周游 13130110075 
int getMaxSum(int[],int);
int main(){
	
	int edata[]={-2,11,-40,-1,100,13,-5,-2};
	int len=6;
	printf("biggest sum = %d\n",getMaxSum(edata,len));
	system("PAUSE");
	return 0;
}


int getMaxSum(int a[],int len){
	
int result = a[0];
int sum = a[0];//为以第i个元素结尾且和最大的连续子数组
int i=0;

for(i=1;i<len;++i){
	
  if(sum < 0)
  sum = a[i];//直至找到一个大于0 的数 
  else
     sum += a[i];

  if(sum > result)
    result = sum;
}

return result;
}
