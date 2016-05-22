/*风口之下，猪都能飞。当今中国股市牛市，真可谓“错过等七年”。 
给你一个回顾历史的机会，已知一支股票连续n天的价格走势，以长度为n的整数数组表示，
数组中第i个元素（prices[i]）代表该股票第i天的股价。 假设你一开始没有股票，
但有至多两次买入1股而后卖出1股的机会，并且买入前一定要先保证手上没有股票。
若两次交易机会都放弃，收益为0。 设计算法，计算你能获得的最大收益。
 输入数值范围：2<=n<=100,0<=prices[i]<=100 
输入例子:
3,8,5,1,7,8

输出例子:
12*/
class Solution {
public:
    /**
     * 计算你能获得的最大收益
     * 
     * @param prices Prices[i]即第i天的股价
     * @return 整型
     */
    int calculateMax(vector<int> prices) {

        int result=0;
        int fr=0,sr=0,tr=0;
		int temp=0,ctemp=0;
        int size=prices.size();
        
        int i=0,j=0;
       // for(i=0;i<size;++i){
            for(j=1;j<size;++j){
                ctemp=ctemp+(prices[j]-prices[j-1]);
                if(prices[j]>prices[j-1]){
                    temp=temp+(prices[j]-prices[j-1]);
                }else{
                    
                    if(temp>fr){
                        sr=fr;
                        fr=temp;
                        result=(fr+sr)>(temp+ctemp)?(fr+sr):(temp+ctemp);
                        temp=0;
                        continue;
                    }
                    sr=temp>sr?temp:sr;
                    temp=0;
                    ctemp=ctemp<0?0:ctemp;
                }
            }
     //   }
    }
};
