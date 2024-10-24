#include <iostream>
#include <stack>
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

    // Function to insert a node at the front of the list
    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Function to print the list
    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Function to check if the list is a palindrome using a stack
    bool isPalindrome() {
        if (head == nullptr || head->next == nullptr) {
            return true;  // A list with 0 or 1 node is always a palindrome
        }

        stack<int> s;
        Node* temp = head;

        // Step 1: Push all node values onto the stack
        while (temp != NULL) {
            s.push(temp->data);
            temp = temp->next;
        }

        // Step 2: Traverse the list again and compare with the stack
        temp = head;
        while (temp != NULL) {
            int topVal = s.top();
            s.pop();

            // If the current node value doesn't match the stack's top, return false
            if (temp->data != topVal) {
                return false;
            }

            temp = temp->next;
        }

        return true;  // If all values matched, the list is a palindrome
    }
};

int main() {
    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);

    ll.printList();

    // Check if the list is a palindrome
    if (ll.isPalindrome()) {
        cout << "The list is a palindrome\n";
    } else {
        cout << "The list is not a palindrome\n";
    }

    return 0;
}
