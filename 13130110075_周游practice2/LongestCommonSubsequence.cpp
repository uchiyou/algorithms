/*
Longest Common Subsequence (LCS). The following are some instances��
a) X: xzyzzyx  Y: zxyyzxz
b) X: ALLAAQANKESSSESFISRLLAIVAD
Y: KLQKKLAETEKRCTLLAAQANKENSNESFISRLLAIVAG
13130110075 
*/

#include<stdio.h>
#include<stdlib.h>
#define RESULTLEN 100
int getLCS(char[],int,char[],int ,char[][RESULTLEN]);//��ȡ�����ַ����Ĺ������� 
int getLen(char[]);// ��ȡ�ַ����ĳ��� 
void showLCS(char[][RESULTLEN],int,int,int len);// ��ӡ���������� 
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

// xlen �� �ַ��� x �ĳ��ȣ�ylen���ַ��� y�ĳ��ȣ� ��ά����result�������淽��򹫹��ַ���¼ 
int getLCS(char x[],int xlen,char y[],int ylen,char result[][RESULTLEN]){
	if(xlen==0||ylen==0)
	return 0;
	
	int len[xlen+1][ylen+1];//len ��ʾ�����ַ��ĸ��� 
	int i=0,j=0;	
	
	
	for(i=0;i<xlen+1;++i)
	for(j=0;j<ylen+1;++j)
	    len[i][j]=0;// ��ʼ������������Ϣ 
	
	
	for(i=0;i<xlen;++i){
		for(j=0;j<ylen;++j){
			
			 if(x[i]==y[j]){// ����ַ��� x �е�ĳ���ַ� ���ַ��� y �е�ĳ���ַ���ͬ 
			 	len[i+1][j+1]=len[i][j]+1;// �����ַ����� �� 1 
			 	result[i][j]=x[i]; //����¼��������ַ� 
			 }else if(len[i][j+1]>len[i+1][j]){// ���������һ�� i ���Ǹ��ַ�ǰ���������ַ������������ڵ���һ���ַ�ʱ�����Ĺ����ַ����� 
			 	len[i+1][j+1]=len[i][j+1];
			 	result[i][j]='u';//  ��־����Ϊ�� upper 
			 }else{
			 	len[i+1][j+1]=len[i+1][j];
			 	result[i][j]='l';// ��־����Ϊ�� left 
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
