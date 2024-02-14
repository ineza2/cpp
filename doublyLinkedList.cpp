#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

// Function to insert node at the beginning
node* insertAtHead(node *head, int val){
    node *newNode = new node(); // Changed Node to node
    newNode->data = val;
    newNode->prev = NULL; // Changed null to nullptr
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to print the linked list
void printList(node *head){ // Changed Node to node
    while(head != NULL){ // Changed NULL to nullptr
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl; // Changed \n to endl
}

int main(){
    struct node *head = NULL; // Changed null to nullptr
    
    struct node *one = new node();
    struct node *two = new node();
    struct node *three = new node();

    // Assign data values
    one->data = 11;
    two->data = 8;
    three->data = 45;
    
    one->next = two;
    one->prev = NULL;

    two->next = three;
    two->prev = one;

    three->next = NULL;
    three->prev = two;

    /* Save address of first node in head */
    head = one;
    
    head = insertAtHead(head, 98);
    printList(head);
    
    return 0; // Added return statement
}

