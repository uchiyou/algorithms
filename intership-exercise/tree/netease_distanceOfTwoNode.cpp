/*��һ�ö�����������ÿ�������Ȩֵ��Ȩֵ������ͬ�������һ���㷨���Ȩֵ����Ҷ�ڵ㵽Ȩֵ��С��Ҷ�ڵ�ľ��롣
������ÿ���ߵľ���Ϊ1��һ���ڵ㾭���������ߵ�����һ���ڵ�Ϊ�������ڵ�֮��ľ��롣
�����������ĸ��ڵ�root���뷵��������롣*/


/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Tree {
public:
	int flag=0;// for flag : 1 max value,0 min value
	static TreeNode* target;
	
	// follow static varies are for getMinParent
	static int depth=0;
	static int mark1=0,mark2=0;//���ڱ���node1 �� node2 ������������ڵ� �ľ��� 
	static int flag1=0,flag2=0;//���ڱ�־�������Ƿ���� node1 �� node2 
    int getDis(TreeNode* root) {
        // write code here
        TreeNode* maxNode=getNode(root,1);
        TreeNode* minNode=getNode(root,0);
        return getMinParent(root,maxNode,minNode);
    }
    
    // mark1 and mark2 should be set 0 when call the function 
    void getMinParent(TreeNode* root,TreeNode* node1,TreeNode* node2){//return the distance of two node, postorder traversal the Tree
    
        if(root==null) return;
        
        if(root==node1){
        	flag1=1;
        }
       
         if(root==node2){
        	flag2=1;
        }
    	
    	getMinParent(root->left,node1,node2);
    	getMinParent(root->right,node1,node2);
    	
    	
    }
    
    void getNode(TreeNode* root,int val){
    	if(root==NULL) return;
    	static TreeNode* target=root;
    	static max=root->val,min=root->val;
		    	
    	if(flag){
    	if(root->val>max){
    		max=root->val;
    		target=root;
    	}
		}else{
    		if(root->val<min){
    		min=root->val;
    		target=root;
    	}
    	}
    	
    	 getNode(root->left,val);
    	 getNode(root->right,val);
    }
};
