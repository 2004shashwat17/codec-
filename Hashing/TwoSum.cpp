#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twosum(vector<int>& nums, int target) {
        unordered_map<int, int> numIndexMap; // To store number and its index
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (numIndexMap.find(complement) != numIndexMap.end()) {
                return {numIndexMap[complement], i}; // Return the indices
            }
            numIndexMap[nums[i]] = i; // Add current number and its index to the map
        }
        return {}; // Return empty vector if no solution is found (though the problem guarantees one solution)
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15}; // Input array
    int target = 9; // Target sum
    
    Solution solution; // Create an instance of the Solution class
    vector<int> result = solution.twosum(nums, target); // Call the twosum function
    
    // Print the result
    if (!result.empty()) {
        cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No solution found!" << endl;
    }

    return 0;
}
