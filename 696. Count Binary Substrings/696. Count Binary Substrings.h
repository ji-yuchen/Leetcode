/*
https://leetcode.com/problems/count-binary-substrings/description/

Give a string s, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

Example 1:
Input: "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".

Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.

Example 2:
Input: "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.

Note:
s.length will be between 1 and 50,000.
s will only consist of "0" or "1" characters.
*/
//We treat neighbour same nums as a group. The contiguous substrings having the same number of 0s and 1s must cross the boundary of two groups.
//So we check when the substring cross the boundary and add the min length of two groups to the result.
#include <string>
#include <algorithm>
using std::string;
using std::min;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0, prev = 0, cur = 1;
        for(int i = 1; i < s.length(); ++i){
            if(s[i-1]!=s[i]){
                res += min(prev, cur);
                prev = cur;
                cur = 1;
            }else{
                ++cur;
            }
        }
        return res + min(prev, cur);
    }
};
