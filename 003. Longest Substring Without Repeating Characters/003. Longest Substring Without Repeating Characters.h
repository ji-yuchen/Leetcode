/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
Given a string, find the length of the longest substring without repeating characters.

Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
//Use a hash map to store the position of each char met. store the starting position of the substring at the same time.
//Traverse each char in string, update the hash map. If the char already exists in the hash map, set existing position +1 as the new starting.
//Check if the length of the substring is longer than recorded.
//Time complexity: O(N); Space complexity: O(min(M, N))
//The size of the hash map is upper bounded by the size of the string N and the size of the charset/alphabet M.
 
#include <string>
#include <unordered_map>
#include <algorithm>
using std::string;
using std::unordered_map;
using std::max;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> pos;
        int left = 0;
        int res = 0;
        for(int i = 0; i < s.size(); ++i){
            if(pos.find(s[i]) != pos.end()){
                left = max(left, (pos.find(s[i]))->second + 1);  //select the larger left_pos between left_pos of current substring and the newly found duplicate char. 
            }
            pos[s[i]] = i;
            int length = i - left + 1;
            if(length > res)
                res = length;
        }
        return res;
    }
};


//As a side note, we can also use a hash set.
//reference: https://leetcode.com/problems/longest-substring-without-repeating-characters/solution/
public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        Set<Character> set = new HashSet<>();
        int ans = 0, i = 0, j = 0;
        while (i < n && j < n) {
            // try to extend the range [i, j]
            if (!set.contains(s.charAt(j))){
                set.add(s.charAt(j++));
                ans = Math.max(ans, j - i);
            }
            else {
                set.remove(s.charAt(i++));
            }
        }
        return ans;
    }
}
