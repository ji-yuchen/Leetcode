/*
https://leetcode.com/problems/first-unique-character-in-a-string/description/
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:
s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/
//Time complexity: O(N) ; Space complexity: O(1)
//we can use a vector<int> instead of the hash map.
//But it gives me a feeling of tricks.
#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        for(int i = 0; i < s.size(); ++i){
            map[s[i]]++;            
        }
        for(int i = 0; i < s.size(); ++i){
            if(map[s[i]] == 1)
                return i;
        }
        return -1;
    }
};
