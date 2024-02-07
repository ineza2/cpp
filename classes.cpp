#include<iostream>
using namespace std;

class Student{
public:
    int age;
    string name;
    string school;
    Student *next; // Pointer to the next student
    Student() {}
    Student(int a, string n, string s){
        age = a;
        name = n;
        school = s;
        next = nullptr;
    }
    void printDetails() {
        cout << "age: " << age << ", name: " << name << ", school: " << school << endl;    
    }
};

void printlist(Student *head){
    while (head != nullptr){
        head->printDetails(); // Using the printDetails method of the Student class
        head = head->next;
    }
}

int main() {
    Student s1(18, "Mary", "RCA");
    Student s2(10, "Mike", "RCA");
    Student *s3 = new Student(20, "Divin", "RCA");
    Student *s4 = new Student(25, "D'Amour", "RCA");
    Student s5(17, "Kamanzi", "Nyabihu tvet");
    s1.next = &s2;
    s2.next = s3;
    s3->next = s4; // Fixing pointer assignment
    s4->next = &s5; // Fixing pointer assignment
    Student *head = &s1; // Corrected assignment
    printlist(head);
        
    delete s3;
    delete s4; // Deleting dynamically allocated memory
    return 0;
}

