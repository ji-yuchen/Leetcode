/*
https://leetcode.com/problems/valid-triangle-number/description/
Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

*/


#include <vector>
#include <algorithm>
using std::vector;
using std::sort;
//This is my brute force solutin, obviously its time complexity is O(N^3). space complexity : O(1)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3)
            return 0;
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i = 0; i < nums.size() - 2; i++)
            for(int j = i + 1; j < nums.size() - 1; j++){
                int sum = nums[i] + nums[j];
                int tmp = j + 1;
                while(nums[tmp] < sum && tmp < nums.size())
                {
                    tmp++;
                }

                count += tmp-1-j;
            }
        return count;
    }
};

//Save one traversal.
//Time complexity: O(N^2)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3)
            return 0;
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i = nums.size()-1; i>=0;--i)
        {
            int j =0;
            int k =i-1;
            while(j<k)
            {
                if(nums[j]+nums[k]>nums[i]){
                    count += k - j;
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return count;
    }
};
