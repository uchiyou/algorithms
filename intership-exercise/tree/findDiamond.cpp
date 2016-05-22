//����һ��ɭ��,��ϵ���ھ�����g2Ϊ���ڵ��������Ľڵ�����g1,
//������g1Ϊ���ڵ����������Ľڵ����g2
//���ǲ�ȡ��������ķ�ʽ������g1��ͷ��������,����g2��ͷ��������.


/*
С����С��ȥ����ʯ�����Ǵ�һ����ʯ�������ȡ���Ų��Ƚ����ǵ���������Щ��ʯ������������ͬ���������ǱȽ���һ��ʱ���
���ǿ�����������ʯg1��g2�������������֮ǰ�Ƚϵ���Ϣ�ж���������ʯ���ĿŸ��ء�
����������ʯ�ı��g1,g2����Ŵ�1��ʼ��ͬʱ������ϵ����vector,����Ԫ��ΪһЩ��Ԫ�飬
��һ��Ԫ��Ϊһ�αȽ��н��ص���ʯ�ı�ţ��ڶ���Ԫ��Ϊ�������ʯ�ı�š�������֮ǰ�ıȽϴ���n���뷵����������ʯ�Ĺ�ϵ��
��g1���ط���1��g2���ط���-1���޷��жϷ���0���������ݱ�֤�Ϸ���������ì��������֡�
����������
2,3,[[1,2],[2,4],[1,3],[4,3]],4
����: 1
*/
#include<unordered_map>


class Cmp {
    bool judge(int g1,int g2,unordered_map<int,vector<int>> ans){
    //����g1�Ƿ��g2��.
        queue<int>q;
        unordered_map<int, bool>mark;//���ڱ�ǵ�ǰ�ڵ��Ƿ������
        q.push(g1);
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            mark[cur] = true;
            if(cur==g2)
                return true;
            
            for(int i=0;i<ans[cur].size();++i){
                if(!mark[ans[cur][i]])//û�б�����
                    q.push(ans[cur][i]);
            }
            
        }
        return false;
    }
    
public:
    int cmp(int g1, int g2, vector<vector<int> > records, int n) {
        
        unordered_map<int,vector<int>> ans;
        for (int i=0; i<n; ++i)
            ans[records[i][0]].push_back(records[i][1]);
        
        
        if(judge(g1, g2, ans))
            return 1;
        else{
            if(judge(g2, g1, ans))
                return -1;
            else
                return 0;
        }
    }
};

