/*
https://leetcode.com/problems/multiply-strings/description/
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"

Note:
The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
    string multiply(string num1, string num2) {
        int s1 = num1.size();
        int s2 = num2.size();
        vector<int> tmp(s1+s2, 0);
        for(int i = 0; i < s1; ++i){
            for(int j = 0; j < s2; ++j){
                tmp[i+j] += (num1[s1-i-1]-'0')*(num2[s2-j-1]-'0'); //USE "+=" TO ACCUMULATE ALL PRODUCTS AT [i, j]
            }
        }
        
        for(int i = 0; i < tmp.size()-1; ++i){
            tmp[i+1] += tmp[i]/10;//PAY ATTENTION TO THE RESULTS OF DIVISION AND MODULUS
            tmp[i] %= 10;
        }
        int pos = tmp.size()-1;//INITIALIZE POS WITH SIZE-1
        while(pos>0&&tmp[pos]==0) --pos;
        string res = "";
        while(pos >= 0){
            res += '0' + tmp[pos];
            --pos;
        }
            
        return res;
        
    }
};
