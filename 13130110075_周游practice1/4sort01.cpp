/*Suppose that we have an array of n data records to sort. The key of each record has the value of 0 or 1.
  An algorithm for sorting such a set of records might possess some subset of the following three desirable characteristics:
  
1. The algorithm runs in O (n) time.
2. The algorithm is stable.
3. The algorithm sorts in place, using no more than a constant amount of storage space in addition to the original array.
a. Give an algorithm that satisfies criteria 1 and 2 above.
b. Give an algorithm that satisfies criteria 1 and 3 above.
c. Give an algorithm that satisfies criteria 2 and 3 above.
*/

#include<stdio.h>
#include<stdlib.h>
int a(int [],int);
int main(){
	
     int i=0;
	int array[]={1,0,0,1,0,1};
	int n=6;
		for(i=0;i<n;++i){
		printf("%d\t",array[i]);
	}
	printf("\n");
	a(array,n);

	for(i=0;i<n;++i){
		printf("%d\t",array[i]);
	}
	return 0;
	
} 

int a(int array[],int n){//ascend sort
	int temp=0;
	int low=0,high=n-1;
	
	while(low<high){
		while(low<high){
			if(array[high]==0)
			break;
			--high;
		}
		while(low<high){
			if(array[low]==1){
				array[high]=1;
				array[low]=0;
				break;
			}
				++low;
		}
	}
	return 1;
}
