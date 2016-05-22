#include<stdio.h>
#include<stdlib.h>
int getMaxArea(int *,int);
int getMaxSubMatrix(int [][3],int ,int);
int main(){
	int a[][3]={{1,1,0},{0,1,0},{1,1,0}};
	int x=3,y=3;
	printf("%d\n",getMaxSubMatrix(a,x,y));
	
	system("PAUSE");
	return 0;
}

int getMaxSubMatrix(int a[][3],int xlen,int ylen){
	
	int temp[ylen];
	
	int i=0,j=0;
	for(i=0;i<ylen;++i)
	temp[i]=0;
	
	int maxRecord=0;
	for(i=0;i<xlen;++i){
		for(j=0;j<ylen;++j){
			if((*(*(a+i)+j))==0)
			temp[j]=0;
			else
			temp[j]+=1;
		}
		
		//	printf("%d\n",maxRecord);
		int t=getMaxArea(temp,ylen);
	
		maxRecord=maxRecord>t?maxRecord:t;
	}
	
	return maxRecord;
} 
int getMaxArea(int *g,int len){
	int result=0;
	int record[len],mark[len];
	
	
	int i=0,j=0;
	// init data
	for(i=0;i<len;++i){
	record[i]=0;
	mark[i]=1;
}
// record the area from the graph
	for(i=0;i<len;++i){
		record[i]+=(*(g+i));
		int lflag=1;
		for(j=i-1;j>=0;--j){
			if(*(g+i)>*(g+j)){
				lflag=0;
				if(mark[j]==1)
				record[j]+=(*(g+j));
			}else if(*(g+i)<*(g+j)){
				mark[j]=0;
				if(lflag==1)
				record[i]+=(*(g+i));
			}else{
				if(mark[j]==1)
				record[j]+=(*(g+j));
				if(lflag==1)
				record[i]+=(*(g+i));
			}
		}
	}
	
	// get the max from record
	for(i=0;i<len;++i)
	result=result>record[i]?result:record[i];

	return result;
}
