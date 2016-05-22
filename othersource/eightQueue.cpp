// 8-queen program
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int count(int);
int solute(int,int[],int);
int isValid(int,int,int[]);
int main(){
	
	printf("%d\n",count(5));
	
	system("PAUSE");
	return 0;
} 

int count(int n){
	if(n<1)
	return 0;
	
	int record[n];
	int i=0;
	for(i=0;i<n;++i)
	record[i]=0;
	return solute(0,record,n);
}

int solute(int row,int record[],int n){
	if(row==n)
	return 1;
	
	int result=0;
	int i=0;
	for(i=0;i<n;++i){
		if(isValid(row,i,record)){
		
			record[row]=i;
			result=result+solute(row+1,record,n);
			
			printf("-- %d --- %d \n",row,i); 
		}
	}
	return result;
}

int isValid(int row,int column,int record[]){
	int i=0;
	for(i=0;i<row;++i)
	if(column==record[i]||abs(row-i)==abs(column-record[i]))
	return 0;
	
	return 1;
}
