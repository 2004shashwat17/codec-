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
                cout << " -> "; // Improved output format
            }
            temp = temp->next;
        }
        cout << endl;
    }

    void removeCycle() {
        // Detect cycle
        Node* slow = head;
        Node* fast = head;
        bool isCycle = false;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                cout << "Cycle exists\n";
                isCycle = true;
                break;
            }
        }
        if (!isCycle) {
            cout << "Cycle doesn't exist\n";
            return;
        }

        // Find the starting node of the cycle
        slow = head;
        if (slow == fast) {
            // Special case: the cycle starts from head
            while (fast->next != slow) {
                fast = fast->next;
            }
            fast->next = NULL; // Remove cycle
        } else {
            Node* prev = fast;
            while (slow != fast) {
                slow = slow->next;
                prev = fast;
                fast = fast->next;
            }
            prev->next = NULL; // Remove cycle
        }
    }  

    void createCycle() {
        if (tail != NULL) {
            tail->next = head;  // Creates a cycle
        }
    } 

    Node* getHead() {
        return head; // Added function to access head
    }
};

int main() {
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    // Creating a cycle: 4 -> 1
    ll.createCycle();

    ll.removeCycle(); // Call removeCycle on the list instance

    ll.printList(); // Call printList on the list instance
    return 0;
}
 