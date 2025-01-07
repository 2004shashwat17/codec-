#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freqMap; // To store the frequency of each number
        
        // Count the frequency of each number
        for (int num : nums) {
            freqMap[num]++;
        }
        
        // Sort the array based on frequency, and by value in decreasing order if frequencies are equal
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (freqMap[a] == freqMap[b]) {
                return a > b; // If frequencies are equal, sort by value in decreasing order
            }
            return freqMap[a] < freqMap[b]; // Otherwise, sort by frequency in increasing order
        });
        
        return nums;
    }
};

int main() {
    vector<int> nums = {1, 1, 2, 2, 2, 3}; // Example input
    Solution solution;
    vector<int> result = solution.frequencySort(nums);
    
    // Print the result
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
