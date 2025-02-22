/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 

Constraints:

1 <= n <= 9
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res;
        backTrack(res, board, 0, n);
        return res;
    }
    void backTrack(vector<vector<string>>& res, vector<string>& board, int row, int n){
        if(row == n){
            res.push_back(board);
        }
        for(int col = 0; col < n; col++){
            if(isValid(board,row,col,n)){
                board[row][col] = 'Q';
                backTrack(res, board, row+1, n);
                board[row][col] = '.';
            }
        }
    }
    bool isValid(vector<string>& board, int row, int col, int n){
        bool flag = false;
        for(int i = 0; i < row; i++){
            if(board[i][col]=='Q'){
                return flag;
            }
        }
        //left diagonal
        for(int i = row - 1, j = col - 1; i >= 0 &&j >= 0; i--, j--){
            if(board[i][j]=='Q'){
                return flag;
            }
        }
        //right diagonal
        for(int i = row - 1, j = col + 1; i >= 0&&j < n; i--, j++){
            if(board[i][j]=='Q'){
                return flag;
            }
        }
        flag = true;
        return flag;

    }

};
