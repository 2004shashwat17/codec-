#include<iostream>
#include<vector>
#include<set> // Use set instead of unordered_set
#include<algorithm>
using namespace std;

int LIS(vector<int> arr){ // O(n²)
    set<int> s(arr.begin(), arr.end()); // O(n log n) unique sorted values

    vector<int> arr2(s.begin(), s.end()); // Already sorted

    // LCS => LIS
    int n = arr.size();
    int m = arr2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; i++){ // O(n²)
        for(int j=1; j<=m; j++){
            if(arr[i-1] == arr2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main(){
    vector<int> arr = {50, 3, 10, 7, 40, 80};

    cout << LIS(arr) << endl;
    return 0;
}
 