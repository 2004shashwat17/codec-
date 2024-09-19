#include <iostream>
#include <vector>
#include <iomanip> // Include this for setw()

using namespace std;

void solve(int n, int i, int j, int cnt, vector<vector<int>>& mat, vector<vector<bool>>& visited, bool &found) {
    // Check if the current position is out of bounds or already visited
    if (i < 0 || j < 0 || i >= n || j >= n || visited[i][j]) return;

    // If all the squares have been visited, mark this path as complete
    if (cnt == n * n - 1) {
        mat[i][j] = cnt;
        found = true;
        return;
    }

    visited[i][j] = true;
    mat[i][j] = cnt;

    // All possible moves of a knight in a chessboard
    solve(n, i - 2, j + 1, cnt + 1, mat, visited, found);
    if (found) return;

    solve(n, i - 2, j - 1, cnt + 1, mat, visited, found);
    if (found) return;

    solve(n, i + 2, j + 1, cnt + 1, mat, visited, found);
    if (found) return;

    solve(n, i + 2, j - 1, cnt + 1, mat, visited, found);
    if (found) return;

    solve(n, i - 1, j + 2, cnt + 1, mat, visited, found);
    if (found) return;

    solve(n, i - 1, j - 2, cnt + 1, mat, visited, found);
    if (found) return;

    solve(n, i + 1, j + 2, cnt + 1, mat, visited, found);
    if (found) return;

    solve(n, i + 1, j - 2, cnt + 1, mat, visited, found);
    if (found) return;

    visited[i][j] = false;
    mat[i][j] = -1; // Reset the position if no solution was found from here
}

int main() {
    // Input the size of the chessboard
    int n;
    cout << "Enter the size of the chessboard: ";
    cin >> n;

    // Initialize the matrix and visited array
    vector<vector<int>> mat(n, vector<int>(n, -1)); //n*n matrix
    vector<vector<bool>> visited(n, vector<bool>(n, false)); // n*n boolean matrix

    bool found = false;

    // Start the knight's tour from position (0, 0)
    solve(n, 0, 0, 0, mat, visited, found);

    // If a valid knight's tour is found, print the matrix
    if (found) {
        cout << "Knight's Tour Solution:" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << setw(2) << mat[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists for the Knight's Tour." << endl;
    }

    return 0;
}
