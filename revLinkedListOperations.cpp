#include<iostream>
using namespace std;
struct Node{
	int data;
	struct Node *next;
};

void traverseNodes(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<< " ,";
        temp = temp->next;
    }
    cout<<"\n"<<endl;
}
 

Node* insertBeginning(Node* head, int val){
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = head;
    return newNode;
}

Node insertEnd(Node *head, int val){
	Node *newNode=new Node;
	newNode->data=val;
	newNode->next=NULL;
	
	struct Node *temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newNode;

}

Node insertAnyPosition(Node *head,int i, int val){
	Node *newNode=new Node;
	newNode->data=val;
	
	struct Node *temp=head;
	for(int j=0; j<i;j++){
		if(temp->next!=NULL){
			temp=temp->next;
		}
	}
	newNode->next=temp->next;
	temp->next=newNode;
	
}

Node* reverse(Node *head){
	Node* current = head;
    Node *prev = NULL, *next = NULL;
    while (current != NULL) {
            next = current->next;
            current->next = prev;
            
            prev = current;
            current = next;
        }
        head = prev;
        return head; 
}

//next=7
//current->next = null
//prev=3
//current=7
//
//next= 45
//current->next=3
//prev=7
//current=45
//
//next= null
//current->next = 7
//prev=45
//current=null
//
//head = 45


int main(){
	Node* n1 = new Node;
    n1->data = 3;
    Node* n2 = new Node;
    n2->data = 7;
    Node* n3 = new Node;
    n3->data = 45;
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;
    
    Node* head = n1;
    
    traverseNodes(head);
//    head=insertBeginning(head,98);
//    traverseNodes(head);
//    insertEnd(head,75);
//    traverseNodes(head);
//    insertAnyPosition(head,1,655);
//    traverseNodes(head);
    head=reverse(head);
    traverseNodes(head);
	
}
