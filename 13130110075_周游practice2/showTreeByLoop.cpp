// �ǵݹ飨��ʹ��ջ���ķ�ʽ���������� 

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
