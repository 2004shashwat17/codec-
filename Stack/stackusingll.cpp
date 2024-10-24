#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Create a stack using linked list
template<class T>
class Node{
    public:
        T data;
        Node* next;
        Node(T val) {
            data = val;
            next = NULL;
        }
};

template<class T>
class Stack{
    Node<T>* head;
    public:
    Stack() {
        head = NULL;
    }
    void push(T val){
        Node<T>* newNode = new Node<T>(val);
        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }
    void pop(){
        if (head == NULL) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    T top(){
        if (head == NULL) {
            throw out_of_range("Stack is empty");
        }
        return head->data;
    }
    bool isEmpty(){
        return head == NULL;
    }
};

int main(){
    Stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    while (!s.isEmpty())
    {
        cout << s.top() << " "; // Output: 1, 2, 3
        s.pop();
    }
    cout << endl;
    return 0;
}
