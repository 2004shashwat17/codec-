#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        
        // Check if merging into one pile is possible
        if ((n - 1) % (k - 1) != 0) {
            return -1;
        }

        // Priority queue (min-heap) to simulate merging
        priority_queue<int, vector<int>, greater<int>> pq(stones.begin(), stones.end());
        int cost = 0;

        // Simulate merging until only one pile remains
        while (pq.size() > 1) {
            // Ensure there are at least k piles to merge
            if (pq.size() < k) {
                return -1;
            }

            // Extract the smallest k piles and merge them
            int mergeCost = 0;
            vector<int> temp;
            for (int i = 0; i < k; i++) {
                mergeCost += pq.top();
                temp.push_back(pq.top());
                pq.pop();
            }

            // Add the merge cost
            cost += mergeCost;

            // Push the merged pile back into the heap
            pq.push(mergeCost);

            // Optional: Debugging output for the merge
            // cout << "Merged: ";
            // for (int val : temp) cout << val << " ";
            // cout << "-> " << mergeCost << ", Total Cost: " << cost << endl;
        }

        return cost;
    }
};

int main() {
    Solution sol;

    vector<int> stones1 = {3, 2, 4, 1};
    int k1 = 2;
    cout << "Minimum Cost: " << sol.mergeStones(stones1, k1) << endl;

    vector<int> stones2 = {3, 2, 4, 1};
    int k2 = 3;
    cout << "Minimum Cost: " << sol.mergeStones(stones2, k2) << endl;

    vector<int> stones3 = {3, 5, 1, 2, 6};
    int k3 = 3;
    cout << "Minimum Cost: " << sol.mergeStones(stones3, k3) << endl;

    return 0;
}
