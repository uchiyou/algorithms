#include<stdio.h>
#include<stdlib.h>
/*
����ת��
д��һ�����򣬽���һ��ʮ�����Ƶ���ֵ�ַ������������ֵ��ʮ�����ַ�����������ͬʱ���� ��

��������:
����һ��ʮ�����Ƶ���ֵ�ַ�����

�������:
�������ֵ��ʮ�����ַ�����

��������:
0xA

�������:
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
