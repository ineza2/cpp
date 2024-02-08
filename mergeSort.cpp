#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node *next;
};

Node *merge(Node *a, Node *b)
{

    if(a == NULL)
        return b;
    if(b == NULL)
        return a;
 
    Node *c;
 
    if(a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }
 
    return c;
}
Node *mid_point(Node *head)
{
    if(head == NULL || head->next == NULL)
        return head;
    Node *fast = head;
    Node *slow = head;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next;
        if(fast->next == NULL)
            break;
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
Node* merge_sort(Node *head)
{
    if(head == NULL || head->next == NULL)
        return head;
 
    
    Node *mid = mid_point(head);
    Node *a = head;
    Node *b = mid->next;
 
    mid->next = NULL;
 
    
    a = merge_sort(a);
    b = merge_sort(b);
 
 
    Node *c = merge(a, b);
 
    return c;
}

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
    
    head = merge_sort(head);

    cout << "Sorted list: ";
    travese(head);

    
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

}
 

