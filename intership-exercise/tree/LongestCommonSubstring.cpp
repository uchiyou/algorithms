/*
Longest Common Subsequence (LCS). The following are some instances£º
a) X: xzyzzyx  Y: zxyyzxz
b) X: ALLAAQANKESSSESFISRLLAIVAD
Y: KLQKKLAETEKRCTLLAAQANKENSNESFISRLLAIVAG

*/

#include<stdio.h>
#include<stdlib.h>
#define RESULTLEN 100
int getLCS(char[],int,char[],int ,char[][RESULTLEN]);
int getLen(char[]);
void showLCS(char[][RESULTLEN],int,int,int len);
int main(){
	
	char x[]="yxxxyyyjjj";
	int xlen=getLen(x);
	char y[]="yxxyjjsdsj";
	int ylen=getLen(y);

	char result[xlen][100];// 'c' mean the common char in both x and y,'x' mean the longest common substring in x,'y' mean the similar
	
	
	int len=getLCS(x,xlen,y,ylen,result);
	printf("len = %d\n",len);
	showLCS(result,xlen,ylen,len);
	system("PAUSE");
	return 0;
}

int getLen(char a[]){
	int i=0;
	while(a[i++]!='\0');
	return i-1;
}


int getLCS(char x[],int xlen,char y[],int ylen,char result[][RESULTLEN]){
	if(xlen==0||ylen==0)
	return 0;
	
	int len[xlen+1][ylen+1];
	int i=0,j=0;	
	
	for(i=0;i<xlen+1;++i)
		len[i][0]=0;
	for(j=0;j<ylen;++j)
	    len[0][j]=0;
	
	
	for(i=0;i<xlen;++i){
		for(j=0;j<ylen;++j){
			
			 if(x[i]==y[j]){
			 	len[i+1][j+1]=len[i][j]+1;
			 	result[i][j]=x[i];
			 }else if(len[i][j+1]>len[i+1][j]){
			 	len[i+1][j+1]=len[i][j+1];
			 	result[i][j]='u';
			 }else{
			 	len[i+1][j+1]=len[i+1][j];
			 	result[i][j]='l';
			 }
		}
	}
	
	return len[xlen][ylen];
}
void showLCS(char result[][RESULTLEN],int xlen,int ylen,int len){
	char temp[len+1];
	temp[len]='\0';
	while(xlen>0 && ylen>0){
	if(result[xlen-1][ylen-1]=='u')
	--xlen;
	else if(result[xlen-1][ylen-1]=='l')
	--ylen;
	else{
	temp[--len]=result[xlen-1][ylen-1];
	--xlen;
	--ylen;
}
}
   printf("%s\n",temp);
   return;
}
