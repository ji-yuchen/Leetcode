/*
https://leetcode.com/problems/longest-uncommon-subsequence-ii/description/
Given a list of strings, you need to find the longest uncommon subsequence among them. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.

Example 1:
Input: "aba", "cdc", "eae"
Output: 3

Note:
All the given strings' lengths will not exceed 10.
The length of the given list will be in the range of [2, 50].
*/
//I REALLY DONT LIKE THIS QUESTION....QAQ
//This is a solution same with my idea from discussion zone: https://leetcode.com/problems/longest-uncommon-subsequence-ii/discuss/99498/hashmap-+-sort-solution-c++
//This question is easy. First we consider the longest string to be the LUS. If there are two same longest strings. Consider the second longest string and check if it is a subsequence of strings having same of lager size.
//I feel uncomfortable when doing this question.


//desending order of string size
bool cmp(pair<string,int> &a, pair<string,int> &b) {
    return a.first.size() > b.first.size();
}

// Return true for s1 = abc, s2 = aebece
bool isSubStringOf(string &s1, string &s2){
    int i = 0, j = 0;
    while (i < s1.size()) {
        while (j < s2.size() && s1[i] != s2[j])
            j++;
        if (j == s2.size())
            return false;
        i++;
        j++;
    }
    return true;
}

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        // define a string to int map to save the frequency of each string
        unordered_map<string, int> mp;
        for (const auto& str : strs)
            mp[str]++;
        
        // define a vector of map element pair and sort it in descending order of string size
        vector<pair<string, int>> vec;
        for (const auto& m : mp)
            vec.push_back(m);
        sort(vec.begin(), vec.end(), cmp);
        
        // For each string in the sorted vector, if all the other string coming before it is
        // NOT super string of it then we use its size as LUS. If each pair of string have 
        // sub string relation then the longest uncommon subsequence doesn't exist
        for (int i = 0; i < vec.size(); i++) {
            if (1 == vec[i].second) {
                int j = 0;
                for (; j < i; j++)
                    if (isSubStringOf(vec[i].first, vec[j].first))
                        break;
                if (j == i)
                    return vec[i].first.size();        
            }
        }
        
        return -1;
    }
};
