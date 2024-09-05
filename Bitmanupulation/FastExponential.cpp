//Fast exponentiation ?
#include<iostream>
using namespace std;

int fastexpo(int x, int n) {
    int ans = 1; // Initialize the answer
    while (n > 0) {
        int lastdigit = n & 1;
        if (lastdigit) {
            ans = ans * x;
        }
        x = x * x;
        n = n >> 1;
    }
    return ans; // Return the final result
}

int main() {
    int result = fastexpo(3, 4);
    cout << result << endl; // Output the result
    return 0;
}