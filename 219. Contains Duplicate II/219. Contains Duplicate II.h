/*
https://leetcode.com/problems/contains-duplicate-ii/description/

Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Using a hashset to store the prev k elements of nums[i]. check and update the set every loop.
*/
#include <vector>
#include <unordered_set>
using std::vector;
using std::unordered_set;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> sheet;
        if(k <= 0) return false;
        for(int i = 0; i < nums.size(); i++){
            if(i > k) sheet.erase(nums[i - k - 1]);
            if(sheet.find(nums[i])!=sheet.end()) return true;
            sheet.insert(nums[i]);
        }
        return false;
    }
};
