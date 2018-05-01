/*
https://leetcode.com/problems/word-search/description/

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/
//This is a classical backtracking problem and we use DFS here.
//When visit an element, change it to ' ' to make it visited.
//After dealing with paths passing this element, change it to original character.

#include<vector>
using std::vector;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i<m; ++i)
            for(int j = 0; j<n; ++j)
                if(search(board,word,0,i,j))
                    return true;
        return false;
    }
    bool search(vector<vector<char>>& board, string& word, int s, int row, int col){
        bool ret = false;
        if(board[row][col]==word[s]){
            if(s >= word.size()-1)
                return true;
            char temp = board[row][col];
            board[row][col] = ' ';
            if(col>0 && search(board, word, s+1, row, col-1))
                ret = true;
            else if(row>0 && search(board, word, s+1, row-1, col))
                ret = true;
            else if(col<(board[0].size()-1) && search(board, word, s+1, row, col+1))
                ret = true;
            else if(row<(board.size()-1) && search(board, word, s+1, row+1, col))
                ret = true;
            board[row][col] = temp;            
        }
        return ret;        
    }
};
