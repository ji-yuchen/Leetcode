/*
https://leetcode.com/problems/missing-number/description/
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

// It's a basic problem, many new problems can derive from it.


*/
#include <vector>
#include <algorithm>
using std::vector;
using std::sort;

//Time complexity : O(n) ; Space complexity : O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size() == 0)
            return -1;
        int N = nums.size();
        int sum_N = (N+1)*N/2;
        int sum_nums = 0;
        for(int i = 0; i < nums.size(); i++)
            sum_nums += nums[i];
        return sum_N - sum_nums;
    }
};

//Time complexity : O(nlgn) ; Space complexity : O(1)
/*
class Solution{
public:
    int missingNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    if(nums[n-1] != n)
        return n;
    if(nums[0] != 0)
        return 0;
    for(int i = 0; i<n; i++)
    {

        if(nums[i] != nums[i+1] - 1)
            return i+1;
    }
    }
};

*/
                
