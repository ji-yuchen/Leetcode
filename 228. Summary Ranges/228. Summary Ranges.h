/*
Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:
Input: [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Example 2:
Input: [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
*/

#include<vector>
#include<string>
using std::vector;
using std::string;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int head = 0;
        int end = 0;
        vector<string> res;
        //I tried use"nums[i] != (nums[i-1]+1)" as a condition, which results some problems dealing with "i = size - 1 " condition.        
        for(int i = 0; i < nums.size(); i++){
            if(i == nums.size()-1 || nums[i] != (nums[i+1]-1)){
                if(head < i)
                    res.push_back(to_string(nums[head]) + "->" + to_string(nums[i]));
                else
                    res.push_back(to_string(nums[head]));
                head = i+1;
            }            
        }
        return res;
    }
};
