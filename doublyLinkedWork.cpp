#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

node* insertAtHead(node *head, int val){
    node *newNode = new node();
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;
    if(head != NULL)
        head->prev = newNode;
    head = newNode;
    return head;
}


void printList(node *head){ 
    while(head != NULL){
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl; 
}

node* reverse(node* head)
{
    if(head == NULL || head->next == NULL)
        return head;

    struct node* temp = NULL;
    struct node* current = head;
 
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    
    if (temp != NULL)
        head = temp->prev;
        
    return head;
}


node* insertMiddle(node* prev, int data) {
    if(prev == NULL)
        return NULL;

    node* newNode = new node();
    newNode->data = data;
    newNode->next = prev->next;
    prev->next = newNode;
    newNode->prev = prev;

    if (newNode->next != NULL)
        newNode->next->prev = newNode;

    return newNode;
}

node* insertAfter(node* prevNode, int newData) {
    if (prevNode == NULL) {
        cout << "The given previous node cannot be NULL";
        return NULL;
    }

    node* newNode = new node();
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;

    if (newNode->next != NULL)
        newNode->next->prev = newNode;

    return newNode;
}

node* insertBefore(node* nextNode, int newData) {
    if (nextNode == NULL) {
        cout << "The given next node cannot be NULL";
        return NULL;
    }

    node* newNode = new node();
    newNode->data = newData;
    newNode->next = nextNode;
    newNode->prev = nextNode->prev;

    if (nextNode->prev != NULL)
        nextNode->prev->next = newNode;
    
    nextNode->prev = newNode;

    return newNode;
}


node* insertAtEnd(node* head, int newData) {
    node* newNode = new node();
    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }

    node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;

    return head;
}


int main(){
    struct node *head = NULL; 
    
    struct node *one = new node();
    struct node *two = new node();
    struct node *three = new node();

    one->data = 11;
    two->data = 8;
    three->data = 45;
    
    one->next = two;
    one->prev = NULL;

    two->next = three;
    two->prev = one;

    three->next = NULL;
    three->prev = two;

    
    head = one;
    
    cout<<"inserting at the head"<<endl;
    
    head = insertAtHead(head, 98);
    printList(head);
    
    cout<<"reversing the list"<<endl;
    
    head = reverse(head);
    printList(head);
    
    cout<<"inserting in the middle"<<endl;
    
    head = insertMiddle(two, 56);
    printList(head);
    
    cout<<"inserting after a given node"<<endl;
    
    node* prevNode = head->next;
    insertAfter(prevNode, 10);
    printList(head);
    
    cout<<"inserting before a given node"<<endl;
    
    node* nextNode = head->next->next;
    insertBefore(nextNode, 20);

    
    printList(head);
    
    cout<<"inserting at the end of the list"<<endl;
    head = insertAtEnd(head, 8);
    printList(head);
    
    
    return 0;
}

