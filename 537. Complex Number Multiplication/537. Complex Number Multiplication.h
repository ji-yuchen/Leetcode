/*
https://leetcode.com/problems/complex-number-multiplication/description/
Given two strings representing two complex numbers.
You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.

Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.

Note:
The input strings will not have extra blank.
The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
*/
//Pay attention to the use of "to_string" and "substr"
#include <string>
#include <algorithm>
using std::string;
using std::find;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int ar = getreal(a); //a_real
        int ac = getcom(a);  //a_complex
        int br = getreal(b);
        int bc = getcom(b);
        int rr = ar*br - ac*bc;
        int rc = ar*bc + ac*br;
        return to_string(rr) + "+" + to_string(rc) + "i";
    }
private:
    int getreal(string& a){
        int res = 1;
        int start = 0;
        if(a[0] == '-'){
            res = -1;
            ++start;
        }
        int end = find(a.begin(), a.end(), '+') - a.begin();
        res *= stoi(a.substr(start, end));//string substr (size_t pos = 0, size_t len = npos) const; len means length, not endpos.
        return res;        
    }
    int getcom(string& a){
        int res = 1;
        int start = find(a.begin(), a.end(), '+') - a.begin() + 1;
        if(a[start] == '-'){
            res = -1;
            ++start;
        }
        int end = find(a.begin()+start, a.end(), 'i') - a.begin();
        res *= stoi(a.substr(start, end-start));
        return res;
    }
};
