#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subArrayCountWithK(vector<int> arr, int K){
    unordered_map<int, int> m;
    m[0] = 1;
    int sum = 0;
    int ans = 0;

    for(int j=0; j<arr.size(); j++){
        sum += arr[j];
        if(m.count(sum-K)) {
            ans += m[sum-K];
        }
        if(m.count(sum)){
            m[sum]++;
        } else {
            m[sum] = 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3};
    int K = 3;

    cout << "subarray count = "<< subArrayCountWithK(arr, K) << endl; 
    return 0;
}