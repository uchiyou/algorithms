#include<stdio.h>
#include<stdlib.h>
int foo(int);
int ack(int,int);
int main(){
	printf("%d\n",ack(4,3));
	system("PAUSE");
	return 0;
}

int foo(int n) {
    if (n < 2)
        return n;
    return foo(n - 1) + foo(n - 2);
}
int ack(int m,int n)
{
    if(m==0)
    {
    return n+1;
    }
    else if(n==0)
    {
        return ack(m-1,1);
    }
    else
    {
        return ack(m-1,ack(m,n-1));
    }
}
