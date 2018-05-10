/*
https://leetcode.com/problems/longest-common-prefix/description/

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:
Input: ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Note:
All given inputs are in lowercase letters a-z.
*/
//We have to search every char in every word in bad conditions. 
//Time complexity: O(N*c) Space complexity: O(c).
#include <vector>
using std::vector
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        string res = strs[0];
        for(int i = 0; i < strs.size(); ++i){
            string tmp = "";
            int j = 0;
            while(j<res.size()&&j<strs[i].size()){
                if(res[j]==strs[i][j])
                    tmp += res[j];
                else
                    break;
                ++j;
            }
            res = tmp;
            if(res == "")
                break;
        }
        return res;
    }
};
