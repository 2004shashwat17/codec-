#include <iostream>
#include <deque>
using namespace std;

class Queue {
    deque<int> deq;

public:
    void push(int data) {
        deq.push_back(data);
    }

    void pop() {
        if (!deq.empty()) {
            deq.pop_front();
        }
    }

    int front() { // Return type changed to int
        if (!deq.empty()) {
            return deq.front();
        }
        return -1; // Optional: Return a default value if queue is empty
    }

    bool empty() {
        return deq.empty();
    }
};

int main() {
    Queue q;
    for (int i = 1; i <= 5; i++) {
        q.push(i);
    }
    while (!q.empty()) { // Check if the queue is empty before accessing front
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}
