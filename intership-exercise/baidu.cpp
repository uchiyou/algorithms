#include<stdio.h>
#include<stdlib.h>
int getLen(char[]);
int main(){
	int N=0,a=0,b=0;
	char string[1000];
	scanf("%d",&N); 
	scanf("%s",string);
	int len=getLen(string);
	int i=0,temp=0;
	
	int j=0;
	for(j=0;j<N;++j){ 
	scanf("%d %d",&a,&b);
	
		if(a<1&&b>len)
		return -1;
		
		temp=1;
	for(i=a-1;i<b;++i){
		temp*=(string[i]-28);
		if(temp>9973)
		temp=temp%9973;
	}
	printf("%d\n",temp%9973);
//	getchar();

} 
	
	
	return 0;
}
int getLen(char string[]){
	if(string==NULL)
	return -1;
	int i=0;
	while(string[i++]!='\0');
	return i;
}
