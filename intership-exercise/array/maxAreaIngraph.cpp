/*��һ��ֱ��ͼ����һ�����������ʾ������ÿ�еĿ��Ϊ1��������ֱ��ͼ�����������������
���磬����ֱ��ͼ[2,7,9,4],���������������ε����Ϊ14(��[7,9]������7x2�ľ���)��
����һ��ֱ��ͼA�������ܿ��n���뷵���������������ֱ֤��ͼ���С�ڵ���500����֤�����int��Χ�ڡ�
����������
[2,7,9,4,1],5
���أ�14*/


class MaxInnerRec {
public:
    int countArea(vector<int> A, int n) {
        // write code here
        int i=0,j=0;
        vector<int> sum(A),flag;
        flag.resize(n);
        for(i=0;i<n;++i)
            flag[i]=1;
        
        
       
        for(i=0;i<n;++i){
            //from left to right
            for(j=0;j<i;++j){
                if(A[i]>=A[j]&&flag[j]==1){
                    sum[j]+=A[j];
                }else{
                    flag[j]=0;
                }
            }
            
            // from right to left
            for(j=i-1;j>=0;--j){
                if(A[i]<=A[j]){
                    sum[i]+=A[i];
                }else{
                    break;
                }
            }
        }
        
        
        
        int temp=sum[0];
        for(i=1;i<n;++i)
            temp=temp>sum[i]?temp:sum[i];
        

        return temp;
        
    }
}; 
