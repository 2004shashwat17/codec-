#include<iostream>
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
public:
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
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
            } else {
                cout << " -> NULL";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    Node* splitAtHead(Node* head) {
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prev != NULL) {
            prev->next = NULL;
        }
        return slow; // slow = right head
    }

    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        return prev; // prev is head of reversed LL
    }

    Node* ZigZagLL(Node* head) {
        Node* rightHead = splitAtHead(head);
        Node* rightHeadRev = reverse(rightHead);

        // Alternate merging: 
        Node* left = head;
        Node* right = rightHeadRev;
        Node* tail = nullptr;

        while (left != NULL && right != NULL) {
            Node* nextLeft = left->next;
            Node* nextRight = right->next;

            left->next = right;
            right->next = nextLeft;

            tail = right;

            left = nextLeft;
            right = nextRight;
        }

        if (right != NULL) {
            tail->next = right;
        }

        return head;
    }
};

int main() {
    List ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    // 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    ll.printList();

    ll.head = ll.ZigZagLL(ll.head);
    ll.printList();

    return 0;
}
