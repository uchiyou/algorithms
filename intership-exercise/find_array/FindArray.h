
/*��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳�����������һ��������
q����������һ����ά�����һ���������ж��������Ƿ��и������� 
��������:
array�� �����ҵĶ�ά����
target�����ҵ�����

�������:
���ҵ�����true�����Ҳ�������false*/
#include<vector>
class Solution {
public:
    bool Find(vector<vector<int> > array,int target);
    bool FindOnce(vector<int> array,int target);
    bool FindBoard(vector<vector<int> > array,int target,int board,int &middle);
};
