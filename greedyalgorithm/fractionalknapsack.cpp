#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<double, int> p1, pair<double, int> p2) {
    return p1.first > p2.first; // Sort in descending order based on ratio
}

double fractionalKnapsack(vector<int> val, vector<int> wt, int W) {
    int n = val.size();
    vector<pair<double, int>> ratio(n); // Pair (ratio, index)

    // Calculate value-to-weight ratio
    for (int i = 0; i < n; i++) {
        double r = val[i] / (double)wt[i];
        ratio[i] = make_pair(r, i);
    }

    // Sort items by ratio in descending order
    sort(ratio.begin(), ratio.end(), compare);

    double ans = 0.0; // Use double for fractional value
    for (int i = 0; i < n; i++) {
        int idx = ratio[i].second;
        
        // If item can fit fully in the knapsack
        if (wt[idx] <= W) {
            ans += val[idx];
            W -= wt[idx];
        } 
        // Add fraction of the item that fits
        else {
            ans += ratio[i].first * W;
            break;
        }
    }

    cout << "Max value = " << ans << endl;
    return ans;
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 20};
    int W = 50;

    fractionalKnapsack(val, wt, W);
    return 0;
}
