/*
https://leetcode.com/problems/smallest-range/description/
You have k lists of sorted integers in ascending order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.

Example 1:
Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Note:
The given list may contain duplicates, so ascending order means >= here.
1 <= k <= 3500
-105 <= value of elements <= 105.
For Java users, please note that the input type has been changed to List<List<Integer>>. And after you reset the code template, you'll see this point.

*/
//Use a priority to store each row of nums, ranking by head value of each row.
#include <queue>
#include <vector>
#include <algorithm>
#include <limits.h>

using std::vector;
using std::priority_queue;
using std::max;
using std::min;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        struct compare {
            bool operator()(pair<vector<int>::iterator,vector<int>::iterator> p1, pair<vector<int>::iterator, vector<int>::iterator> p2){
                return *p1.first > *p2.first;
            }
        };
        int lo = INT_MAX;
        int hi = INT_MIN;
        //template <class T, class Container = vector<T>, class Compare = less<typename Container::value_type> > class priority_queue;
        priority_queue<pair<vector<int>::iterator, vector<int>::iterator>, vector<pair<vector<int>::iterator, vector<int>::iterator>>, compare> pq;
        for (auto& row:nums){
            lo = min(lo, row[0]);
            hi = max(hi, row[0]);
            pq.push({row.begin(), row.end()});
        }
        vector<int> res = {lo, hi};
        while(true){
            auto p = pq.top();
            pq.pop();
            ++p.first;
            if(p.first == p.second)
                break;
            pq.push(p);
            
            lo = *pq.top().first;
            hi = max(hi, *p.first);
            if(hi-lo < res[1] - res[0])
                res = {lo, hi};
        }
        return res;
    }
};
