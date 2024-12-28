#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int connectRopes(vector<int> ropes, int k) {
    // Create a min-heap from the input ropes
    priority_queue<int, vector<int>, greater<int>> pq(ropes.begin(), ropes.end()); // O(n)
    int cost = 0; 

    // Combine ropes until only one rope is left
    while (pq.size() > 1) {
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();

        cost += min1 + min2;
        pq.push(min1 + min2);
    }

    // Print the minimum cost
    cout << "k = " << k << ", min cost = " << cost << endl;
    return cost;
}

int main() {
    vector<int> ropes = {4, 3, 2, 6};
    int k = 3; // Example value of k
    connectRopes(ropes, k);
    return 0;
}
