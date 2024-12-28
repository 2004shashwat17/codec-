#include <iostream>
#include <vector>
using namespace std;

class Heap {
    vector<int> vec; // max Heap

public:
    void heapify(int i) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int maxIdx = i;

        if (l < vec.size() && vec[l] > vec[maxIdx]) {
            maxIdx = l;
        }
        if (r < vec.size() && vec[r] > vec[maxIdx]) {
            maxIdx = r;
        }
        if (maxIdx != i) {
            swap(vec[i], vec[maxIdx]);
            heapify(maxIdx); // Recurse on the affected subtree
        }
    }

    void push(int val) { // O(log n)
        vec.push_back(val); // Add at the end

        int x = vec.size() - 1; // Index of the new element
        int parI = (x - 1) / 2; // Parent index

        while (x > 0 && vec[x] > vec[parI]) { // Fix the heap upwards
            swap(vec[x], vec[parI]);
            x = parI;
            parI = (x - 1) / 2;
        }
    }

    void pop() { // O(log n)
        if (vec.empty()) {
            cout << "Heap is empty!" << endl;
            return;
        }
        swap(vec[0], vec[vec.size() - 1]); // Swap root with the last element
        vec.pop_back();                   // Remove the last element
        heapify(0);                       // Restore heap property
    }

    int top() { // O(1)
        if (vec.empty()) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        return vec[0]; // Return the root (highest priority element)
    }

    bool empty() {
        return vec.empty();
    }
};

int main() {
    Heap heap;
// priority_queue<int , vector<int>, greater<int>> pq;
    // pq.push(5);
    // pq.push(10);
    // pq.push(9);
    // pq.push(7);
    // pq.push(3);
    heap.push(9);
    heap.push(4);
    heap.push(8);
    heap.push(1);
    heap.push(2);
    heap.push(5);

    while (!heap.empty()) {
        cout << "top = " << heap.top() << endl;
        heap.pop();
    }

    return 0;
}
