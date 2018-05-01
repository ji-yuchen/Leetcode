/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

*/
//At first I tried merge the new interval on the original intervals, which is more complex than new a result vector=.=
//However, the latter is much easier to code =.= Thanks to the high performance of "push_back", the latter one is also fast.lol


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
#include<vector>
using std::vector;

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int n = intervals.size();
        int s = newInterval.start;
        int e = newInterval.end;
        vector<Interval> res;
        for(int i = 0; i < n; ++i){
            if(intervals[i].end<s)
                res.push_back(intervals[i]);
            else if(intervals[i].start > e){
                res.push_back(newInterval);
                for(int j = i ; j < n; ++j)
                    res.push_back(intervals[j]);
                return res;               
            }
            else{//newinterval may overlap mutiple intervals
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }           
        }
        res.push_back(newInterval);
        return res;
        
    }
};
