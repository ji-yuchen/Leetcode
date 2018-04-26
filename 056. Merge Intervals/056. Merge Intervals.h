/*
https://leetcode.com/problems/merge-intervals/description/

Given a collection of intervals, merge all overlapping intervals.

Example 1:
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considerred overlapping.

*/
//Time complexity: O(NlogN) ; Space complexity: O(N)
//Just sort the original array, and then judge whether merge two intervals one by one depending on simple rules.


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(const Interval& a, const Interval& b){
    return a.start < b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval> res;
        
        for(auto& i : intervals){
            if(res.empty()||i.start > res.back().end)
                res.push_back(i);
            else{
                res.back().end = max(i.end, res.back().end);
            }
        }
        return res;
    }
    
    
};
