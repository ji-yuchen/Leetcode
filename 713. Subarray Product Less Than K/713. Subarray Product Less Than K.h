/*
https://leetcode.com/problems/subarray-product-less-than-k/description/

Your are given an array of positive integers nums.

Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.


*/

#include <vector>
using std::vector;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0)
            return 0;
        int res = 0;
        int sum = 1;
        for(int left = 0, right = 0; right < nums.size(); ++right){
            sum *= nums[right];
            while(left <= right && sum >= k){
                sum /= nums[left++];                
            }
            res += right - left + 1;// accumulate once when right++;
            
        }
        return res;
    }
};
