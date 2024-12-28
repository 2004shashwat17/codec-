#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> freqMap;

    // Count the frequency of each task
    for (char task : tasks) {
        freqMap[task]++;
    }

    // Create a max heap (priority queue) for task frequencies
    priority_queue<int> maxHeap;
    for (auto& entry : freqMap) {
        maxHeap.push(entry.second);
    }

    int maxFreq = maxHeap.top(); // The highest frequency of any task
    int maxFreqCount = 0;

    // Count how many tasks have the same maximum frequency
    while (!maxHeap.empty() && maxHeap.top() == maxFreq) {
        maxFreqCount++;
        maxHeap.pop();
    }

    // Calculate the minimum intervals
    int partCount = maxFreq - 1; // Number of gaps between the most frequent tasks
    int partLength = n - (maxFreqCount - 1); // Available idle slots in each part
    int emptySlots = partCount * partLength; // Total idle slots
    int availableTasks = tasks.size() - (maxFreq * maxFreqCount); // Tasks left to fill slots
    int idles = max(0, emptySlots - availableTasks); // Remaining idle slots

    return tasks.size() + idles; // Total time = tasks + idle slots
}

int main() {
    vector<char> tasks1 = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n1 = 2;
    cout << "Output: " << leastInterval(tasks1, n1) << endl;

    vector<char> tasks2 = {'A', 'C', 'A', 'B', 'D', 'B'};
    int n2 = 1;
    cout << "Output: " << leastInterval(tasks2, n2) << endl;

    vector<char> tasks3 = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n3 = 3;
    cout << "Output: " << leastInterval(tasks3, n3) << endl;

    return 0;
}
