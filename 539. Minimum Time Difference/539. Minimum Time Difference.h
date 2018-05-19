/*
https://leetcode.com/problems/minimum-time-difference/description/

Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.

Example 1:
Input: ["23:59","00:00"]
Output: 1

Note:
The number of time points in the given list is at least 2 and won't exceed 20000.
The input time is legal and ranges from 00:00 to 23:59.
*/

#include <string>
#include <algorithm>
using std::string;
using std::sort;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        sort(timePoints.begin(), timePoints.end());
        int res = 1440;
        for(int i = 0; i < n; ++i){
            int diff = abs(minutes(timePoints[i]) - minutes(timePoints[(i-1+n)%n]));
            diff = min(diff, 1440 - diff);
            res = min(res, diff);
        }
        return res;
    }
private:
    int minutes(const string& time){
        int res = (time[0]-'0')*60*10 + (time[1]-'0')*60 + (time[3]-'0')*10 + (time[4]-'0');//we can also use this: stoi(time.substr(0, 2));
        return res;
    }
};
