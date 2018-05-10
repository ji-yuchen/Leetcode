/*
https://leetcode.com/problems/implement-strstr/description/

Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1

Clarification:
What should we return when needle is an empty string? This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        int res = 0;
        if(n==0)
            return res;
        if(m<n)
            return -1;
        
        for(int i = 0; i < m - n + 1; ++i){            
            int tmp = 1;
            for(int j = 0; j < n; ++j){
                if(haystack[i+j]!=needle[j]){//At first, I wrote "needle[i+j]"=.=
                    tmp = 0;
                    break;
                } 
            }
            if(tmp == 1){
                res = i;
                return res;
            }            
        }
        return -1;
    }
};
