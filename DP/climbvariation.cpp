#include<iostream>
#include<vector>
using namespace std;

int countwaystab(int n){
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];
}

int main(){
    int n = 4;
    cout << countwaystab(n) << endl; 
    return 0;
}