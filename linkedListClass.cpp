#include<iostream>
using namespace std;

template <typename T>
struct Node{
    T data;
    Node *next;
    Node() {}
    Node(T d){
        data = d;
        next = NULL;
    }
};

template <typename T>
void printList(Node<T> *head){
    int count=0;
    while(head !=NULL){
        cout<<head->data<<"->";
        head=head->next;
        count++;
    }
//    cout<<"nbr of elements: "<<count<<endl;
    cout<<"\n"<<endl;
}

template <typename T>
Node<T>* addAtHead(Node<T> *head, T value){
    Node<T> *newNode=new Node<T >(value);
    newNode->next=head;
    head=newNode;
    return head;
}

template <typename T>
Node<T>* addAtTail(Node<T> *head, T value) {
    Node<T> *newNode = new Node<T>(value);
    if (head == NULL) {
        head = newNode;
    } else {
        Node<T> *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

template <typename T>
Node<T>* userData(){
    T data;
    cin >> data;
    Node<T> *head = NULL;
    Node<T> *tail = NULL;
    while (data != -1){
        Node<T> *n = new Node<T>(data);
        if (head == NULL){
            head = n;
            tail = n;
        } else {
            n->next = head;
            head = n;
        }
        cin >> data;
    }
    return head;
}

template <typename T>
Node<T>* insertAtPos(Node<T> *head, int i, T data){
    if(i<0){
        return head;
    }
    if(i==0){
        Node<T>* n = new Node<T>(data);
        n->next = head;
        head = n;
        return head;
    }
    Node<T> *temp = head;
    int count = 1;
    while(count<i && temp!=NULL){
        temp = temp->next;
        count++;
    }
    if(temp){
        Node<T> *n = new Node<T>(data);
        n->next = temp->next;
        temp->next = n;
    }
    return head;
}

template <typename T>
Node<T>* deleteFirstNode(Node<T> *head){
    if(head == NULL) 
        return NULL;
    Node<T>* temp = head;
    head = temp->next;
    delete temp;
    return head;
}

template <typename T>
Node<T>* deleteLastNode(Node<T>* head){
	if(head==NULL)return NULL;
	if(head->next==NULL){
		delete head;
		return NULL;
	}
	
	Node<T>* second_last=head;
	while(second_last->next->next !=NULL)second_last=second_last->next;
	
	delete(second_last->next);
	second_last->next=NULL;
	
	return head;
}

template <typename T>
Node<T>* deleteNode(Node<T>* head, int i){
   if(i<=0){
      return head;
   }
   if(i==1 && head){
    Node<T>* newHead = head->next;
    head->next = NULL;

    delete head;
    return newHead;
   }
   
  Node<T>* curr = head;
   int count = 1;
   while(count<i-1 && curr!=NULL){
    curr = curr->next;
    count++;
   }
       if(curr && curr->next){
     Node<T> *temp = curr->next;
     
     curr->next = curr->next->next;
     temp->next=NULL;
     
     delete temp;
     
     return head;
   }
   return head;
}




int main(){
    Node<int> *n1=new Node<int>(10);
    Node<int> *n2= new Node<int>(20);
    Node<int> *n3= new Node<int>(30);
    n1->next=n2;
    n2->next=n3;
    Node<int> *head=n1;

    printList(head);
    cout<<"after adding element at the head"<<endl;
    head=addAtHead(head,8);
    printList(head);

    cout<<"after adding element at the tail"<<endl;
    head=addAtTail(head, 22);
    printList(head);

    cout<<"after inserting element at position"<<endl;
    head=insertAtPos(head,4,250);
    printList(head);
    
    cout<<"after deleting the head"<<endl;
    head=deleteFirstNode(head);
    printList(head);
    
    cout<<"after deleting the tail"<<endl;
    head=deleteLastNode(head);
    printList(head);
    
    cout<<"after deleting at any position"<<endl;
    head=deleteNode(head, 2);
    printList(head);
    


    Node<int> *userHead = userData<int>();
    cout << "User input list:" << endl;
    printList(userHead);
//    
    delete n1;
    delete n2;
    delete n3;
    return 0;
}

