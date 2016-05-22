/*
所谓回文字符串，就是一个字符串，从左到右读和从右到左读是完全一样的，
比 如 "aba"、"c"。</p><p>对于一个字符串，可以通过删除某些字符而变成回文字符串，
如"cabebaf"，删除'c'、'e'、'f'后剩下子串"abba"就是回文字符串。

要求，给定任意一个字符串，字符串最大长度1000，计算出最长的回文字符串长度。
如"cabebaf"的回文串包括"c"、"aba"、"abba"等，最长回文"abba"长度为4。
输入：字符串
输出：最大的回文字符串长度。

示例：
输入: cabbeaf
输出: 4

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

