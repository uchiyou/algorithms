/*����ȫ�����,����������е�����

�������Ҫ˼·�ǣ�
1.�ѵ�1����������ǰ����������������ǰ�棩��׼����ӡ1xx���ٶԺ�������2��3��ȫ���С�
2.�ѵ�2����������ǰ������׼����ӡ2xx���ٶԺ�������1��3��ȫ���С�
3.�ѵ�3����������ǰ������׼����ӡ3xx���ٶԺ�������1��2��ȫ���С�
�ɼ�����һ���ݹ�Ĺ��̣��Ѷ�����������ȫ���е�������Ϊ��������������ȫ���е����⣬
ע����û������Base Case��ô��������Ҫ�Լ��롣��ĳ���Ҫ����ͨ���ԣ�
����ı���N������a�Ķ��壨����ĳ�4���������飩���������벻��Ҫ�޸ľͿ�����4������ȫ���У���24�����У���
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

int get_allOrder(int arr[],int n,int piovt){//ָ��ڼ������Ƶ���ǰ�� 
        
        int array[n];//arr is for keep the array's sort, array is the copy of arr
        copy_array(arr,array,n);

		if(piovt==n-1){
    	print_once(array,n);
	    return 1;
}		
	
	int i=0;
	int temp=array[piovt];
	for(i=piovt;i<n;++i){
		//��ÿһ�����ƶ�����ǰ��һ�� 
		temp=array[piovt];
		array[piovt]=array[i];
		array[i]=temp;	
		
    	get_allOrder(array,n,piovt+1);//��ÿһ�����ƶ�����ǰ��󣬶�ʣ�µ� n-piovt-1 ��������һ��ȫ���� 
    	
	}
	
}

