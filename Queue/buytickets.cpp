#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int timeRequiredToBuy(vector<int>& tickets, int k) {
    // Queue to store {number of tickets needed, original index}
    queue<pair<int, int>> q;
    int n = tickets.size();

    // Populate the queue with each person's tickets and original index
    for (int i = 0; i < n; i++) {
        q.push({tickets[i], i});
    }

    int time = 0; // Time counter to track total time spent

    // Process the queue
    while (!q.empty()) {
        auto [num_tickets, og_i] = q.front();
        q.pop();

        // Decrease ticket count by one for this person
        num_tickets--;
        time++; // Increase time as one unit passes

        // Check if this is the person at index k and they are done
        if (og_i == k && num_tickets == 0) {
            return time;
        }

        // If they still have tickets to buy, push them back in the queue
        if (num_tickets > 0) {
            q.push({num_tickets, og_i});
        }
    }

    return time;
}

int main() {
    vector<int> tickets = {2, 3, 2};
    int k = 2;
    
    int result = timeRequiredToBuy(tickets, k);
    cout << "Time required for person at index " << k << " to buy tickets: " << result << endl;

    return 0;
}
