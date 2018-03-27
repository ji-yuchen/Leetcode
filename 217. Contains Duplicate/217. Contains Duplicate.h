/*
https://leetcode.com/problems/contains-duplicate/description/

Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

QAQ I'm not familiar with "set"or"map". Maybe it's the time to go back to "c++primer" or reading "algorithm" books.
*/
include <vector>
include <algorithm>
using std::vector;
using std::sort;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() == 0)
            return false;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i] == nums[i+1])
                return true;
        }
        return false;        
    }
};

/*
#include <set>
using std::set;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();        
    }
};



*/
