#include <iostream>
using namespace std;
class Student {
	public:
    string name;
    int age;
    string school;
    Student() {}
    Student(int a, string n, string s) {
        age=a;
        name=n;
        school=s;
    }
    void printDetails () {
    cout<<"age:"<<age<<" name:"<<name<<" school:"<<endl;
    }
};
int main () {
    Student student1(18, "Henri", "RCA");
    student1.printDetails();
return (0);
} 
