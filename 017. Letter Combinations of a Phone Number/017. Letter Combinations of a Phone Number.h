/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> map;
        map={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        vector<string> res;
        if(digits.size() == 0)
            return res;
        res.push_back("");
        for(int i = 0; i < digits.size(); ++i){
            if(digits[i]<'2'||digits[i]>'9')
                continue;
            const string& next = map[digits[i]];
            vector<string> tmp;
            for(int j = 0; j < res.size(); ++j){
                for(int k = 0; k < next.size(); ++k){
                    tmp.push_back(res[j] + next[k]);
                }
            }
            res = tmp;
            tmp.clear();
        }
        return res;
    }
};
