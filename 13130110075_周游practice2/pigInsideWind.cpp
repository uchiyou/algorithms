/*���֮�£����ܷɡ������й�����ţ�У����ν����������ꡱ�� 
����һ���ع���ʷ�Ļ��ᣬ��֪һ֧��Ʊ����n��ļ۸����ƣ��Գ���Ϊn�����������ʾ��
�����е�i��Ԫ�أ�prices[i]������ù�Ʊ��i��Ĺɼۡ� ������һ��ʼû�й�Ʊ��
����������������1�ɶ�������1�ɵĻ��ᣬ��������ǰһ��Ҫ�ȱ�֤����û�й�Ʊ��
�����ν��׻��ᶼ����������Ϊ0�� ����㷨���������ܻ�õ�������档
 ������ֵ��Χ��2<=n<=100,0<=prices[i]<=100 
��������:
3,8,5,1,7,8

�������:
12*/
class Solution {
public:
    /**
     * �������ܻ�õ��������
     * 
     * @param prices Prices[i]����i��Ĺɼ�
     * @return ����
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
