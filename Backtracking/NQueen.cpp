#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool foundsolution  = false; // Global flag to indicate if a solution has been found

void printBoard(vector<vector<char>> board) {
    int n = board.size();

    for(int i=0; i<n ; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------------\n";
}

bool isSafe(vector<vector<char>> board, int row, int col){
    int n = board.size();
    // Horizontal safety
    for(int j=0; j<n; j++){
        if(board[row][j] == 'Q') {
            return false;
        }
    }
    // Vertical safety
    for(int i=0; i<n; i++){
        if(board[i][col] == 'Q') {
            return false;
        }
    }
    // Diagonal left safety
    for(int i=row, j=col; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    // Diagonal right safety
    for(int i=row, j=col; i>=0 && j<n; i--, j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}

int nQueens(vector<vector<char>> board, int row) {
    int n = board.size();
    if(row == n) {
        if(!foundsolution) {
            printBoard(board);
            foundsolution = true; // Set flag to true to stop further searches
        }
        return 1;  // Return 1 when a valid solution is found
    }

    int count = 0;
    for(int j=0; j<n; j++) { // cols
        if(isSafe(board, row, j)) {
            board[row][j] = 'Q'; // Place the queen
            count += nQueens(board, row+1); // Recur to place queens in next rows
            board[row][j] = '.';   // Backtrack and reset the position
        }
    }
    return count; // Return the number of solutions found at this level
}

int main(){
    vector<vector<char>> board;
    int n = 3;

    for(int i=0; i<n; i++) {
        vector<char> newRow;
        for(int j=0; j<n; j++) {
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }

    int count = nQueens(board, 0);
    cout << "Total number of solutions: " << count << endl;

    return 0;
}
