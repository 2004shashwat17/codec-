#include<iostream>
using namespace std;

class Node {
public:    
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    } 

    ~Node(){
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }
};

class List {
    Node* head;
    Node* tail;

public:
    List() {
        head = NULL;
        tail = NULL;
    }   

    ~List(){
        if(head != NULL){
            delete head;
            head = NULL;
        }
    }

    void push_front(int val) {
        Node* newNode = new Node(val); // dynamic allocation

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }   
    } 

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) { 
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insert(int val, int pos) {
        Node* newNode = new Node(val);

        // If inserting at the front
        if (pos == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            if (temp == NULL) {
                cout << "Position is INVALID\n";
                return;
            }
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position is INVALID\n";
            return;
        }

        // Inserting the new node at the found position
        newNode->next = temp->next;
        temp->next = newNode;

        // Update tail if inserted at the end
        if (newNode->next == NULL) {
            tail = newNode;
        }
    }

    void pop_front() {
        if(head == NULL){
            cout << "LL is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
        Node* temp = head;

        while(temp->next->next != NULL){
            temp = temp -> next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n"; 
    }

    int searchItr(int key) { //0(n)
        Node* temp = head;
        int idx = 0;

        while(temp != NULL){
           if(temp->data == key) {
                return idx;
           } 
           temp = temp->next;
           idx++;
        }
        return -1;
    }
    int helper(Node* temp, int key){
        if(temp == NULL){
            return -1;
        }

        if(temp->data == key){
            return 0;
        }
        int idx =helper(temp->next, key);
        if(idx == -1){
            return -1;
        }
    }
    int searchRec(int key){
        return helper(head,key);
    }
};

int main() {
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(4);
    ll.push_back(5);
    ll.printList(); // 1->2->3->4->5->NULL
    cout << ll.searchItr(5) << endl;
    cout << ll.searchRec(4) << endl;
    ll.printList(); // 1->2->100->3->4->5->NULL
    ll.pop_front();
    ll.printList(); //2->3->null
    ll.pop_back();
    ll.printList(); // 1->2->null
    return 0;
}
