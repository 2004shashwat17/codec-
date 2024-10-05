#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
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

    void push_front(int val) {
        Node* newNode = new Node(val);
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

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    int getSize() {
        int size = 0;
        Node* temp = head;
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }
        return size;
    }

    Node* kthfromend(int k) {
        Node* temp = head;
        int size = getSize();
        for (int i = 0; i < size - k; i++) {
            temp = temp->next;
        }
        return temp;
    }

    void swapNodes(int k) {
        // Find the k-th node from the beginning
        Node* left = head;
        for (int i = 0; i < k - 1; i++) {
            left = left->next;
        }

        // Find the k-th node from the end
        Node* right = kthfromend(k);

        // Swap their values
        int temp = left->data;
        left->data = right->data;
        right->data = temp;
    }
};

int main() {
    List ll;

    // Add 10 values to the linked list in sequential order
    for (int i = 1; i <= 10; i++) {
        ll.push_back(i);
    }

    // Print the linked list to verify the values
    cout << "Original List:" << endl;
    ll.printList();  

    // Swap the 2nd node from the beginning with the 2nd node from the end
    ll.swapNodes(2);

    // Print the linked list after swapping
    cout << "List after swapping 2nd node from start and 2nd node from end:" << endl;
    ll.printList();

    return 0;
}
