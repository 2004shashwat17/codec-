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

    // Function to insert a node at the front of the list
    void push_front(int val) {
        Node* newNode = new Node(val); // dynamic allocation

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

    // Function to check if the list is a palindrome
    bool isPalindrome() {
        if (head == nullptr || head->next == nullptr) {
            return true;  // A list with 0 or 1 node is always a palindrome
        }

        // Step 1: Find the middle of the linked list using slow and fast pointers
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        Node* prev = nullptr;
        Node* curr = slow;
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Now, 'prev' is the head of the reversed second half of the list

        // Step 3: Compare the two halves of the list
        Node* firstHalf = head;
        Node* secondHalf = prev;
        while (secondHalf != nullptr) {
            if (firstHalf->data != secondHalf->data) {
                return false;  // Not a palindrome
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;  // The list is a palindrome
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

    ll.printList();

    return 0;
}
