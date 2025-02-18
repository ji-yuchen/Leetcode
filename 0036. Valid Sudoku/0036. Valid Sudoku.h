/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.

*/


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    continue;
                }
                char dig = board[i][j];

                for(int col = j+1; col<9; col++){
                    if(board[i][col] == dig){
                        return false;
                    }
                }
                for(int row = i+1; row < 9; row++){
                    if(board[row][j] == dig){
                        return false;
                    }
                }

                int srow = (i/3)*3;
                int scol = (j/3)*3;

                for(int x = srow; x <= srow+2; x++){
                    for(int y = scol; y <=scol+2; y++){
                        if(x==i && y==j){
                            continue;
                        }
                        if(board[x][y] == dig){
                            return false;
                        }
                    }
                }            
            }

        }
        return true;

    }
};
