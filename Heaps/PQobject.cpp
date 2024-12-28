#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

class Student { //"<" overload
    public:
        string name;
        int marks;

        Student(string name, int marks) {
            this->name = name;
            this->marks = marks;
        }

        bool operator < (const Student &obj) const {
            return this->marks < obj.marks;
        }
};

int main(){
    priority_queue<Student> pq;

    pq.push(Student("shashwat", 50));
    pq.push(Student("aman", 90));
    pq.push(Student("chetan", 65));

    while(!pq.empty()){
        cout << "top = " << pq.top().name << " , " << pq.top().marks<< endl;
        pq.pop();
    }
    return 0;
}