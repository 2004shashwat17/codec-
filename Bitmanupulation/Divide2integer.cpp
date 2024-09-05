//Giventwointegersdividendanddivisor,dividetwointegerswithoutusingmultiplication,division,andmodoperator
#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    // Function to divide two integers without using multiplication, division, or mod operators
    int divide(int dividend, int divisor) {
        // Handle overflow edge case: when dividend is INT_MIN and divisor is -1, result overflows
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        // Determine the sign of the result
        bool negative = (dividend < 0) ^ (divisor < 0); // XOR to check if signs are different
        
        // Convert both numbers to positive using long long to avoid overflow with abs(INT_MIN)
        long long a = labs(dividend);
        long long b = labs(divisor);
        
        // Initialize result (quotient)
        int result = 0;
        
        // Subtract divisor from dividend while shifting divisor left
        while (a >= b) {
            long long temp = b;
            int multiple = 1;
            // Keep doubling the divisor (bitwise shift left) until it exceeds the dividend
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;       // Subtract the largest shifted divisor from the dividend
            result += multiple; // Add the corresponding multiple to the result
        }
        
        // Return the result with the appropriate sign
        return negative ? -result : result;
    }
};

int main() {
    Solution solution;
    
    // Example test cases
    int dividend = 10, divisor = 3;
    
    // Perform the division
    int result = solution.divide(dividend, divisor);
    
    // Output the result
    cout << "Result of " << dividend << " / " << divisor << " is: " << result << endl;
    
    return 0;
}
