/*
https://leetcode.com/problems/search-for-a-range/description/

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

*/
//Time complexity: O(N); Space complexity: O(1)
//This is my first solution. Though I use binary search, I use "traversal" to find the start and end of the target value sequence, which cost O(n).

#include<vector>
using std::vector;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int second = -1;
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] > target)
                end = mid - 1;
            else if(nums[mid] < target)
                start = mid+1;
            else{
                int tmp = mid;
                while(nums[tmp] == target){
                    --tmp;
                    if(tmp < 0)
                        break;
                }
                first = tmp + 1;
                tmp = mid;
                while(nums[tmp] == target){
                    ++tmp;
                    if(tmp == nums.size())
                        break;
                }
                second = tmp - 1;
                break;
            }
        }
        vector<int> res{first, second};
        return res;
    }
};


//reference to https://leetcode.com/problems/search-for-a-range/discuss/14699/Clean-iterative-solution-with-two-binary-searches-(with-explanation)
//Use two binary search to separately locate the left and right target.
//Time complexity: O(NlogN); Space complexity: O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int second = -1;
        vector<int> res{first, second};
        int start = 0;
        int end = nums.size() - 1;
        if(start > end)
            return res;
        while (start < end){
            int mid = start + (end - start)/2;
            if(nums[mid] < target)
                start = mid + 1 ;
            else end = mid;
        }
        if(nums[start]!=target)
            return res;
        else res[0] = start;
        end = nums.size() - 1;
        while (start < end){
            int mid = start + (end - start)/2 + 1;
            if(nums[mid]>target)
                end = mid - 1;
            else start = mid;
        }
        res[1] = end;
        return res;
    }
};
