#include<iostream>
using namespace std;

int friendpairing(int n){
    if( n==1 || n==2 ){
        return n;
    }
    return friendpairing(n-1) + (n-1) * friendpairing(n-2);
}
int main(){
    cout << friendpairing(4) << endl; // 4ways
    return 0;
}