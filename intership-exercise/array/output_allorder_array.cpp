/*����ȫ�����,����������е�����

ȫ����ݹ鷽ʽ 
��ԭ���һ�������õ�ÿһ��λ�ã���������̫���㣬
��ÿһ�����ŵ���һ��λ�ø��ӷ��㣨�ο��ڶ������� 
*/

#include<stdio.h>

int main(){
	int a[]={23,1,34,5,332}��
	 
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
	 //һ���ݹ�ȫ��ÿ�θ�������һ��Ԫ��	
	 }
	  
} 
int[] all_order(int a[],int n,int new){// �˳����� new ���� n + 1 
	
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
