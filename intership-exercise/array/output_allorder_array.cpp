/*数组全序输出,输出数组所有的序列

全排序递归方式 
我原想把一个数放置到每一个位置，但这样不太方便，
把每一个数放到第一个位置更加方便（参考第二个程序） 
*/

#include<stdio.h>

int main(){
	int a[]={23,1,34,5,332}；
	 
}

int print_once(int a[],int n){
	int i=0;
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 1;
}


int outputAllOrder(int a[],int n){
     
	 int i=0;
	 for(i=0;i<n;++i){
	 //一个递归全序，每次该序增加一个元素	
	 }
	  
} 
int[] all_order(int a[],int n,int new){// 此程序中 new 等于 n + 1 
	
	if(n==1) return a;
	if(n==2){
		
	}
	
	int i=0;
	int temp=a[new];
	for(i=0;i<n;++i){
		a[new]=a[n-i-1];
		a[n-i-1]=temp;
		temp=a[new];
		
	}
	
	
	
}
