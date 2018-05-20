/*
https://leetcode.com/problems/count-and-say/description/

The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:
Input: 1
Output: "1"

Example 2:
Input: 4
Output: "1211"
*/
#include <string>
using std::string;

class Solution {
public:
    string countAndSay(int n) {
        if(n==0)
            return "1";
        string res = "1";
        for(int i = 0; i < n-1; ++i)
            readoff(res);
        return res;
        
    }
private:
    void readoff(string& A){
        string res = "";
        for(int i = 0; i < A.size(); ++i){
            int count = 1;
            while(i+1<A.size()&&A[i] == A[i+1]){
                ++count;
                ++i;
            }
            res += to_string(count) + A[i];
        }
        A = res;
    }
};
