
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 37: Sudoku Solver
// Time complexity id 9^(empty cells)

bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {
    // Check horizontal row
    for (int j = 0; j < 9; j++) {
        if (board[row][j] == dig) {
            return false;
        }
    }

    // Check vertical column
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == dig) {
            return false;
        }
    }

    // Check 3x3 grid
    int srow = (row / 3) * 3;
    int scol = (col / 3) * 3;

    for (int i = srow; i < srow + 3; i++) {
        for (int j = scol; j < scol + 3; j++) {
            if (board[i][j] == dig) {
                return false;
            }
        }
    }

    return true;
}

bool helper(vector<vector<char>>& board, int row, int col) {
    // All rows completed
    if (row == 9) {
        return true;
    }

    // Calculate next cell
    int nextRow = row;
    int nextCol = col + 1;

    if (nextCol == 9) {
        nextRow = row + 1;
        nextCol = 0;
    }

    // Skip already filled cells
    if (board[row][col] != '.') {
        return helper(board, nextRow, nextCol);
    }

    // Try digits 1 to 9
    for (char dig = '1'; dig <= '9'; dig++) {
        if (isSafe(board, row, col, dig)) {
            board[row][col] = dig;

            if (helper(board, nextRow, nextCol)) {
                return true;
            }

            // Backtrack
            board[row][col] = '.';
        }
    }

    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    helper(board, 0, 0);
}

// Print the Sudoku board
void printBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
            if (j == 2 || j == 5) {
                cout << "| ";
            }
        }

        cout << '\n';

        if (i == 2 || i == 5) {
            cout << "------+-------+------\n";
        }
    }
}

int main() {
    vector<vector<char>> board(9, vector<char>(9));

    cout << "Enter Sudoku (use . for empty cells):\n";

    // Input 9 rows, each containing 9 characters
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }
    //i/p :- 53..7....6..195....98....6.8...6...34..8.3..17...2...6.6....28....419..5....8..79

    cout << "\nOriginal Sudoku:\n";
    printBoard(board);

    solveSudoku(board);

    cout << "\nSolved Sudoku:\n";
    printBoard(board);

    return 0;
}


// Original Sudoku:
// 5 3 . | . 7 . | . . . 
// 6 . . | 1 9 5 | . . . 
// . 9 8 | . . . | . 6 . 
// ------+-------+------
// 8 . . | . 6 . | . . 3 
// 4 . . | 8 . 3 | . . 1 
// 7 . . | . 2 . | . . 6 
// ------+-------+------
// . 6 . | . . . | 2 8 . 
// . . . | 4 1 9 | . . 5 
// . . . | . 8 . | . 7 9 

// Solved Sudoku:
// 5 3 4 | 6 7 8 | 9 1 2 
// 6 7 2 | 1 9 5 | 3 4 8 
// 1 9 8 | 3 4 2 | 5 6 7 
// ------+-------+------
// 8 5 9 | 7 6 1 | 4 2 3 
// 4 2 6 | 8 5 3 | 7 9 1 
// 7 1 3 | 9 2 4 | 8 5 6 
// ------+-------+------
// 9 6 1 | 5 3 7 | 2 8 4 
// 2 8 7 | 4 1 9 | 6 3 5 
// 3 4 5 | 2 8 6 | 1 7 9 