/*
https://leetcode.com/problems/restore-ip-addresses/description/

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:
Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
*/
#include <string>
#include <vector>
using std::string;
using std::vector;

//Using iteration
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        string ans;
        
        for (int a=1; a<=3; a++)
        for (int b=1; b<=3; b++)
        for (int c=1; c<=3; c++)
        for (int d=1; d<=3; d++)
            if (a+b+c+d == s.length()) {
                int A = stoi(s.substr(0, a));
                int B = stoi(s.substr(a, b));
                int C = stoi(s.substr(a+b, c));
                int D = stoi(s.substr(a+b+c, d));
                if (A<=255 && B<=255 && C<=255 && D<=255)
                    if ( (ans=to_string(A)+"."+to_string(B)+"."+to_string(C)+"."+to_string(D)).length() == s.length()+3)
                        ret.push_back(ans);
            }    
        
        return ret;
    }
};

//Using backtracking
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        
        vector<string> ret;
        helper(s, ret, 0, "", 0);
        return ret;
    }   
    void helper(string s, vector<string> &ret, int index, string current, int count) {
        
        if (count > 4) return;
        if (count == 4 && index == s.size()) { ret.push_back(current); return;}
        
        for(int i = 1; i < 4; i++) {
            if ((index + i) > s.size()) break;
            string temp = s.substr(index,i);
            if (((temp[0] == '0') && (temp.size() > 1)) || ((i == 3) && (stoi(temp) > 255))) continue;
            helper(s, ret, index+i, current + temp + (count == 3 ? "" : "."), count+1);
        }
    }
};
