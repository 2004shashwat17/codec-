#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
public:
    MedianFinder() {
        // No initialization needed
    }
    
    void addNum(int num) {
        // Add to maxHeap (smaller half)
        maxHeap.push(num);
        
        // Ensure all elements in maxHeap are <= elements in minHeap
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        
        // Balance the heaps if sizes differ
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        // If odd number of elements, return the top of maxHeap
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        // If even number of elements, return the average of tops of both heaps
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }

private:
    priority_queue<int> maxHeap; // Max heap for the smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap for the larger half
};

int main() {
    MedianFinder medianFinder;

    // Test case
    medianFinder.addNum(1);    // Add number 1
    medianFinder.addNum(2);    // Add number 2
    cout << "Median: " << medianFinder.findMedian() << endl; // Should output 1.5

    medianFinder.addNum(3);    // Add number 3
    cout << "Median: " << medianFinder.findMedian() << endl; // Should output 2.0

    medianFinder.addNum(4);    // Add number 4
    cout << "Median: " << medianFinder.findMedian() << endl; // Should output 2.5

    medianFinder.addNum(5);    // Add number 5
    cout << "Median: " << medianFinder.findMedian() << endl; // Should output 3.0

    return 0;
}
