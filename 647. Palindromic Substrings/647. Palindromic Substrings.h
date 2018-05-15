/*
https://leetcode.com/problems/palindromic-substrings/description/

Given a string, your task is to count how many palindromic substrings in this string.
The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
*/
#include<string>
using std::string;
//At each center, expand step by step around it and check if it is palindromic.
//Time complexity: O(N^2); Space complexity: O(1)
class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for(int i = 0; i < 2*s.size()-1; ++i){
            int left = i/2;
            int right = left + i%2;
            while(left>=0&&right<s.size()&&s[left] == s[right]){
                ++res;
                --left;
                ++right;
            }
        }
        return res;
    }
};
