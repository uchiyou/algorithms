/*
��ν�����ַ���������һ���ַ����������Ҷ��ʹ��ҵ��������ȫһ���ģ�
�� �� "aba"��"c"��</p><p>����һ���ַ���������ͨ��ɾ��ĳЩ�ַ�����ɻ����ַ�����
��"cabebaf"��ɾ��'c'��'e'��'f'��ʣ���Ӵ�"abba"���ǻ����ַ�����

Ҫ�󣬸�������һ���ַ������ַ�����󳤶�1000���������Ļ����ַ������ȡ�
��"cabebaf"�Ļ��Ĵ�����"c"��"aba"��"abba"�ȣ������"abba"����Ϊ4��
���룺�ַ���
��������Ļ����ַ������ȡ�

ʾ����
����: cabbeaf
���: 4

*/
#include<stdio.h>
#include<stdlib.h>
int getMaxLength(char[]);
int getLen(char[]);
int main(){
	char source[]="cfaccf";
	printf("%d\n",getMaxLength(source));
	system("PAUSE");
	return 0;
}

int getLen(char source[]){
	int len=0;
	while(source[++len]!='\0');
	return len;
}
int getMaxLength(char source[]){
	if(source==NULL)
	return -1;
	int len=getLen(source);
	if(len<=1)
	return len;

	
	int maxRecord[len][len],leftRecord[len],rightRecord[len];
	int i=0,j=0,t=0;
	// init data
	for(i=0;i<len;++i){
		for(j=0;j<len;++j)
		maxRecord[i][j]=i<=j?1:0;// only i < j can data having meannings
		leftRecord[i]=i;
		rightRecord[i]=i;
	}
	
	// calculate the max into record
	for(i=1;i<len;++i){
		for(j=0;j<len-i;++j){
		   		  
		   // temp is the max of j - j+i-1 or j+1 - j+i
		       int temp=( maxRecord[j][j+i-1] > maxRecord[j+1][j+i] ? maxRecord[j][j+i-1] : maxRecord[j+1][j+i] );
			   if( source[j] == source[j+i]  )
			    	maxRecord[j][j+i] = maxRecord[j+1][j+i-1]+2>temp?maxRecord[j+1][j+i-1]+2:temp;
				else
					maxRecord[j][j+i] = temp;
		  
		  
		}
	}
	// the result is char[] 0 - (len-1)
	return maxRecord[0][len-1];
}

