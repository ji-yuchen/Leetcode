/*
https://leetcode.com/problems/reverse-vowels-of-a-string/description/

Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".
*/
#include <string>
using std::string;

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.length()-1;
        while(i<j) {
        //If use STL:
        //i = s.find_first_of("aeiouAEIOU", i);
        //j = s.find_last_of("aeiouAEIOU", j);
            while(i<j && !isVowel(s[i])) i++;
            while(i<j && !isVowel(s[j])) j--;
            if(i<j) swap(s[i++], s[j--]);
        }
        return s;
    }
private:
    bool isVowel(char c) const{
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || 
            c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
    
};
