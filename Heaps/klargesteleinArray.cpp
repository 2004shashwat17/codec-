#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int> &nums, int k) {
    // Create a min-heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Iterate through the numbers
    for (int num : nums) {
        minHeap.push(num); // Push the current number into the heap

        // If the heap size exceeds k, remove the smallest element
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    // The root of the min-heap is the kth largest element
    return minHeap.top();
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4}; // Input array
    int k = 2; // Specify k
    int result = findKthLargest(nums, k); // Call the function
    cout << "kth largest element: " << result << endl; // Output the result
    return 0;
}
