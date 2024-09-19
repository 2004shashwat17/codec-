#include <iostream>
#include <vector>
using namespace std;

// Helper function to check if the rat can move to the next cell
bool isSafe(int x, int y, vector<vector<int>> &maze, vector<vector<bool>> &visited, int n) {
    // The function checks whether (x, y) is a valid move
    // The rat can move to (x, y) only if:
    // - (x, y) is within the maze bounds
    // - maze[x][y] is not blocked (i.e., value is 1)
    // - (x, y) has not been visited in the current path
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && !visited[x][y]);
}

// Recursive function to find all paths from (0, 0) to (N-1, N-1)
void findPaths(int x, int y, vector<vector<int>> &maze, int n, vector<vector<bool>> &visited, string path, vector<string> &result) {
    // Base Case: If we reach the destination (N-1, N-1)
    if (x == n - 1 && y == n - 1) {
        // We've found a valid path, so we add it to the result
        result.push_back(path);
        return;
    }

    // Mark the current cell as visited
    visited[x][y] = true;

    // Move Down (D) if possible
    if (isSafe(x + 1, y, maze, visited, n)) {
        findPaths(x + 1, y, maze, n, visited, path + 'D', result);
    }

    // Move Right (R) if possible
    if (isSafe(x, y + 1, maze, visited, n)) {
        findPaths(x, y + 1, maze, n, visited, path + 'R', result);
    }

    // Move Up (U) if possible
    if (isSafe(x - 1, y, maze, visited, n)) {
        findPaths(x - 1, y, maze, n, visited, path + 'U', result);
    }

    // Move Left (L) if possible
    if (isSafe(x, y - 1, maze, visited, n)) {
        findPaths(x, y - 1, maze, n, visited, path + 'L', result);
    }

    // Backtrack: Unmark the current cell to allow future paths to visit it
    visited[x][y] = false;
}

// Main function to find all paths in the maze
vector<string> ratInMaze(vector<vector<int>> &maze, int n) {
    vector<string> result;  // Stores all valid paths
    vector<vector<bool>> visited(n, vector<bool>(n, false));  // Keeps track of visited cells

    // Start DFS from (0, 0) if the start cell is open
    if (maze[0][0] == 1) {
        findPaths(0, 0, maze, n, visited, "", result);
    }

    return result;
}

int main() {
    // Updated maze input
    vector<vector<int>> maze = {
        { 1, 1, 1, 1 },
        { 0, 1, 0, 1 },
        { 1, 1, 1, 1 },
        { 1, 0, 1, 1 }
    };
    int n = maze.size();
    vector<string> paths = ratInMaze(maze, n);

    // Print all paths
    if (paths.empty()) {
        cout << "No path found!" << endl;
    } else {
        for (const string &path : paths) {
            cout << path << endl;
        }
    }

    return 0;
}
