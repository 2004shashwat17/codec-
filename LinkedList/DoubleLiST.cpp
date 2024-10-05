#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
}; 

class DoublyList {
public:
    Node* head;
    Node* tail;

    DoublyList() {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pop_front() {
        if (head == NULL) {
            cout << "List is empty, nothing to pop." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;  // If the list becomes empty, update tail
        }
        delete temp;
    }

    void pop_back() {
        if (tail == NULL) {
            cout << "List is empty, nothing to pop." << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        } else {
            head = NULL;  // If the list becomes empty, update head
        }
        delete temp;
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) {
                cout << " <=> ";
            } else {
                cout << " <=> NULL";
            }
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    DoublyList dbll;

    dbll.push_front(4);
    dbll.push_front(3);
    dbll.push_front(2);
    dbll.push_front(1);
    dbll.printList(); // Expected output: 1 <=> 2 <=> 3 <=> 4 <=> NULL

    dbll.push_back(5);
    dbll.printList(); // Expected output: 1 <=> 2 <=> 3 <=> 4 <=> 5 <=> NULL

    dbll.pop_front();
    dbll.printList(); // Expected output: 2 <=> 3 <=> 4 <=> 5 <=> NULL

    dbll.pop_back();
    dbll.printList(); // Expected output: 2 <=> 3 <=> 4 <=> NULL

    return 0;
}
