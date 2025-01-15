/*
https://leetcode.com/problems/reverse-integer/description/

Given a 32-bit signed integer, reverse digits of an integer.

Example 1:
Input: 123
Output: 321

Example 2:
Input: -123
Output: -321

Example 3:
Input: 120
Output: 21
*/

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x){
            int temp = ans*10 + x%10;
            if(temp/10 != ans)//Detect if out of boundary
                return 0;
            ans = temp;
            x /= 10;
        }
        return ans;
    }
};
