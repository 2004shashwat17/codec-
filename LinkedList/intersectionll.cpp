#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = nullptr;
        tail = nullptr;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    int getsize(Node* head) {
        int size = 0;
        while (head != nullptr) {
            head = head->next;
            size++;
        }
        return size;
    }

    Node* getintersectionNode(Node* headA, Node* headB) {
        int m = getsize(headA);
        int n = getsize(headB);
        Node* t1 = headA;
        Node* t2 = headB;
        int diff = 0;

        // Align both pointers to the same starting position
        if (m >= n) {
            diff = m - n;
            for (int i = 0; i < diff; i++) {
                t1 = t1->next;
            }
        } else {
            diff = n - m;
            for (int i = 0; i < diff; i++) {
                t2 = t2->next;
            }
        }

        // Traverse both lists together to find the intersection point
        while (t1 != nullptr && t2 != nullptr && t1 != t2) {
            t1 = t1->next;
            t2 = t2->next;
        }
        return t1; // Return intersection node or nullptr
    }
};

int main() {
    List l1;
    List l2;

    l1.push_front(7);
    l1.push_front(6);
    l1.push_front(3);
    l1.push_front(2);
    l1.push_front(1);

    l2.push_front(5);
    l2.push_front(4);

    // Creating intersection:
    l2.head->next->next = l1.head->next->next->next; // Point to node with data 6

    // Call the getintersectionNode method on the List object
    Node* intersectionNode = l1.getintersectionNode(l1.head, l2.head);
    if (intersectionNode != nullptr) {
        cout << "The intersection point is at node with data: " << intersectionNode->data << endl;
    } else {
        cout << "There is no intersection point." << endl;
    }

    return 0;
}
