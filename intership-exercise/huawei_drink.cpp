#include<stdio.h>
#include<stdlib.h>
int getMax(int);
int main(){
    
    int n[10];
    int ncount=0;
    
    int count=0;
    int i=0;
    for(;i<10;++i){
        scanf("%d",n+i);
        if(n[i]==0){
            ncount=i;
            break;
        }
            
    }
    
    for(i=0;i<ncount;++i){ 
   // printf("------>%d\n",n[i]); 
        printf("%d\n",getMax(n[i]));
    
    } 
   //  printf("%d\n",getMax(10));
     system("PAUSE");
    return 0;
    
    
}
int getMax(int n){
    int rest=n%3;
    int count=n=n/3;
    n+=rest;
    
    while(n>2){
        rest=n%3;
        n=n/3;
        count+=n;
        n=n+rest;
    }
    if(n==2)
        ++count;
    return count;
    
}
