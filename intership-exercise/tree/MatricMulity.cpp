/*Matrix-chain product. The following are some instances:
a) <3, 5, 2, 1,10> <A,B,C,D>
b) <2, 7, 3, 6, 10> 
c) <10, 3, 15, 12, 7, 2> 
d) <7, 2, 4, 15, 20, 5>

���� 13130110075 
*/
#include <iostream>
using namespace std;

#define N 4

void matrix_chain_order(int*,int,int[][N+1],int[][N+1]);
void print_optimal_parents(int[][N+1],int,int);

int main()
{

    int p[N+1] = {10, 3, 15, 12, 7};
    int m[N+1][N+1]={0};
    int s[N+1][N+1]={0};
    int i,j;
    matrix_chain_order(p,N+1,m,s);
   
    cout<<"s value is: "<<endl;
    for(i=1;i<=N;++i)
    {
        for(j=1;j<=N;++j)
        if(s[i][j]!=0)
            cout<<s[i][j]<<" ";
        cout<<endl;
    }
    cout<<"The result is:"<<endl;
    print_optimal_parents(s,1,N);
    return 0;
}

void matrix_chain_order(int *p,int len,int m[N+1][N+1],int s[N+1][N+1])
{
    int i,j,k,t;
    for(i=0;i<=N;++i)
        m[i][i] = 0;
    for(t=2;t<=N;t++)  //��ǰ���˾���ĳ���
    {
        for(i=1;i<=N-t+1;i++)  //�ӵ�һ����ʼ���𣬼��㳤��Ϊt�����ٴ���
        {
            j=i+t-1;//����Ϊtʱ������һ��Ԫ��
            m[i][j] = 10000000;  //��ʼ��Ϊ������
            for(k=i;k<=j-1;k++)   //Ѱ�����ŵ�kֵ��ʹ�÷ֳ�������k��i��j-1֮��
            {
                int temp = m[i][k]+m[k+1][j] + p[i-1]*p[k]*p[j];
                if(temp < m[i][j])
                {
                    m[i][j] = temp;   //��¼�µ�ǰ����С����
                    s[i][j] = k;      //��¼��ǰ������λ�ã�������ı��
                }
            }
        }
    }
}

//s�д�������ŵ�ǰ��λ��
void print_optimal_parents(int s[N+1][N+1],int i,int j)
{
    if( i == j)
        cout<<"A"<<i;
    else
    {
        cout<<"(";
        print_optimal_parents(s,i,s[i][j]);
        print_optimal_parents(s,s[i][j]+1,j);
        cout<<")";
    }

}
