#include<stdio.h>
#include<stdlib.h>
/*С�׾���������������Ϸ.��һ��,������һ�������������Ϸ,���Ľ�ɫ�ĳ�ʼ����ֵΪ a.�ڽ�������һ��ʱ����,��������������n������,ÿ������ķ�����Ϊb1,b2,b3...bn. ��������Ĺ��������biС�ڵ���С�׵ĵ�ǰ����ֵc,��ô���������ɴ�ܹ���,�� ��ʹ���Լ�������ֵ����bi;���bi����c,����Ҳ�ܴ�ܹ���,����������ֵֻ������bi ��c�����Լ��.��ô��������,��һϵ�еĶ�����,С�׵���������ֵΪ����?

��������:
����ÿ������,��һ������������n(1��n<100000)��ʾ�����������a��ʾС�׵ĳ�ʼ����ֵ.
�ڶ���n������,b1,b2...bn(1��bi��n)��ʾÿ������ķ�����


�������:
����ÿ������,���һ��.ÿ�н�����һ������,��ʾС�׵���������ֵ

��������:
3 50
50 105 200
5 20
30 20 15 40 100

�������:
110
205*/

int get_hcd(int,int);
int get_hcd(int x,int y){
    int i=1,result=1;
    int min=x>y?y:x;
    int max=x>y?x:y;
    for(;i<=min;i++){
        if(min%i==0&&max%i==0){
            result=i;
            if(max%(min/i)==0){
                result=min/i;
                return result;
            }
        }
    }
    return result;
}
int main(){
    
    int n=0,a=0;
    int count=2;
    for(;count>0;--count){
        
    scanf("%d %d",&n,&a);
    if(n<0||a<1)
        exit(0);
    
    int i=0,temp=0;
    for(;i<n;i++){
        scanf("%d",&temp);
        
        if(a>=temp)
            a+=temp;
        else{
            a+=get_hcd(a,temp);
        }
        
    }
    printf("%d\n",a);
        
    }
        
    return 0;
}
