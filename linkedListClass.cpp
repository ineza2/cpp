//#include <iostream>
//using namespace std;
//class Student {
//	public:
//    string name;
//    int age;
//    string school;
//    Student() {}
//    Student(int a, string n, string s) {
//        age=a;
//        name=n;
//        school=s;
//    }
//    void printDetails () {
//    cout<<"age:"<<age<<" name:"<<name<<" school:"<<endl;
//    }
//};
//int main () {
//    Student student1(18, "Henri", "RCA");
//    student1.printDetails();
//return (0);
//} 

#include<iostream>
using namespace std;
template <typename T>

struct Node{
	T data;
	Node *next;
	Node(){	}
	Node(T d){
		data=d;
		next=NULL;	}
};

template <typename T>
void printList(Node<T> *head){
	int count=0;
	while(head !=NULL){
		cout<<head->data<<"->";
		head=head->next;
		count++;
	}
	cout<<"nbr of elements: "<<count<<endl;
}
template <typename T>
Node<T>* addAtHead(Node<T> *head, T value){
	Node<T> *newNode=new Node<T >(value);
	newNode->next=head;
	head=newNode;
	return head;
}
//Node<T>* addAtTail(Node<T> *next, T value){
//	Node<T> *newNode=new Node<T >(value);
//	newNode->next= next;
//	next=newNode;
//	return next;
//} 


template <typename T>
Node<T>* addAtTail(Node<T> *head, T value) {
    Node<T> *newNode = new Node<T>(value);
        Node<T> *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
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
int main(){
	Node<int> *n1=new Node<int>(10);
//	cout<<n1->data<<endl;
	Node<int> *n2= new Node<int>(20);
//	cout<<n2->data<<endl;
	Node<int> *n3= new Node<int>(30);
//	cout<<n3->data<<endl;
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

//Node* head=userData();
//print(head);
//return 0;

Node<int> *userHead = userData<int>();
    cout << "User input list:" << endl;
    printList(userHead);
    
delete n1;
    delete n2;
    delete n3;
	return 0;
}


//#include<iostream>
//using namespace std;
//class Student{
//	public:
//	int age;
//	string name;
//	string school;
//	Student() {}
//	Student (int a, string n, string s){
//		age = a;
//		name = n;
//		school = s;
////		next = NULL;
//	}
//	void printDetails() {
//		cout << "age: " << age << ", name: " << name << ", school: " << school << endl;	
//	}
//};
//void printlist (Student *head){
//	while (head != NULL){
//		cout << "age: " <<head -> age << ", name: " << head -> name << ", school: " << head -> school << endl;	
//	}
//}
//int main() {
//	Student s1 (18, "Mary", "RCA");
//	Student s2 (10, "Mike", "RCA");
//	Student *s3 = new Student(20, "Divin", "RCA");
//	Student *s4 = new Student(25, "D'Amour", "RCA");
//	Student s5(17, "Kamanzi", "Nyabihu tvet");
//	s1.next = &s2;
//	s2.next = s3;
//	s3.next = s4;
//	s4.next = &s5;
//	Student *head = s1;
//	printlist(head);
//		
//	delete s3;
//	return 0;
//}
