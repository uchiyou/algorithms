/*获取列表倒数第 k 个*/

#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int key;
	struct Node* next;
};
Node* getTheLastKNode(Node*,int);
Node* generateListByInput();

int main(){
	Node* head=generateListByInput();
	
	int k=2;
	printf("the last %d node is %d\n",k,(getTheLastKNode(head,k))->key);
	return 0;
}

Node* generateListByInput(){
	Node* head=NULL;
	Node* temp;
		
	head=(Node*)malloc(sizeof(Node));
	temp=head;
	printf("how many node do you want create ?\n");
	int n=0,i=0;
	scanf("%d",&n);
	getchar();
	int t;
	for(i=0;i<n;++i){
	scanf("%d",&t);
	temp->key=t;
	getchar();
	temp->next=(Node*)malloc(sizeof(Node));
	if(temp->next==NULL){
		printf(" malloc failed\n");
		system("PAUSE");
		exit(0);
	}
	temp=temp->next;	
}
    temp->next=NULL;

	return head;
}

Node* getTheLastKNode(Node* head,int k){
	int count=1;
	if(head==NULL) return NULL;
	Node* temp=head;
	
	while(head->next!=NULL){
		head=head->next;
		if(count>k){
			temp=temp->next;
		}
		++count;
	}
	if(count<k)
	return NULL;
	else
	return temp;
}
