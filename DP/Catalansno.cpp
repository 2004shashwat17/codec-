#include<iostream>
#include<vector>
#include<string>
using namespace std;

int catalanRec(int n){ //0(2^n)
    if(n == 0 || n == 1){
        return 1;
    }   
    int ans = 0;
    for(int i=0; i<n; i++){
        ans += catalanRec(i) * catalanRec(n-i-1);
    }
    return ans;
}

int catalanMem(int n, vector<int> &dp){ //0(n^2)
        if(n == 0 || n == 1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }

        int ans = 0;

        for(int i=0; i<n; i++){
            ans += catalanMem(i,dp) * catalanMem(n-i-1,dp);
        }
        return dp[n] = ans;
}

int catatab(int n){ //0(n^2)
    vector<int> dp(n+1, 0); //dp initalized
    dp[0] = dp[1] = 1; //base case

    for(int i=2; i<=n; i++){ //ith catalan
        for(int j=0; j<i; j++){ //0 to i-1
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    return dp[n];
}

int main(){
    int n = 6;
    // vector<int>dp(n+1, -1);

    // for(int i=0; i<=6; i++){
    //     cout << catalanMem(i, dp) << endl;
    // }
    for(int i=0; i<=n; i++){
        cout << catatab(i) << endl;
    } 
    cout << endl;
    return 0;
}