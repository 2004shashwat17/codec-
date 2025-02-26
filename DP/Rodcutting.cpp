#include<iostream>
#include<vector>
using namespace std;
// using tabularization
int rodcutting(vector<int> price, vector<int>length, int rodLength){
    int n = length.size();

    vector<vector<int>> dp(n+1, vector<int>(rodLength + 1, 0));

    for(int i=1; i<n+1; i++){
        for(int j=1; j<rodLength+1; j++){
            if(length[i-1] <= j){
                dp[i][j] = max(price[i-1] + dp[i][j-length[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][rodLength];
}
//using memo
int cutRodMemo(vector<int> &price, int n, vector<int> &dp) {
    int n = price.size();
    vector<int> dp(n + 1, -1); 
    if (n == 0) return 0;  

    if (dp[n] != -1) return dp[n];  

    int maxValue = 0;
    for (int i = 1; i <= n; i++) {
        //adding the price for that cut (price[i - 1]), and recursively calculating the best value for the remaining rod (n - i).
        maxValue = max(maxValue, price[i - 1] + cutRodMemo(price, n - i, dp));
    }
    
    dp[n] = maxValue;  
    return maxValue;
}
int main(){
    vector<int> price = {1,5,8,9,10,17,17,20};
    vector<int>length = {1,2,3,4,5,6,7,8};
    int rodLength = 8;

    cout << rodcutting(price, length, rodLength) << endl;
    return 0;
}