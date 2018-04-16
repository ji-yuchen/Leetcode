/*
https://leetcode.com/problems/number-of-matching-subsequences/description/
Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.

Example :
Input: 
S = "abcde"
words = ["a", "bb", "acd", "ace"]
Output: 3
Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
Note:

All words in words and S will only consists of lowercase letters.
The length of S will be in the range of [1, 50000].
The length of words will be in the range of [1, 5000].
The length of words[i] will be in the range of [1, 50].


Something unclear with the concept of subsequence=.=
The original structure of "S" is not convenient to do processing. So we construct an alphabet to store index of each char on the alphabet[0-26].
*/
#include <vector>
using std::vector;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<int>> alphabet (26);
        for(int i = 0; i < S.size(); ++i)
            alphabet[S[i] - 'a'].push_back(i);
        int res = 0;
        for(const auto& word : words){
            int x = -1;
            int prev = -1;
            bool found = true;
            for(char ch : word){
                auto it = upper_bound(alphabet[ch -  'a'].begin(), alphabet[ch - 'a'].end(), x);
                //if(it == alphabet[ch - 'a'].end() || *it != (prev + 1)) 
                if(it == alphabet[ch - 'a'].end())
                    found = false;
                else{
                    prev = x;
                    x = *it;
                }                    
            }
            if(found)
                res++;
        }
        return res;
    }
};
