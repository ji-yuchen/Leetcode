/*
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:
Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?

*/

#include <vector>
#include <algorithm>
using std::vector;
using std::reverse;

//Using an extra array to help store the aimed order elements.
//Time complexity: O(N); Space complexity:O(N)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp = nums;
        k = k%nums.size();
        for(int i = 0; i < nums.size(); ++i){
            tmp[(i+k)%nums.size()] = nums[i];
        }
        nums = tmp;   
    }
};

//Using std::reverse
//Time complexity: O(N); Space complexity: O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        //Reverses the order of the elements in the range [first,last)
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};
