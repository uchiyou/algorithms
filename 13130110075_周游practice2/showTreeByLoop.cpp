// 非递归（不使用栈）的方式遍历二叉树 

#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node* left,right;
};
int main(){
	
	return 0;
}

void show(Node* head){
	Node* temp=head;
	
	while(temp->left!=NULL||temp->right!=NULL)
	temp=temp->left;
	
	printf("%d\t",temp->data);
	
	
	
}
