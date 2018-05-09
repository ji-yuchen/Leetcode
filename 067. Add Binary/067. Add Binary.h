/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
*/
//I'm not familiar with bits operations, so I write the operation one by one =.=
#include<string>
using std::string;

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size()>=b.size())
            return addbinary(a,b);
        else
            return addbinary(b,a);        
    }
    string addbinary(string& a, string& b){
        string res = "";
        int as = a.size();
        int bs = b.size();
        int tmp = 0;
                 
        for(int i = 0; i < bs; ++i){
            int sum = tmp;
            if(a[as-1-i]=='1')
                ++sum;
            if(b[bs-1-i]=='1')
                ++sum;
           
            if(sum > 1){
                if(sum == 2){
                    tmp = 1;
                    res+="0";
                }else if(sum == 3 ){
                    tmp = 1;
                    res+="1";
                }
            }else if(sum == 1){
                tmp = 0;
                res+="1";
            }else if(sum == 0){
                tmp = 0;
                res+="0";
            }
        }
        
            
        for(int i = 0; i < as - bs; ++i){
            int sum = tmp;
            if(a[as-bs-1-i]=='1')
                ++sum;
                
            if(sum > 1){
                tmp = 1;
                res+="0";
            }else if(sum == 1){
                tmp = 0;
                res+="1";
            }else{
                tmp = 0;
                res+="0";
            }
        }
        if(tmp == 1){
            res+="1";
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
