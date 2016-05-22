#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*
13130110075_÷‹”Œpractice1
  Randomized Quicksort.
*/
int my_rand(int);
int once_sort(int[],int,int );
int quick_sort(int[],int,int);
int main(){
	int array[]={13,5,3454,-23,23,2};
	int n=6;
	quick_sort(array,0,n-1);
	
	int i=0;
	for(;i<n;i++){
		printf(" %d\n",array[i]);
	}
	
	system("PAUSE");
	return 0;
}

int my_rand(int n){
	if(n<2) return n;
	srand((int)time(0));
	return (int)rand()%n;
}


int once_sort(int array[],int head,int tail){
	
	int pivot=head+my_rand(tail-head);
	int temp=array[pivot];
	while(tail>head){
		while(tail>pivot){
		if(array[tail]<temp) {
			array[pivot]=array[tail];
			pivot=tail;
			--tail;
			break;
		}
		--tail;
	}
	
		while(head<pivot){
		if(array[head]>temp){
			array[pivot]=array[head];
			pivot=head;
			++head;
			break;
		}
		++head;
	}
	
}  
     array[pivot]=temp;
     return pivot;
 }
int quick_sort(int array[],int low,int hight){
	int pivot=0;
	if(low<hight){
		pivot=once_sort(array,low,hight);
		quick_sort(array,low,pivot-1);
		quick_sort(array,pivot+1,hight);
	}
	return 1;
}
