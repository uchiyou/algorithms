#include<stdio.h>
#include<stdlib.h>


int main(){
   char c;
        int a=0,b=0;
         int temp=0;
    int n=0,m=0;
    int *nscore;
   
    scanf("%d %d",&n,&m);
    
  
    nscore=(int*) malloc(sizeof(int)*n);
    int* out=(int*)malloc(sizeof(int)*m);
    int outs=0;
    
    int i;
    for(i=0;i<n;i++){
    	scanf("%d",nscore+i);
    }
   // fflush(stdin);//清空最后留下的 \n 
    getchar();
     	
    for(i=0;i<m;++i){
    
 //   printf("--->i=%d\n",i);
		scanf("%c %d %d",&c,&a,&b);// 回车键也算一个字符（换行符）,否则在 stdin 缓存中缓存 '\n ‘ 
        getchar();
    
		if('Q'==c){
    		temp=*(nscore+a-1);
    		int j=0;
	        for(j=a-1;j<b;j++)
	        temp=temp>(*(nscore+j))?temp:(*(nscore+j));
            out[outs]=temp;
            ++outs;
         	temp=0;
         	
    	}else if('U'==c)
    	*(nscore+a-1)=b;
    	else{
    	exit(0);
    	}
    	
    }
   
      
      for(i=0;i<outs;++i)
      printf("%d\n",out[i]);
   
    system("PAUSE");
    return 0;
        
}








