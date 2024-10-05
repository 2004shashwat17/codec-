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

    void deleteNodes(int m, int n) {
        Node* current = head;
        while (current) {
            // Retain `m` nodes
            for (int i = 1; i < m && current; ++i) {
                current = current->next;
            }

            // If we reached the end, return
            if (!current) {
                return;
            }

            // Start deleting `n` nodes
            Node* temp = current->next;
            for (int i = 0; i < n && temp; ++i) {
                Node* nodeToDelete = temp;
                temp = temp->next;
                delete nodeToDelete;
            }

            // Link the retained part to the rest of the list
            current->next = temp;

            // Move `current` to the next part to retain
            current = temp;
        }
    }
};

int main() {
    List ll;

    // Add 20 values to the linked list in sequential order
    for (int i = 1; i <= 10; i++) {
        ll.push_back(i);
    }

    // Print the linked list to verify the values
    ll.printList();  // Expected output: 1 -> 2 -> 3 -> 4 -> ... -> 20

    // Delete nodes: retain 2 nodes, delete the next 3 nodes
    ll.deleteNodes(2, 3);

    // Print the linked list after deletion
    ll.printList();  // Expected output: 1 -> 2 -> 6 -> 7 -> 11 -> 12 -> 16 -> 17 -> ...

    return 0;
}
