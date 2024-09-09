#include<iostream>
using namespace std;

// Function to count how many times 'num' appears in the range [lo, hi] of the array
int countInRange(int nums[], int num, int lo, int hi){
    int count = 0;
     // Iterate over the range and count occurrences of 'num'
    for (int i = lo; i <= hi; i++){
        if(nums[i] == num){
            count++;
        }
    }
    return count; // Return the count of 'num'
}

// Recursive function to find the majority element in the range [lo, hi]
int majorityElementrec(int nums[], int lo, int hi){
     // Base case: if the array contains only one element, return that element as the majority
    if(lo == hi){
        return nums[lo];
    }
    // Find the middle index to divide the array into two halves
    int mid = (hi - lo)/ 2 + lo;
    // Recursively find the majority element in the left half
    int left = majorityElementrec(nums, lo, mid);
     // Recursively find the majority element in the right half
    int right = majorityElementrec (nums, mid+1, hi);
    // If both halves agree on the majority element, return it
    if(left == right){
        return left;
    }
     // Otherwise, count how many times 'left' and 'right' appear in the entire range [lo, hi]
    int leftCount = countInRange(nums, left, lo,hi);
    int rightCount = countInRange(nums, right, lo,hi);
      // Return the element that appears more times (either 'left' or 'right')
    return leftCount > rightCount ? left : right;
}
// Main function to find the majority element in the array
int majorityElement(int nums[], int n) {
     // Call the recursive function with the entire range of the array
    return majorityElementrec(nums, 0, n-1);
}
int main() {
    int nums[] = {2,2,1,1,1,2,2};
    int n = 7;
    cout << "Majority Element : " << majorityElement(nums , n) << endl;
    return 0;
}