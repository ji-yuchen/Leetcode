/*
https://leetcode.com/problems/valid-palindrome/description/
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:
Input: "A man, a plan, a canal: Panama"
Output: true

Example 2:
Input: "race a car"
Output: false

*/
#include <string>
using std::string;
class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        while(start<end){
            while(isnumchar(s[start]) == false && start<end) ++start;
            while(isnumchar(s[end]) == false && start<end) --end;
            if(!comparecharnum(s[start], s[end])) return false;
            ++start;
            --end;            
        }
        return true;
        
    }
private:
    bool isnumchar(char& i){//can use isalnum
        if((i < '0' || i > '9') && (i < 'A' || i > 'Z') && (i < 'a' || i > 'z'))
            return false;
        else
            return true;
    }
    bool comparecharnum(char& a, char& b){// can use toupper or tolower
        if(a >= 'A'&&a <= 'Z')
            a -= 'A' - 'a';
        if(b >= 'A'&&b <= 'Z')
            b -= 'A' - 'a';
        if(a == b)
            return true;
        else
            return false;
    }
};
