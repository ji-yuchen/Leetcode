/*
https://leetcode.com/problems/reverse-string/description/

Write a function that takes a string as input and returns the string reversed.
Example:
Given s = "hello", return "olleh".
*/

//We can use existing "reverse", "swap", "rbegin" functions to help us.
#include <string>
using std::string;
class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
};

/*
        int i = 0, j = s.size() - 1;
        while(i < j){
            swap(s[i++], s[j--]); 
        }
*/
/*
        return { s.rbegin(), s.rend() };
*/
