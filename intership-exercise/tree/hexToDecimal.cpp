#include<stdio.h>
#include<stdlib.h>
/*
进制转换
写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串。（多组同时输入 ）

输入描述:
输入一个十六进制的数值字符串。

输出描述:
输出该数值的十进制字符串。

输入例子:
0xA

输出例子:
10
*/
 
int main(){
    char input[100];
    int i=0;
    int count=0;
       
       
    
    while(scanf("%s",input)!=EOF){
    	
    	printf("%s\n",input);
    	printf("%c\n",input[2]);
    	
        i=2;
        int temp=0;
        while(input[i]!='\0'){
        	printf("%c\n",input[i]);
            if(input[i]>'9'){
                temp=input[i]-'A'+10;
            }else{
                temp=input[i]-'0';
            }
            
            count=count*16+temp;
            
            
            ++i;
        }
        printf("%d\n",count);
        count=0;
        i=0;
       
    }
    
    system("PAUSE");
    return 0;
}
