#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false)); // Fixed typo
        dp[0][0] = true;

        for(int j=1; j<m+1; j++){ // 0th row initialization
            if(p[j-1] == '*') { // Fixed incorrect comparison syntax
                dp[0][j] = dp[0][j-1];
            } else {
                dp[0][j] = false;
            }
        }

        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?') { // Fixed 't' -> 's'
                    dp[i][j] = dp[i-1][j-1];
                } else if(p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};

int main() {
    Solution sol;

    // Example 1
    string s1 = "aa", p1 = "a";
    cout << "Example 1 Output: " << (sol.isMatch(s1, p1) ? "true" : "false") << endl;

    // Example 2
    string s2 = "aa", p2 = "*";
    cout << "Example 2 Output: " << (sol.isMatch(s2, p2) ? "true" : "false") << endl;

    return 0;
}
