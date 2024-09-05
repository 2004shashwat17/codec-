//Question3:Youaregivena0-indexedintegerarraynums.Theeffectivevalueofthreeindicesi,j,andkisdefinedas((nums[i]|nums[j])&nums[k]).ujjawalfrds@gmail.com
//Thexor-beautyofthearrayistheXORingoftheeffectivevaluesofallthepossibletripletsofindices(i,j,k)where0<=i,j,k<n.Returnthexor-beautyofnums.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to calculate XOR beauty
    int xorBeauty(vector<int>& nums) {
        int a = 0, b = 0;
        // Loop through all numbers in the vector
        for (int i = 0; i < nums.size(); i++) {
            a = a | nums[i]; // Perform OR operation with a and current number
            b = b ^ nums[i]; // Perform XOR operation with b and current number
        }
        return (a & b); // Return the result of AND operation between a and b
    }
};

int main() {
    Solution solution;
    
    // Example input array
    vector<int> nums = {3, 5, 6, 7};
    
    // Get the XOR beauty of the array
    int result = solution.xorBeauty(nums);
    
    // Output the result
    cout << "The XOR beauty is: " << result << endl;

    return 0;
}
