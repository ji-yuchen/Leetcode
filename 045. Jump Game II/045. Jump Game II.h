/*
https://leetcode.com/problems/jump-game-ii/description/

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:
Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.

Note:
You can assume that you can always reach the last index.
*/

#include <vector>
#include <algorithm>
using std::vector;
using std::max;
//For every step of jump, we try to locate the start and end of it. Once the end get to the end of array, we return the step recorded.
class Solution {
public:
    int jump(vector<int>& nums) {
        //You can assume that you can always reach the last index.
        int step = 0;
        int n = nums.size();
        int start = 0, end = 0;
        while(end < n-1){
            ++step;
            int next_end = end + 1;
            for(int i = start; i <= end; ++i){
                if(i + nums[i] >= n - 1)
                    return step;
                next_end = max(i + nums[i], next_end);
            }
            start = end + 1;
            end = next_end;
        }
        return step;
        
    }
};

//Then, we find we don't need to update start and end for every step.
//We record the max position we can reach at this step, and number of steps at that time. Only update again when we reach the max position from last step. 
class Solution {
public:
    int jump(vector<int>& nums) {
        //You can assume that you can always reach the last index.
        int step = 0;
        int n = nums.size();
        int start = 0, end = 0;
        int max = 0;
        while(end < n){
            if(end > max){
                ++step;
                max = start;
                if(max > n - 2)
                    return step;
            }
            start = std::max(end+nums[end], start);
            ++end;            
        }
        return step;
        
    }
};
