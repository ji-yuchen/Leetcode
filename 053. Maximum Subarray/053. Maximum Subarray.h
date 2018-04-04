/*
https://leetcode.com/problems/maximum-subarray/description/

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

*/
#include <vector>
using std::vector;

//=w= The best solution i saw in the "sword towards offer". Time complexity: O(N).
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ret = nums[0];
        for(int i = 0; i < nums.size(); i++)
        {
            sum = max(sum + nums[i], nums[i]);
            ret = max(sum, ret);
        }
        return ret;
    }
};


//Divide and Conquer solution
//The recurrence is: T(n) = 2T(n / 2) + O(N); T(1) = 1. Time complexity: O(NlogN).
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0) return 0;
        return maxSubArrayDivideConquerFunction(nums,0,nums.size()-1);
    }
    
    int maxSubArrayDivideConquerFunction(vector<int>& A, int left, int right){
        
        if(left == right) 
            return A[left];
        int mid = left + (right - left) / 2;
        int leftMAX = maxSubArrayDivideConquerFunction(A, left, mid);
        int rightMAX = maxSubArrayDivideConquerFunction(A, mid+1, right);
        int left_cross = A[mid];
        int right_cross = A[mid+1];
        int tmp = 0;
        for(int i = mid; i>=left; --i){
            tmp += A[i];
            left_cross = max(tmp, left_cross);
        }
        tmp = 0;
        for(int i = mid+1; i<=right; ++i){
            tmp += A[i];
            right_cross = max(tmp, right_cross);
        }
        return max(max(leftMAX, rightMAX), left_cross+right_cross);
    }
};
