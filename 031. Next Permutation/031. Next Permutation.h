/*
https://leetcode.com/problems/next-permutation/description/

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/

//I'm confused with the pointer out of range.
//I'd better write like this:
//while(idx > 0 && nums[idx-1]>=nums[idx]){
//    --idx;
//}
//At first I write:
//while(nums[idx-1]>=nums[idx]){
//    --idx;
//    if(idx == 0)
//        break;
//}
#include<vector>
#include<algorithm>
using std::vector;
using std::swap;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 0|| n == 1)
            return;
        int idx = n - 1;
        
        while(idx > 0 && nums[idx-1]>=nums[idx]){
            --idx;
        }
        if(idx > 0){
            int min = n-1;
            
            while(nums[min]<=nums[idx-1])
                --min;
            
            swap(nums[idx-1], nums[min]);
        }
            
        for(int i = idx, j = n-1; i < j; ++i,--j)
            swap(nums[i], nums[j]);
        
    }
};
