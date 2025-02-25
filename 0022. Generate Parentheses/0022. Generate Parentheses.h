/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
// A basic backtracking problem. Keep track of the number of opening and closing brackets we have placed so far.
//Time Complexity : O(4^n/n^0.5). Each valid sequence has at most n steps during the backtracking procedure.
//Space Complexity : O(4^n/n^0.5). Use O(n)O(n) space to store the sequence.

#include <string>
using std::string;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", 0, 0, n);
        return res;        
    }
private://At first I use "string& cur", which conflicts the "" used in vector<string> generateParenthesis(int n).
    void backtrack(vector<string>& res, string cur, int open, int close, int max){
        if(cur.size() == max * 2){
            res.push_back(cur);
            return;
        }
        if(open<max){
            backtrack(res, cur+"(", open+1, close, max);
        }
        if(close<open){
            backtrack(res, cur+")", open, close+1, max);
        }
        /*
        if(left < n){
            cur += '(';
            backTrack(res, cur, left+1, right, n);
            cur.pop_back();
        }
        if(right < left){
            cur += ')';
            backTrack(res, cur, left, right+1, n);
            cur.pop_back();
        }
        */
    }
};
