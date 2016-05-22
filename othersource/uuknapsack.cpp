/*
1го	0-1 knapsack problem. 
a)	Instance : weight capacity is 100
item	weights	values
A	50	200
B	30	180
C	45	225
D	25	200
E	5	50

*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	char item;
	int weights;
	int values;
};
int main(){
	
	return 0;
} 
int solution(Node items[],int n,int w){
	
	
	
	int r1=(solution(items,n-1,w-items[n-1].weights)+items[n-1].value)
	int r2=solution(items,n-1,w);
	return r1>r2?r1:r2;
}
