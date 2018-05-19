/*
https://leetcode.com/problems/student-attendance-record-i/description/
You are given a string representing an attendance record for a student. The record only contains the following three characters:
'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).
You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True

Example 2:
Input: "PPALLL"
Output: False
*/
#include <string>
using std::string;

class Solution {
public:
    bool checkRecord(string s) {
        int AR = 0;
        int LR = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i]=='A'){
                ++AR;
                LR = 0;
                if(AR == 2)
                    return false;
            }else if(s[i]=='L'){
                ++LR;
                if(LR == 3)
                    return false;
            }else//At first, I did't use this "else", leading to LR=0 occuring every loop.
                LR = 0;            
        }
        return true;        
    }
};
