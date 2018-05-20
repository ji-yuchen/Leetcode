/*
https://leetcode.com/problems/group-anagrams/description/
Given an array of strings, group anagrams together.

Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:
All inputs will be in lowercase.
The order of your output does not matter.
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using std::vector;
using std::string;
using std::unordered_map;
using std::sort;

//Categorize by Sorted String
//Time complexity: O(N*K*logK); Space complexity: O(N*K)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> count;
        int i = 0;
        for(int i = 0; i < strs.size(); ++i){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            count[tmp].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto i:count){
            res.push_back(i.second);
        }
        return res;
    }
};

//Categorize by Counting Chars
//Time complexity: O(N*K); Space complexity: O(N*K)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> count;
        for(int i = 0; i < strs.size(); ++i){
            string tmp(26, '0');
            for(auto i:strs[i]){
                tmp[i-'a'] = '0' + ((tmp[i-'a'] - '0')+1);
            }
            
            if(count.find(tmp) == count.end()){
                count[tmp] = {strs[i]};                
            }else{
                count[tmp].push_back(strs[i]);
            }
        }
        
        vector<vector<string>> res;
        for(auto i:count){
            res.push_back(i.second);
        }
        return res;
    }
};
