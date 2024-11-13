#include<iostream>
#include<string>
using namespace std;

string getSmallestString(int n, int k){
    string result(n, 'a');
    int remaining_value =  k - n;

    for(int i=n-1; i>=0 && remaining_value>0; i--){
        int add = min(25, remaining_value);
        result[i] += add;
        remaining_value -= add;
    }
    return result;
}
int main(){
    int n,k;
    cin >> n >> k;
    cout << getSmallestString(n , k) << endl;
    return 0;
}