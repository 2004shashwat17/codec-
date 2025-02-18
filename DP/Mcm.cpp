#include<iostream>
#include<vector>
#include <climits>
using namespace std;

int mcmRec(vector<int> arr, int i, int j){
    if(i == j){
        return 0;
    }
    int ans = INT_MAX;

    for(int k=i; k<j; k++){
        //(i,k)
        int cost1 = mcmRec(arr, i, k);
        //(k+1,j)
        int cost2 = mcmRec(arr, k+1, j); 
        //current partition cost 
        int currCost = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);
        ans = min(ans, currCost);
    }
    return ans;
}

int mcmMEMO(vector<int> &arr, int i, int j, vector<vector<int>> &dp) {
    if (i == j) {
        return 0;
    }
    if (dp[i][j] != -1) {  // Correct memoization check
        return dp[i][j];
    }

    int ans = INT_MAX;

    for (int k = i; k < j; k++) {
        //(i,k)
        int cost1 = mcmMEMO(arr, i, k, dp);  // Correct function call
        //(k+1,j)
        int cost2 = mcmMEMO(arr, k + 1, j, dp);
        // Current partition cost
        int currCost = cost1 + cost2 + (arr[i - 1] * arr[k] * arr[j]);
        ans = min(ans, currCost);
    }

    return dp[i][j] = ans;  // Store the result in dp
}

int mcmTab(vector<int> arr){ //0(n^3)
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(n,0));

    //intialization
    for(int i=1; i<n; i++){
        dp[i][i] = 0; //single matrix
    }

    //bottom up fill
    for(int len=2; len<n; len++){ // for digonal traversal
        for(int i=1; i<=n-len; i++){ //rows
            int j = i+len-1;
            dp[i][j] = INT_MAX;
            for(int k=i; k<j; k++){ //cols
                int cost1 = dp[i][k];
                int cost2 = dp[k+1][j];
                int currCost = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);
                dp[i][j] = min(dp[i][j], currCost);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[1][n-1];
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 3}; // n->n-1 matrices (1 to n-1)
    cout << mcmTab(arr) << endl;
    // int n = arr.size();

    // vector<vector<int>> dp(n, vector<int>(n, -1));  // Correct initialization

    // cout << mcmMEMO(arr, 1, n - 1, dp) << endl;
    return 0;
}