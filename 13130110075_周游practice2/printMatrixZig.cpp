#include<stdio.h>
#include<stdlib.h>
#define MAXLEN 100
int printLine(int[][MAXLEN],int,int,int,int,int);
int printMatrixZig(int[][MAXLEN],int,int);
int main(){
	int matrix[][MAXLEN]={{1,2,3},{4,5,6},{7,8,9}};
	int b=3,h=3;
	printMatrixZig(matrix,b,h);
	system("PAUSE");
	return 0;
} 


int printMatrixZig(int matrix[][MAXLEN],int b,int h){
	int ti=0,tj=0;
	int bi=0,bj=0;
	int flag=0;
	while(bj<b&&bi<h){
		printLine(matrix,ti,tj,bi,bj,flag);
		flag=1-flag;
		ti=tj<b-1?ti:1+ti;
		tj=tj<b-1?1+tj:tj;
		bj=bi<h-1?bj:1+bj;
		bi=bi<h-1?1+bi:bi;
	
	}
	return 0;
}

int printLine(int matrix[][MAXLEN],int ti,int tj,int bi,int bj,int flag){
	if(flag){
		while(ti!=bi+1)
		printf("%d\t",matrix[ti++][tj--]);
	}else
	while(bi!=ti-1)
		printf("%d\t",matrix[bi--][bj++]);
	printf("\n");	
    return 0;
}
