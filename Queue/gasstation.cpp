#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int cancomplete(vector<int>& fuel, vector<int>& dist) {
    int n = fuel.size();
    deque<int> dq;
    int startindex = 0, totalFuel = 0, currFuel = 0;

    // Traverse the circular array
    for (int i = 0; i < 2 * n; i++) {
        int idx = i % n; // Wrap around the circular array
        int netFuel = fuel[idx] - dist[idx];
        totalFuel += netFuel; // Track total fuel to check feasibility
        currFuel += netFuel;  // Track current fuel for the current start
        dq.push_back(netFuel);

        // If current cumulative fuel is negative, reset the starting point
        while (currFuel < 0 && !dq.empty()) {
            currFuel -= dq.front();
            dq.pop_front();
            startindex++;
        }

        // If we have formed a complete circuit starting from startindex
        if (i >= startindex + n - 1) {
            return startindex;
        }
    }

    // If totalFuel is negative, it is impossible to complete the circuit
    return totalFuel >= 0 ? startindex : -1;
}

int main() {
    vector<int> fuel = {1, 2, 3, 4, 5};
    vector<int> dist = {3, 4, 5, 1, 2};
    int result = cancomplete(fuel, dist);
    cout << "Starting index to complete the circuit: " << result << endl;
    return 0;
}
