/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = 1;
        int count = 2;//If set count = 1 here, the res may out the bound. Such as{0,1,2,2} the nums[count] != nums[res-1] at first.
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return 1;
        while(count < nums.size()){
            if(nums[count]!=nums[res-1]){
                swap(nums[++res],nums[count]);
            }
            ++count;
        }
        return res+1;       
    }
};
