#include<stdio.h>
#include<stdlib.h>


typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    
    };


typedef struct Stack{
	TreeNode* node;
	struct Stack * next;
};
Stack* push(Stack*,TreeNode*);
TreeNode* pop(Stack** head);
void show_by_recursion(TreeNode* root);

int main(){
	TreeNode* temp=(TreeNode*)malloc(sizeof(TreeNode));
	temp->val=32;
	temp->left=NULL;
	temp->right=NULL;
	Stack* head=NULL;
	head=push(head,temp);
	
	TreeNode* t=pop((Stack**)(&head));
	
	t->left=(TreeNode*)malloc(sizeof(TreeNode));
	temp=t->left;
	temp->val=33;
	temp->left=NULL;
	temp->right=NULL;
	
	show_by_recursion(t);
	
//	printf("t-> val: %d\n",t->val);
	system("PAUSE");
	return 0;
}


Stack* push(Stack* head,TreeNode* node){
	Stack *temp=(Stack*) malloc(sizeof(Stack));
	temp->node=node;
	temp->next=head;
	return temp;
}

TreeNode* pop(Stack** head){
	if((*head)==NULL)
	return NULL;
	Stack* temp=*head;
	*head=(*head)->next;
	return temp->node;
}

void show_by_recursion(TreeNode* root){
	Stack* head=NULL;
	while(root!=NULL){
		
	printf(" %d\t ",root->val);
	
	if(root->right!=NULL)
	head=push(head,root->right);
	if(root->left!=NULL)
	head=push(head,root->left);
	
	root=pop((Stack**)(&head));
}
}

