#include<iostream>
#include<vector>
using namespace std;

int tilingproblem (int n){ //0(2^n)
    if(n == 0 || n == 1){
        return 1;
    }
    int ans1 = tilingproblem(n-1);
    int ans2 = tilingproblem(n-2);
    return ans1 + ans2;
}
//using dp
int numberOfWays(int n) {  //0(n)
        
    vector<int>dp(n+1, 0);
    
   dp[0] = 1;
   if(n >= 1){
       dp[1] = 1;
   }
   
   for(int i=2; i<=n; i++){
       dp[i] = dp[i-1] + dp[i-2];
   }
   return dp[n];
}
int main(){
    int n = 3;
    // cout << tilingproblem(5) << endl;
    cout << numberOfWays(5) << endl;
    return 0;
}