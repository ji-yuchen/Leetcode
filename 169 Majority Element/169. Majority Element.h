#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

//Time complexity : O(nlgn)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return(nums[nums.size()/2]);
    }
};


//Time complexity : O(n)
/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
                candidate = nums[i];
            if(nums[i] == candidate)
                count++;
            else
                count--;
        }
        return candidate;
        
    }
};


*/
