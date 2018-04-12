/*
https://leetcode.com/problems/longest-consecutive-sequence/description/
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
*/


//Sort
//Time complexity: O(NlogN); Space complexity: O(1)
#include<vector>
#include<unordered_set>
#include<algorithm>
using std::vector;
using std::unordered_set;
using std::sort;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int res = 1;
        int max = 1;
        for(int i =1; i<nums.size(); i++){
            if(nums[i] == nums[i-1])
                continue;
            if(nums[i] == nums[i-1]+1){
                ++max;
                if(max>res)
                    res = max;
            }
            else{
                max = 1;
            }
            
        }
        return res;
    }
};


//HashSet
//Time complexity: O(N); Space complexity: O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> record(nums.begin(), nums.end());
        int res = 1;
        if(nums.size()==0)
            return 0;
        for(int n : nums){
            if(record.find(n) == record.end())
                continue;
            record.erase(n);
            int prev = n-1;
            int next = n+1;
            while(record.find(prev) != record.end())
                record.erase(prev--);
            while(record.find(next) != record.end())
                record.erase(next++);
            res = max(res, next-prev-1);
        }
        return res;
    }
};
