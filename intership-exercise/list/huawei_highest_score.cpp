
/*
��ʦ��֪����ĳĳͬѧ���У�������ߵ��Ƕ��٣�����������ģ����ʦ��ѯ�ʡ���Ȼ����ʦ��ʱ����Ҫ����ĳλͬѧ�ĳɼ�. 
��������:
�����������������ݡ�
ÿ�������һ��������������N��M��0 < N <= 30000,0 < M < 5000��,�ֱ����ѧ������Ŀ�Ͳ�������Ŀ��
ѧ��ID��Ŵ�1�ൽN��
�ڶ��а���N��������������N��ѧ���ĳ�ʼ�ɼ������е�i��������IDΪi��ѧ���ĳɼ�
��������M�У�ÿһ����һ���ַ�C��ֻȡ��Q����U������������������A,B,��CΪ'Q'��ʱ��, ��ʾ����һ��ѯ�ʲ�������ѯ��ID��A��B������A,B����ѧ�����У��ɼ���ߵ��Ƕ���
��CΪ��U����ʱ�򣬱�ʾ����һ�����²�����Ҫ���IDΪA��ѧ���ĳɼ�����ΪB��


�������:
����ÿһ��ѯ�ʲ�������һ�����������߳ɼ�.

��������:
5 7
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 4 5
U 2 9
Q 1 5

�������:
5
6
5
9
*/
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
    int i;
    for(i=0;i<n;i++){
    	scanf("%d",nscore+i);
    }
   // fflush(stdin);//���������µ� \n 
    getchar();
     	
    for(i=0;i<m;++i){
    
 //   printf("--->i=%d\n",i);
		scanf("%c %d %d",&c,&a,&b);// �س���Ҳ��һ���ַ������з���,������ stdin �����л��� '\n �� 
        getchar();
     //   printf("----->c=%c a=%d b=%d i=%d\n",c,a,b,i); 
      
    	if('Q'==c){
    		temp=*(nscore+a-1);
    		int j=0;
	        for(j=a-1;j<b;j++)
	        temp=temp>(*(nscore+j))?temp:(*(nscore+j));
         	printf("%d\n",temp);
         //	fflush(stdout);
         	temp=0;
         	
    	}else if('U'==c)
    	*(nscore+a-1)=b;
    	else{
    		printf("illegel input\n");
    	}
    	
    }
   
   
    system("PAUSE");
    return 0;
        
}
