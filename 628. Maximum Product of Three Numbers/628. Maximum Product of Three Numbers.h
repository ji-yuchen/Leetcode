/*
https://leetcode.com/problems/maximum-product-of-three-numbers/description/

Given an integer array, find three numbers whose product is maximum and output the maximum product.
Note:
The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.


*/




class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size() == 1)
        return nums[0];
        else if(nums.size() == 2)
        return nums[0]*nums[1];
        else if(nums.size() == 3)
        return nums[0]*nums[1]*nums[2];
        
        int max_1 = -10001;
        int max_2 = -10001;
        int max_3 = -10001;
        int min_1 = 10001;
        int min_2 = 10001;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i]>max_1)
            {
                max_3 = max_2;
                max_2 = max_1;
                max_1 = nums[i];
            }else if(nums[i]>max_2)
            {
                max_3 = max_2;
                max_2 = nums[i];
            }else if(nums[i]>max_3)
            {
                max_3 = nums[i];
            }
            if(nums[i]<min_1)
            {
                min_2 = min_1;
                min_1 = nums[i];
            }else if(nums[i]<min_2)
            {
                min_2 = nums[i];
            }
        }
        return max(max_1*max_2*max_3, min_1*min_2*max_1); 
        
    }
};
