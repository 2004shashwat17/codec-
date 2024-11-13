#include <iostream>
#include <vector>
#include <numeric>   // for accumulate
#include <algorithm> // for max_element
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        // Define the binary search bounds
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        
        // Binary search to find the minimized largest sum
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (canSplit(nums, k, mid)) {
                // If we can split with this max sum, try smaller
                right = mid;
            } else {
                // If we cannot split with this max sum, try larger
                left = mid + 1;
            }
        }
        
        return left;
    }
    
private:
    bool canSplit(const vector<int>& nums, int k, int maxSum) {
        int currentSum = 0;
        int splits = 1;
        
        for (int num : nums) {
            currentSum += num;
            
            // If adding num exceeds maxSum, start a new subarray
            if (currentSum > maxSum) {
                currentSum = num;
                splits++;
                
                // If we exceed k splits, return false
                if (splits > k) {
                    return false;
                }
            }
        }
        
        return true;
    }
};

int main() {
    Solution solution;
    
    // Example 1
    vector<int> nums1 = {7, 2, 5, 10, 8};
    int k1 = 2;
    cout << "Example 1 Output: " << solution.splitArray(nums1, k1) << endl; // Expected Output: 18

    // Example 2
    vector<int> nums2 = {1, 2, 3, 4, 5};
    int k2 = 2;
    cout << "Example 2 Output: " << solution.splitArray(nums2, k2) << endl; // Expected Output: 9
    
    return 0;
}
