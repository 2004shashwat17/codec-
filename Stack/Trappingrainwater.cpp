#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trap(vector<int>& height) {
    // Initialize two pointers: left and right.
    int left = 0;
    int right = height.size() - 1;

    // Initialize leftMax and rightMax to track the maximum height encountered so far.
    int leftMax = height[left];
    int rightMax = height[right];

    // Variable to store the total amount of trapped water.
    int water = 0;

    // Loop until the two pointers meet.
    while (left < right) {
        if (leftMax < rightMax) {
            // Move the left pointer to the right.
            left++;

            // Update the maximum height encountered on the left.
            leftMax = max(leftMax, height[left]);

            // Calculate trapped water at this point (if any) and add to the total.
            water += leftMax - height[left];
        } else {
            // Move the right pointer to the left.
            right--;

            // Update the maximum height encountered on the right.
            rightMax = max(rightMax, height[right]);

            // Calculate trapped water at this point (if any) and add to the total.
            water += rightMax - height[right];
        }
    }

    return water;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    // Output the amount of trapped rainwater.
    cout << "Total trapped rainwater: " << trap(height) << endl;

    return 0;
}
