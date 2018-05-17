/*
https://leetcode.com/problems/detect-capital/description/

Given a word, you need to judge whether the usage of capitals in it is right or not.
We define the usage of capitals in a word to be right when one of the following cases holds:
All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.

Example 1:
Input: "USA"
Output: True

Example 2:
Input: "FlaG"
Output: False

Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/
//65～90为26个大写英文字母，97～122号为26个小写英文字母.... When we compare chars, we are comparing their ascii.
#include <string>
using std::string;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if(word[0]>='a'&&word[0]<='z'){
            for(int i = 1; i < n; ++i){
                if(word[i]>='A'&&word[i]<='Z')
                    return false;
            }
        }
        if(word[0]>='A'&&word[0]<='Z'){
            for(int i = 2; i < n; ++i){
                if((word[i]>='A'&&word[i]<='Z') != (word[i-1]>='A'&&word[i-1]<='Z'))
                    return false;
            }
        }
        return true;
    }
};
