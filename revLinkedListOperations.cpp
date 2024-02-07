#include<iostream>
struct Node{
	int data;
	struct Node *next;
};

//Node traverseNodes(Node *head){
	struct Node *temp=head;
	while(temp !=NULL){
		println("%d-->", temp->data);
		temp=temp->next;
	}
	
//} 

//Node insertBeginning(int val){
	
	struct Node *newNode;
	newNode=malloc(sizeof(struct Node));
	newNode->data=val;
	newNode->next=head;
	head=newNode;

//}

//Node insertEnd(int val){
	struct Node *newNode;
	newNode= malloc(sizeof(struct Node));
	newNode->data=val;
	newNode->next=NULL;
	
	struct Node *temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newNode;

//}


int main(){
	
}
