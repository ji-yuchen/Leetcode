/*
https://leetcode.com/problems/basic-calculator-ii/description/
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:
Input: "3+2*2"
Output: 7

Example 2:
Input: " 3/2 "
Output: 1

Example 3:
Input: " 3+5 / 2 "
Output: 5

Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/

//Try using sstream to simplify our codes.

#include <sstream>
#include <string>
using std::istringstream;
using std::string;

class Solution {
public:
    int calculate(string s) {
        istringstream in('+' + s + '+');
        int res = 0;
        int num = 0;
        int tmp = 0;//number for divide or multiple
        char op;
        while(in >> op){
            if(op=='+'||op=='-'){
                res += num;
                in>>num;
                if(op=='-')
                    num =-1*num;
            }else {
                in>>tmp;                
                if(op=='*')
                    num=num*tmp;
                else
                    num=num/tmp;
            }
        }
        return res;
    }
};
