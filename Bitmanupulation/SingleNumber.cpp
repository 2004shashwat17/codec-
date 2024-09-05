//q2 Givenanon-emptyarrayofintegersnums,everyelementappearstwiceexceptforone.
//Findthatsingleone.Youmustimplementasolutionwithalinearruntimecomplexityanduseonlyconstantextraspace
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer = 0;
        // XOR all elements in the array
        for (int i = 0; i < nums.size(); i++) {
            answer ^= nums[i];
        }
        return answer;
    }
};

int main() {
    Solution solution;
    // Example input array
    vector<int> nums = {4, 1, 2, 1, 2};

    // Find the single number
    int result = solution.singleNumber(nums);

    // Output the result
    cout << "The single number is: " << result << endl;

    return 0;
}
