
/*
老师想知道从某某同学当中，分数最高的是多少，现在请你编程模拟老师的询问。当然，老师有时候需要更新某位同学的成绩. 
输入描述:
输入包括多组测试数据。
每组输入第一行是两个正整数N和M（0 < N <= 30000,0 < M < 5000）,分别代表学生的数目和操作的数目。
学生ID编号从1编到N。
第二行包含N个整数，代表这N个学生的初始成绩，其中第i个数代表ID为i的学生的成绩
接下来又M行，每一行有一个字符C（只取‘Q’或‘U’），和两个正整数A,B,当C为'Q'的时候, 表示这是一条询问操作，他询问ID从A到B（包括A,B）的学生当中，成绩最高的是多少
当C为‘U’的时候，表示这是一条更新操作，要求把ID为A的学生的成绩更改为B。


输出描述:
对于每一次询问操作，在一行里面输出最高成绩.

输入例子:
5 7
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 4 5
U 2 9
Q 1 5

输出例子:
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
   // fflush(stdin);//清空最后留下的 \n 
    getchar();
     	
    for(i=0;i<m;++i){
    
 //   printf("--->i=%d\n",i);
		scanf("%c %d %d",&c,&a,&b);// 回车键也算一个字符（换行符）,否则在 stdin 缓存中缓存 '\n ‘ 
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
