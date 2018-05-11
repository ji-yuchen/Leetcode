/*
https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.

*/
#include <string>
#include <algorithm>
using std::string;
using std::reverse;

class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        int end = 0;
        while(start < s.size()){
            while(end<s.size() && s[end] != ' '){
                ++end;
            }
            reverse(s.begin()+start, s.begin()+end);
            ++end;
            start = end;
        }
        return s;        
    }
};
