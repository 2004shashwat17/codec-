#include <iostream>
#include <vector>

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
private:
    Node* head;  // Make head private
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

    Node* getHead() { // Public method to get the head
        return head;
    }

    void setHead(Node* newHead) { // Public method to set the head
        head = newHead;
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

    // Merge two sorted linked lists
    Node* merge(Node* list1, Node* list2) {
        Node* merged = new Node(-1); // Dummy node
        Node* mptr = merged;          // Pointer to track the end of the merged list
        Node* left = list1;          // Pointer to traverse list1
        Node* right = list2;         // Pointer to traverse list2

        while (left != NULL && right != NULL) {
            if (left->data <= right->data) {
                mptr->next = left;   // Link to the smaller node
                mptr = mptr->next;   // Move the mptr to next
                left = left->next;   // Advance in list1
            } else {
                mptr->next = right;  // Link to the smaller node
                mptr = mptr->next;   // Move the mptr to next
                right = right->next; // Advance in list2
            }
        }

        // Append any remaining nodes
        if (left != NULL) {
            mptr->next = left;
        }
        if (right != NULL) {
            mptr->next = right;
        }
        return merged->next; // Return the head of the merged list
    }

    // Merge k sorted linked lists
    Node* mergeKLists(vector<Node*>& lists) {
        if (lists.size() == 0) {
            return NULL; // No lists to merge
        }
        if (lists.size() == 1) {
            return lists[0]; // Only one list, return it
        }

        Node* head = lists[0]; // Initialize head with the first list
        for (int i = 1; i < lists.size(); i++) {
            head = merge(head, lists[i]); // Merge with the next list
        }
        return head; // Return the final merged list
    }
};

int main() {
    List ll;

    // Add values to the linked list in sequential order
    for (int i = 1; i <= 10; i++) {
        ll.push_back(i);
    }

    cout << "Original List: ";
    ll.printList();

    // Creating multiple sorted linked lists for testing
    List l1, l2, l3;
    l1.push_back(1);
    l1.push_back(3);
    l2.push_back(6);
    l2.push_back(8);
    l3.push_back(9);
    l3.push_back(10);

    // Storing the heads of these linked lists in a vector
    vector<Node*> lists;
    lists.push_back(l1.getHead()); // Head of l1
    lists.push_back(l2.getHead()); // Head of l2
    lists.push_back(l3.getHead()); // Head of l3

    // Merging the k sorted linked lists
    List mergedList;
    mergedList.setHead(mergedList.mergeKLists(lists)); // Store the merged head

    cout << "Merged List: ";
    mergedList.printList();

    return 0;
}
