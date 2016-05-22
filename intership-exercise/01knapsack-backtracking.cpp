#include<stdio.h>
int n,c,bestp;//物品的个数，背包的容量，最大价值

//物品的价值，物品的重量，x[i]暂存物品的选中情况,物品的选中情况
int p[10000],w[10000],x[10000],bestx[10000];
void Backtrack(int i,int cp,int cw)
{ //cw当前包内物品重量，cp当前包内物品价值
    int j;
    if(i>n)//回溯结束 {
        if(cp>bestp){
            bestp=cp;
            for(i=0;i<=n;i++) bestx[i]=x[i];//记录结果 
        //  j=0 表示第 i 个物品不放入背包， j=1 第 i 个物品放入背包 
        }}else for(j=0;j<=1;j++) {
            x[i]=j;
            if(cw+x[i]*w[i]<=c){// 如果第 i  个物品不可以放入，则 x[i]==0, 
                cw+=w[i]*x[i];// 增加第 i 个物品的重量 
                cp+=p[i]*x[i]; //增加第 i 个物品的价值 
                Backtrack(i+1,cp,cw);// 判断第  i+1 个物品的情况 
                // 回溯一步,  将第 i 个物品取出 
                cw-=w[i]*x[i];
                cp-=p[i]*x[i];
            }}}
            
int main()
{
    int i;
    bestp=0; 
    printf("请输入背包最大容量:\n");
    scanf("%d",&c);
    printf("请输入物品个数:\n");
    scanf("%d",&n);
    printf("请依次输入物品的重量:\n");
    for(i=1;i<=n;i++) 
        scanf("%d",&w[i]);
    printf("请依次输入物品的价值:\n");
    for(i=1;i<=n;i++) 
        scanf("%d",&p[i]);
    Backtrack(1,0,0);
    printf("最大价值为:\n");
    printf("%d\n",bestp);
    printf("被选中的物品依次是(0表示未选中，1表示选中)\n");
    for(i=1;i<=n;i++) 
        printf("%d ",bestx[i]);
    printf("\n");
    return 0;
}
