/*
https://leetcode.com/problems/subsets-ii/description/

Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Please compare with "Subsets I" 
https://github.com/JupiterXXX/Leetcode/blob/master/078.%20Subsets/078.%20Subsets.h

let us use [1,2,3,4] as an example to explain my solution:

subsets([1,2,3,4]) = []
                     // push(1)
                     [1, subsets([2,3,4])] // if push N times in subsets([2,3,4]), the pop times is also N, so vec is also [1] after backtrack.
                     // pop(), push(2)
                     [2, subsets([3,4])]
                     // pop(), push(3)
                     [3, subsets([4])]
                     // pop(), push(4)
                     [4, subsets([])]
                     // pop()

*/

#include <vector>
#include <algorithm>
using std::vector;
using std::sort;


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> vec;
        subsetsWithDup(res, nums, vec, 0);
        return res;
        
    }
    
private:
    void subsetsWithDup(vector<vector<int>>& res, vector<int>& nums, vector<int>& vec, int begin){
        res.push_back(vec);
        for(int i = begin; i != nums.size(); ++i){
            if(i == begin || nums[i] != nums[i-1]){
                vec.push_back(nums[i]);
                subsetsWithDup(res, nums, vec, i+1);
                vec.pop_back();
            }
        }
    }
};
