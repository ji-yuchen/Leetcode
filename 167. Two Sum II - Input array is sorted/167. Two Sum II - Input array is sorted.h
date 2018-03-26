/*
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

Solution:
try to search from beginning and end at the same time. track two nums at the first and the last at the same time. if the two nums add is bigger than "target", --last;else if smaller, ++first.
Do until find the two nums equal the "target".

Time complexity： O(n).
*/




#include <vector>
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;
        auto head = 0;
        auto foot = numbers.size() - 1;
        while(foot > head){
            
            if((numbers[head] + numbers[foot]) > target)
                foot--;
            else if((numbers[head] + numbers[foot]) < target)
                head++;
            if((numbers[head] + numbers[foot]) == target)
            {
                ret.push_back(head+1);
                ret.push_back(foot+1);
                return ret;
            }
            
                
        }
        return ret;
        
    }
};
