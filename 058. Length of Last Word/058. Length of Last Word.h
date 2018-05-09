/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:
Input: "Hello World"
Output: 5

*/

//This issue ask as to return the length of last word. Two conditions need attention.
//The string contains no space.
//The end of string is space.
//We start loop from the end of string.
#include <string>
using std::string;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        for(int i = s.size()-1;i>=0;--i){
            if(s[i] == ' '){
                if(res == 0)
                    continue;
                else
                    break;
            }else
                ++res;
        }
        return res;
    }
};
