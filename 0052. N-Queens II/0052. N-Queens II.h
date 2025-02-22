/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.



It does not require to return strings. Thus, we change to vector<bool>.
*/



class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<vector<bool>> board(n, vector(n, false));
        backTrack(board, res, 0, n);
        return res;
    }
    void backTrack(vector<vector<bool>>& board, int& res, int row, int n){
        if(row == n){
            res++;
            return;
        }
        for(int col = 0; col < n; col++){
            if(isValid(board, row, col, n)){
                board[row][col] = true;
                backTrack(board, res, row+1, n);
                board[row][col] = false;
            }
        }
        return;
    }
    bool isValid(vector<vector<bool>>& board, int row, int col, int n){
        for(int i = 0; i < row; i++){
            if(board[i][col] == true){
                return false;
            }
        }
        for(int i = row-1, j = col-1; i>=0&&j>=0; i--, j--){
            if(board[i][j] == true){
                return false;
            }
        }
        for(int i = row-1, j = col+1; i>=0&&j<n; i--, j++){
            if(board[i][j] == true){
                return false;
            }
        }
        return true;
    }

};
