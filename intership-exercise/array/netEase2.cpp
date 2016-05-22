 #include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*兰博教训提莫之后,然后和提莫讨论起约德尔人,谈起约德尔人,自然少不了一个人,那 就是黑默丁格------约德尔人历史上最伟大的科学家. 提莫说,黑默丁格最近在思考一个问题:黑默丁格有三个炮台,炮台能攻击到距离它R的敌人 (两点之间的距离为两点连续的距离,例如(3,0),(0,4)之间的距离是5),如果一个炮台能攻击 到敌人,那么就会对敌人造成1×的伤害.黑默丁格将三个炮台放在N*M方格中的点上,并且给出敌人 的坐标. 问:那么敌人受到伤害会是多大?

输入描述:
第一行9个整数,R,x1,y1,x2,y2,x3,y3,x0,y0.R代表炮台攻击的最大距离,(x1,y1),(x2,y2),
(x3,y3)代表三个炮台的坐标.(x0,y0)代表敌人的坐标.


输出描述:
输出一行,这一行代表敌人承受的最大伤害,(如果每个炮台都不能攻击到敌人,输出0×)

输入例子:
1 1 1 2 2 3 3 1 2

输出例子:
2x*/
using namespace std;
int main(){
    int R,x1,y1,x2,y2,x3,y3,x0,y0;
    int r1=0,r2=0,r3=0;
    int result=0;
    int count=2;
    for(;count>0;--count){
    scanf("%d %d %d %d %d %d %d %d %d",&R,&x1,&y1,&x2,&y2,&x3,&y3,&x0,&y0);
        r1= sqrt(pow((x1-x0),2)+pow((y1-y0),2));
        r2= sqrt(pow((x2-x0),2)+pow((y2-y0),2));
        r3= sqrt(pow((x3-x0),2)+pow((y3-y0),2));
     if(r1<R)
            ++result;
    if(r2<R)
            ++result;
    if(r3<R)
            ++result;
            
  cout<<result<<"x"<<endl;
        result=0;
    }
            
   return 0;
}
