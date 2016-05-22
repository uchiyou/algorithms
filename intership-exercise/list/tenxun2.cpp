
/*编程题] 微信红包
春节期间小明使用微信收到很多个红包，非常开心。在查看领取红包记录时发现，某个红包金额出现的次数超过了红包总数的一半。请帮小明找到该红包金额。写出具体算法思路和代码实现，要求算法尽可能高效。
给定一个红包的金额数组gifts及它的大小n，请返回所求红包的金额。
测试样例：
[1,2,3,2,2],5
返回：2*/class Gift {
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
            //考虑队头
            if(gifts[i]==node->value){
                ++(node->count);                
            }
            
            GiftNumber* before=node,temp=head;
            while(node->next!=null){
                node=node->next;
            if(gifts[i]==node->value)
                ++(node->count);
             
                //构造最大优先级队列，数量越大的在队头
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
            
            //如果不在队列，则置于队尾
                node->next=(GiftNumber*)malloc(sizeof(GiftNumber));
                node=node->next;
                node->value=gifts[i];
                node->count=1;
                node->next=null;
           
            
            
            
        }
    }
};
