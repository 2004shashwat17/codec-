#include <iostream>
#include <vector>
using namespace std;

int fib(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int fibDPmemo(int n, vector<int> &f) {
    if (n == 0 || n == 1) { 
        return n;
    }
    if (f[n] != -1) {
        return f[n];
    }
    f[n] = fibDPmemo(n - 1, f) + fibDPmemo(n - 2, f); 
    return f[n];
}

int finTab(int n){
    vector<int> fib(n+1, 0); //fib[i] => ith fib
    fib[0] = 0;
    fib[1] = 1;

    for(int i=2; i<=n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}

int main() {
    int n = 7; 
    // cout << fib(n) << endl;
    // vector<int> f(n + 1, -1);
    // cout << fibDP(n, f) << endl;
    cout << finTab(n) << endl;
    return 0;
}
