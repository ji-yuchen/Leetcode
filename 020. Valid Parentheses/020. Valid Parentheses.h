/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:
Input: "{[]}"
Output: true
*/

#include <string>
#include <stack>
using std::string;
using std::stack;

class Solution {
public:
    bool isValid(string s) {
        stack<char> tmp;
        for(auto &i : s){
            if(i == '(' || i == '[' || i == '{')
                tmp.push(i);
            else{
                if(tmp.empty()) return false;
                if(i == ')'&&tmp.top()!='(')return false;
                if(i == ']'&&tmp.top()!='[')return false;
                if(i == '}'&&tmp.top()!='{')return false;
                tmp.pop();
            }
        }
        return tmp.empty();
        
    }
};
