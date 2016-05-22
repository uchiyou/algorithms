/*
Longest Common Subsequence (LCS). The following are some instances：
a) X: xzyzzyx  Y: zxyyzxz
b) X: ALLAAQANKESSSESFISRLLAIVAD
Y: KLQKKLAETEKRCTLLAAQANKENSNESFISRLLAIVAG
13130110075 
*/

#include<stdio.h>
#include<stdlib.h>
#define RESULTLEN 100
int getLCS(char[],int,char[],int ,char[][RESULTLEN]);//获取两个字符串的公共长度 
int getLen(char[]);// 获取字符串的长度 
void showLCS(char[][RESULTLEN],int,int,int len);// 打印公共子序列 
int main(){
	
	char x[]="ALLAAQANKESSSESFISRLLAIVAD";
	int xlen=getLen(x);
	char y[]="KLQKKLAETEKRCTLLAAQANKENSNESFISRLLAIVAG";
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

// xlen 是 字符串 x 的长度，ylen是字符串 y的长度， 二维数组result用来保存方向或公共字符记录 
int getLCS(char x[],int xlen,char y[],int ylen,char result[][RESULTLEN]){
	if(xlen==0||ylen==0)
	return 0;
	
	int len[xlen+1][ylen+1];//len 表示公共字符的个数 
	int i=0,j=0;	
	
	
	for(i=0;i<xlen+1;++i)
	for(j=0;j<ylen+1;++j)
	    len[i][j]=0;// 初始化公共长度信息 
	
	
	for(i=0;i<xlen;++i){
		for(j=0;j<ylen;++j){
			
			 if(x[i]==y[j]){// 如果字符串 x 中的某个字符 和字符串 y 中的某个字符相同 
			 	len[i+1][j+1]=len[i][j]+1;// 公共字符个数 加 1 
			 	result[i][j]=x[i]; //　记录这个公共字符 
			 }else if(len[i][j+1]>len[i+1][j]){// 如果相邻上一行 i 的那个字符前包含公共字符个数大于相邻的上一列字符时包含的公共字符个数 
			 	len[i+1][j+1]=len[i][j+1];
			 	result[i][j]='u';//  标志方向为上 upper 
			 }else{
			 	len[i+1][j+1]=len[i+1][j];
			 	result[i][j]='l';// 标志方向为左 left 
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
