// done by uchiyou

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
	
	
	TreeNode* findNode(TreeNode* root,int flag){
		if(root==NULL) return NULL;
		TreeNode* temp=root;
		
		TreeNode* left=findNode(root->left,flag);
		TreeNode* right=findNode(root->right,flag);
		
		
		if(left!=NULL)
		if(flag)
		temp=temp->val>left->val?temp:left;
		else
		temp=temp->val<left->val?temp:left;
		
		if(right!=NULL)
		if(flag)
		temp=temp->val>right->val?temp:right;
		else
		temp=temp->val<right->val?temp:right;
		
		return temp;
	}
	
	TreeNode* findPath(TreeNode* root,TreeNode* target,vector<TreeNode*> &paths){// the paths include the target
		
		if(root==NULL)
		return NULL;
		
		if(root==target){
		 paths.push_back(root);
		 return target;
	}
		
		TreeNode* left=findPath(root->left,target);		
		TreeNode* right=findPath(root->right,target);
		
		
		if(left==target || right==target){
			paths.push_back(root);
			return target;
		}
		
		return NULL;
	}
	
	int countPath(vector<TreeNode*> v1,vector<TreeNode*> v2){
		int i=0,j=0;
		int size1=v1.size(),size2=v2.size();
		
		for(i=0;i<size1;++i){
			for(j=0;j<size2;++j){
				if(v1[i]==v2[j])
				return i+j;
			}
		}
		
		return -1;// unknowed error happen		
	}
	
	
	
    int getDis(TreeNode* root) {
        // write code here
        TreeNode* maxNode=findNode(root,1);
        TreeNode* minNode=findNode(root,0);
        vector<TreeNode*> maxPath,minPath;
		findPath(root,maxNode,maxPath);
		findPath(root,minNode,minPath);
		int result=countPath(maxPath,minPath);
		return result==-1 ? 0 : result;
    }
    
