/*数组全序输出,输出数组所有的序列

程序的主要思路是：
1.把第1个数换到最前面来（本来就在最前面），准备打印1xx，再对后两个数2和3做全排列。
2.把第2个数换到最前面来，准备打印2xx，再对后两个数1和3做全排列。
3.把第3个数换到最前面来，准备打印3xx，再对后两个数1和2做全排列。
可见这是一个递归的过程，把对整个序列做全排列的问题归结为对它的子序列做全排列的问题，
注意我没有描述Base Case怎么处理，你需要自己想。你的程序要具有通用性，
如果改变了N和数组a的定义（比如改成4个数的数组），其它代码不需要修改就可以做4个数的全排列（共24种排列）。
*/
#include<stdio.h>
int print_once(int[],int);
int get_allOrder(int[],int,int);

int static copy_count=0;
int main(){
	int a[]={1,2,3};
	int n=3;
	get_allOrder(a,n,0);
	printf("copy_count= %d \n",copy_count);
	return 0;
	 
}

int print_once(int a[],int n){
	int i=0;
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 1;
}
int copy_array(int source[],int target[],int n){
	int i=0;
	++copy_count;
	for(i=0;i<n;++i)
		target[i]=source[i];
		return i;
}

int get_allOrder(int arr[],int n,int piovt){//指向第几个数移到最前面 
        
        int array[n];//arr is for keep the array's sort, array is the copy of arr
        copy_array(arr,array,n);

		if(piovt==n-1){
    	print_once(array,n);
	    return 1;
}		
	
	int i=0;
	int temp=array[piovt];
	for(i=piovt;i<n;++i){
		//把每一个数移动到最前面一次 
		temp=array[piovt];
		array[piovt]=array[i];
		array[i]=temp;	
		
    	get_allOrder(array,n,piovt+1);//把每一个数移动到最前面后，对剩下的 n-piovt-1 个数进行一趟全排序 
    	
	}
	
}

