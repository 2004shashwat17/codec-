#include<iostream>
#include<vector>
using namespace std;

int coinchange(int amount, vector<int>& coins){
    int n = coins.size();
    vector<vector<int>> dp(n+1, vector<int>(amount+1,0));

    for(int i=0; i<n+1; i++){
        dp[i][0] = 1;
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<amount+1; j++){
            if(coins[i-1] <= j){
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][amount];
};


int main(){
    vector<int> coins = {1,2,5};
    int amount = 5;

    cout << coinchange(amount,coins) << endl;
    return 0;
}