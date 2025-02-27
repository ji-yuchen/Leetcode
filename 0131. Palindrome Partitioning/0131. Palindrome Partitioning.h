/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.

Time complexity: O(N*2^N), where 2^N refers to the backtracking part.
Need to care about the seleciton of start and end in this solution.
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> par;
        backTrack(res, s, par, 0);
        return res;
    }
    void backTrack(vector<vector<string>>& res, string s, vector<string>& par, int start){
        if(start == s.size()){
            res.push_back(par);
            return;
        }
        for(int end = start+1; end <= s.size(); end++){
            string cur = s.substr(start, end-start);
            if(!check(cur)){
                continue;
            }
            //is a palindrome
            par.push_back(cur);
            backTrack(res, s, par, end);
            par.pop_back();
        }
    }
    bool check(string cur){
        if(cur.size() == 0){
            return false;
        }
        int left = 0;
        int right = (int)cur.size()-1;
        while(left<right){
            if(cur[left]!=cur[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
