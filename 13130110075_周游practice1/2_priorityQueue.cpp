#include<stdio.h>
#include<stdlib.h>

/*
13130110075_ÖÜÓÎpractice1
2£®	Implement priority queue.

*/
typedef struct Node{
	int key;
	int value;
	struct Node* next;
};


int showQueue(Node*);
Node* insert(Node*,Node*);
Node* maximum(Node*);
Node* extract_max(Node**);
Node* increase_key(Node*,Node*,int);
Node* getNode(Node*,int);

int main(){
	Node* head=(Node*)malloc(sizeof(Node));
	head->next=NULL;
	head->value=0;
	head->key=1;
	
	
	showQueue(head);
	
	printf("how many node entry (key,value) will you input ?\n");
	int num=0;
	scanf("%d",&num);
	int i=0;
	for(;i<num;++i){

	Node* node=(Node*)malloc(sizeof(Node));
	node->next=NULL;
	printf("(key,value)= ?\n");
	scanf("%d %d",&(node->key),&(node->value));
	head=insert(head,node);
	
}
	
	
	showQueue(head);
	
	
	Node* max=maximum(head);
	printf("\n--------------test maximum\nmax entry is (key, value)=(%d , %d)\n",max->key,max->value);
	
	

	
	
	printf("please input x->key and k \n------------test increased key\n");
	int xk,k;
	scanf("%d %d",&xk,&k);
	Node* x=getNode(head,xk);
	if(x==NULL){
		printf("--------> get x Node failed\n");
		exit(0);
	}
     head=increase_key(head,x,k);
	showQueue(head);
	
	
	printf("\n\n------test extract max\n");
	Node* emax=extract_max(&head);
	printf(" the extracted max entry is (%d,%d), the rest queue is \n",emax->key,emax->value);
	showQueue(head);
	
	
	
	
	system("PAUSE");
	return 0;
	
}

Node* getNode(Node* head,int key){
	if(head==NULL) return NULL;
	if(head->key==key) return head;
	while(head->next!=NULL) {
		head=head->next;
		if(head->key==key) 
		return head;
	}
	
	return NULL;
}

int showQueue(Node* head){// show the infomation include head node
	if(head==NULL)
	return -1;
	
	
	while(head->next!=NULL){
	printf("key= %d ,value= %d \n",head->key,head->value);
	head=head->next;
}
    printf("key= %d ,value= %d \n",head->key,head->value);
	

    return 1;
}

//  ascending  return head of priority queue
Node* insert(Node* head,Node* node){
	
	if(head==NULL||node==NULL)
	return NULL;
	
	Node* h=head;// h is for save the head of queue
	Node* temp=head;
	
	if(node->key>head->key){// node is the head of the queue
	node->next=head;
	return node;
}
    
	while(head->next!=NULL){
		
		temp=head;
	    head=head->next;
    	if(node->key>head->key){
		         node->next=head;
		         temp->next=node;
		        return h;
	}
	
}

  head->next=node;// node is the tail of the queue
  return h;
}

Node* maximum(Node* head){
	if(head==NULL) return NULL;
	return head;
	
}
Node* extract_max(Node** head){// return the hightest key and delete it
	Node* temp=*head;
	(*head)=(*head)->next;
	return temp;
}

Node* increase_key(Node* head,Node* x,int key){// x->key will turn into key
	if(key<(x->key)) {
		printf("illegel key \n");
	return NULL;
}
	
	Node* h=head;
	x->key=key;
	
	if(head==x) return head;// if x if the head ,do nothing !  because key is the max
	while(head->next!=NULL){
		if(head->next==x) {
		head->next = head->next->next;//delete x
		break;
		} 
		head=head->next;
	}
	
	h=insert(h,x);
	return h;
	
	
}
