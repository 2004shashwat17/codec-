#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive function to solve the Tower of Hanoi problem
    int towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {
        if (n == 0) {
            return 0;  // No moves needed for 0 disks
        }
        if (n == 1) {
            // Base case: move the single disk
            return 1;  // One move needed for 1 disk
        }
        
        // Move n-1 disks from fromRod to auxRod
        int moves1 = towerOfHanoi(n - 1, fromRod, auxRod, toRod);
        // Move the nth disk from fromRod to toRod
        int moves2 = 1;
        // Move n-1 disks from auxRod to toRod
        int moves3 = towerOfHanoi(n - 1, auxRod, toRod, fromRod);

        // Total moves = moves1 + 1 (for nth disk) + moves3
        return moves1 + moves2 + moves3;
    }
};

int main() {
    int T;
    cin >> T; // Test cases
    while (T--) {
        int N;
        cin >> N; // Number of disks

        Solution ob;
        cout << ob.towerOfHanoi(N, 'A', 'C', 'B') << endl;  // Print total moves

        cout << "~" << "\n"; // Separation line after each test case
    }
    return 0;
}
