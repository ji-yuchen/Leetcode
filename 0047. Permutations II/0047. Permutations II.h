/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10



A key difference between this solution and the former one in Permutations I is the duplicates.
We sort nums at the beginning.
To keep the order of nums to help check duplicates, we pass value instead of ref of nums in backTrack.


*/


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(begin(nums), end(nums));
        backTrack(nums, res, 0);
        return res;
    }
private:
    void backTrack(vector<int> nums, vector<vector<int>>& res, int count) {
        if (count == nums.size()) {
            res.push_back(nums);
        }
        for (int i = count; i < size(nums); ++i) {
            if (i != count && nums[i] == nums[count]) continue;
            swap(nums[i], nums[count]);
            backTrack(nums, res, count + 1);
        }
    }
};
