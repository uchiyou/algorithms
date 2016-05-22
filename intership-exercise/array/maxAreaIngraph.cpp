/*有一个直方图，用一个整数数组表示，其中每列的宽度为1，求所给直方图包含的最大矩形面积。
比如，对于直方图[2,7,9,4],它所包含的最大矩形的面积为14(即[7,9]包涵的7x2的矩形)。
给定一个直方图A及它的总宽度n，请返回最大矩形面积。保证直方图宽度小于等于500。保证结果在int范围内。
测试样例：
[2,7,9,4,1],5
返回：14*/


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
