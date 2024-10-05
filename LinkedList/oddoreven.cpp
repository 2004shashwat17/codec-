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
        cout << " -> NULL" << endl;
    }

    Node* oddEvenList(Node* head) {
        // Case of linked list length 0, 1, or 2
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return head;
        }

        Node* evenStart = head->next; // Pointer to the start of even list
        Node* odd = head;              // Pointer to the current node in the odd list
        Node* even = head->next;       // Pointer to the current node in the even list

        // Traverse and rearrange nodes
        while (odd->next && even->next) {
            odd->next = even->next;        // Link the current odd node to the next odd node
            even->next = odd->next->next;  // Link the current even node to the next even node
            odd = odd->next;               // Move the odd pointer to the next odd node
            even = even->next;             // Move the even pointer to the next even node
        }

        odd->next = evenStart;             // Connect the end of the odd list to the start of the even list

        return head;                       // Return the modified head
    }

    void rearrange() {
        head = oddEvenList(head);         // Update the head after rearrangement
    }
};

int main() {
    List ll;

    // Add 10 values to the linked list in sequential order
    for (int i = 1; i <= 10; i++) {
        ll.push_back(i);
    }

    cout << "Original List: ";
    ll.printList();  

    ll.rearrange(); // Rearranging the list
    cout << "Rearranged List: ";
    ll.printList();

    return 0;
}
