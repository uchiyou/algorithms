
/*�����] ΢�ź��
�����ڼ�С��ʹ��΢���յ��ܶ��������ǳ����ġ��ڲ鿴��ȡ�����¼ʱ���֣�ĳ����������ֵĴ��������˺��������һ�롣���С���ҵ��ú����д�������㷨˼·�ʹ���ʵ�֣�Ҫ���㷨�����ܸ�Ч��
����һ������Ľ������gifts�����Ĵ�Сn���뷵���������Ľ�
����������
[1,2,3,2,2],5
���أ�2*/class Gift {
public:
    typedef struct GiftNumber{
        int value;
        int count;
        struct GiftNumber *next;
    }
    int getValue(vector<int> gifts, int n) {
        // write code here
        GiftNumber *head,*node;
        node=head=(GiftNumber*)malloc(sizeof(GiftNumber));
        head->value=gitfs[0];
        head->count=1;
        head->next=null;
        int i=0;
        for(i=1;i<n;++i){
            
            node=head;
            //���Ƕ�ͷ
            if(gifts[i]==node->value){
                ++(node->count);                
            }
            
            GiftNumber* before=node,temp=head;
            while(node->next!=null){
                node=node->next;
            if(gifts[i]==node->value)
                ++(node->count);
             
                //����������ȼ����У�����Խ����ڶ�ͷ
            if(before->count<node->count){                
                before->next=node->next;
                node->next=before;
               if(before==head){
                   temp->next=node;
               }
            }
                temp=before;
                before=node;
            }
            
            //������ڶ��У������ڶ�β
                node->next=(GiftNumber*)malloc(sizeof(GiftNumber));
                node=node->next;
                node->value=gifts[i];
                node->count=1;
                node->next=null;
           
            
            
            
        }
    }
};
