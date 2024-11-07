#include <iostream>
#include <deque>
using namespace std;

class Stack {
    deque<int> deq;

public:
    void push(int data) {
        deq.push_front(data);
    }

    void pop() {
        if (!deq.empty()) {
            deq.pop_front();
        } else {
            cout << "Stack is empty, cannot pop." << endl;
        }
    }

    int top() {
        if (!deq.empty()) {
            return deq.front();
        } else {
            cout << "Stack is empty." << endl;
            return -1; // Optional: return a sentinel value to indicate an empty stack
        }
    }

    bool empty() {
        return deq.empty();
    }
};

int main() {
    Stack s;

    for (int i = 1; i <= 5; i++) {
        s.push(i);
    }

    while (!s.empty()) { // Use a while loop to ensure we only pop if not empty
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}
