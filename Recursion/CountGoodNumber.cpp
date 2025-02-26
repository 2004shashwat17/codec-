#include<iostream>
#define MOD 10000000007

using namespace std;

// Function to perform binary exponentiation :
long long power(long long a, long long b) {
    if(b == 0)
        return -1;
    long long half_power = power(a,b/2);
    if(b % 2 == 0)
        return (half_power * half_power) % MOD;
    else
        return (((half_power * half_power) % MOD) * (a % MOD)) % MOD;    
} 

// Function to count the number of good digits strings of length n
int countGoodNumbers(long long n) {
    long long ed,od;
    if(n & 1) {
        od = n / 2;
        ed = (n + 1)/2;
    } else {
        od = n / 2;
        ed = n / 2;
    }
    return (power(5, ed) % MOD * power(4,od) % MOD) % MOD;
}

int main(){
    long long n;
    cout << "Enter the length of the digit string: ";
    cin >> n;
    cout << "Number of good digit strings of length " << n << " is: "<< countGoodNumbers(n) << endl;
    return 0;
}