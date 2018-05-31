/*
https://leetcode.com/problems/basic-calculator/description/
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

Example 1:
Input: "1 + 1"
Output: 2

Example 2:
Input: " 2-1 + 2 "
Output: 3

Example 3:
Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23

Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/
#include <stack>
#include <string>
using std::stack;
using std::string;

class Solution {
public:
    int calculate(string s) {
        stack <int> signs, nums;
        int res = 0;//result for return
        int sign = 1;//'+'or'-'
        int num = 0;//current num
        for(auto c:s){
            if(c>='0'&&c<='9'){
                num = 10*num + c - '0';
            }else if(c == '+'){
                res += num*sign;
                num = 0;
                sign = 1;
            }else if(c == '-'){
                res += num*sign;
                num = 0;
                sign = -1;
            }else if(c == '('){
                nums.push(res);
                signs.push(sign);
                res = 0;
                sign = 1;
            }else if(c == ')'){
                res += num*sign;
                num = 0;
                res = res*signs.top() + nums.top();
                signs.pop();
                nums.pop();
            }
        }
        res += num*sign;
        return res;        
    }
};
