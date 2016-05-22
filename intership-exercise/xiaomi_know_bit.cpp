#include<stdio.h>
#include<stdlib.h>
int compare(int,int);
int main(){
	printf("%d",compare(0,0));
	return 0;
}
    int compare(int x,int y){
    	int result[32];
    	int count=0;
    	int i=0;
    	for(;i<32;i++){
    		if(x%2!=y%2)
    		++count;
    		x=x/2;
    		y=y/2;
    		if(!x&&!y)
    		break;
    	}
    	return count;
    } 

