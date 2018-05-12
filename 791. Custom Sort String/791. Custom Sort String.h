/*
https://leetcode.com/problems/custom-sort-string/description/
S and T are strings composed of lowercase letters. In S, no letter occurs more than once.
S was sorted in some custom order previously. We want to permute the characters of T so that they match the order that S was sorted. More specifically, if x occurs before y in S, then x should occur before y in the returned string.
Return any permutation of T (as a string) that satisfies this property.

Example :
Input: 
S = "cba"
T = "abcd"
Output: "cbad"

Explanation: 
"a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in S, it can be at any position in T. "dcba", "cdba", "cbda" are also valid outputs.

Note:
S has length at most 26, and no character is repeated in S.
T has length at most 200.
S and T consist of lowercase letters only.
*/
#include <string>
#include <unordered_map>
#include <algorithm>
using std::string;
using std::unordered_map;
using std::sort;

//My first solution
//Build a hash map for S. Then sort T by searching every char in T in S  .
//Time complexity: O(n^2); Space complexity: O(N)
class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char, int> idx;
        for(int i = 0; i<S.size(); ++i){
            idx.insert({S[i], i});
        }
        for(int i = 1; i < T.size(); ++i){
            for(int j = i; j >= 0; --j){
                if(idx[T[j]]<idx[T[j-1]]){
                    swap(T[j], T[j-1]);
                }
            }
        }
        return T;
    }
};

//Use function sort, which is cleverer than my first solution.
//Time complexity: O(NlogN); Space complexity: O(N)
class Solution {
  public:
    string customSortString(string S, string T) {
        unordered_map<char, int> dir;
        for (int i = 0; i < S.size(); i++) {
            dir[S[i]] = i + 1;
        }
        sort(T.begin(), T.end(),
             [&](char a, char b) { return dir[a] < dir[b]; });
        return T;
    }
};

//Build hash map for T, not S. Then build the result string in an order of S.
//Time complexity: O(N); Space complexity: O(N)
class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char, int> idx;
        for(auto& t:T){
            ++idx[t];
        }
        string res;
        for(auto& s:S){
            res += string(idx[s], s);
            idx[s] = 0;
        }
        for(auto& i:idx){
            if(i.second) 
                res += string(i.second, i.first);
        }
        return res;
    }
};
