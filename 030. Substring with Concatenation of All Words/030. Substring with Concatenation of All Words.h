/*
https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

Example 1:
Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.

Example 2:
Input:
  s = "wordgoodstudentgoodword",
  words = ["word","student"]
Output: []
*/
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> counts;
        for(string word:words){
            counts[word]++;
        }
        vector<int> index;
        if(words.size()==0 || s.size()==0)
            return index;
        int len = words[0].size();
        
        for(int i = 0; i < s.size() - words.size()*len + 1; ++i){
            unordered_map<string, int> seen;
            int j = 0;
            while(j < words.size()){
                string word = s.substr(i+j*len, len);
                if(counts.find(word) != counts.end()){
                    ++seen[word];
                    if(seen[word] > counts[word])
                    break;
                }else
                    break;
                ++j;
            }
            if(j == words.size()) index.push_back(i);
        }
        return index;
    }
};
