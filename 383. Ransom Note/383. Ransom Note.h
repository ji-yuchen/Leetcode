/*
https://leetcode.com/problems/ransom-note/description/
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.
canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

*/
//I don't understand what the arbitrary note means....
//This problem is easy to solve by using an hash map to store the number of each char.
#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map(26);
        for(int i = 0; i < magazine.size(); ++i){
            ++map[magazine[i]];
        }
        for(int i = 0; i <ransomNote.size(); ++i){
            if(--map[ransomNote[i]]<0)
                return false;            
        }
        return true;
    }
};
