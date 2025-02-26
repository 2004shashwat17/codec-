#include<iostream>
#include<vector>
#include<algorithm>  // Required for min()
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) { // O(n*m)
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int j = 0; j < m+1; j++) {
            dp[0][j] = j;  // Base case: insert all characters
        }
        for(int i = 0; i < n+1; i++) {
            dp[i][0] = i;  // Base case: delete all characters
        }

        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j < m+1; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];  // No cost if characters match
                } else {
                    dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});  
                    // Insert (dp[i][j-1]), Delete (dp[i-1][j]), Replace (dp[i-1][j-1])
                }
            }
        }
        return dp[n][m];
    }
};

int main() {
    Solution sol;
    string word1 = "horse";
    string word2 = "ros";

    cout << sol.minDistance(word1, word2) << endl; // Expected Output: 3
    return 0;
}
