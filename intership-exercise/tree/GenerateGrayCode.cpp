/*���ɸ�����
��һ�����ı����У��������������ڵĴ���ֻ��һλ����������ͬ�� ������ֱ���Ϊ������(Gray Code)�����дһ��������ʹ�õݹ�ķ�������Nλ�ĸ����롣
����һ������n���뷵��nλ�ĸ����룬˳��Ϊ��0��ʼ��
����������
1
���أ�["0","1"]*/
class GrayCode {
public:
    vector<string> getGray(int n) {
        // write code here
        vector<string> result;
        if(n==1){
            result.push_back("0");
            result.push_back("1");
            return result;
        }        
        
        result=getGray(n-1);
        
        int size=result.size();
        string temp;
        int i=0;
        
        for(i=size-1;i>=0;--i){
            temp=result[i];
            temp.push_back('1');
            result.push_back(temp);
        }
        for(i=0;i<size;++i){
            result[i].push_back('0');
        }
       return result;
        
    }
};
