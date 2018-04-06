/*
https://leetcode.com/problems/subarray-sum-equals-k/description/

Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

*/

#include<vector>
#include<unordered_map>
using std::vector;
using std::unordered_map;

//Brute Force: First i want to use two points, head and end, to traverse "nums" once. But the condition of this problem is not what i thought(the num in nums may < 0 =.=).
//Time complexity: O(N^2) ; Space complexity: O(N)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int head = 0;
        int end = 0;
        int count = 0;
        vector<int> sum(nums.size()+1,0);
        for (int i = 1; i <= nums.size(); i++)
            sum[i] = sum[i - 1] + nums[i - 1];
        for (int start = 0; start < nums.size(); start++) {
            for (int end = start + 1; end <= nums.size(); end++) {
                if (sum[end] - sum[start] == k)
                    count++;
            }
        }
        return count;
        
    }
};

//hash map: use a hash map to store the cultimative number.
//Time complexity: O(N); Space complexity: O(1)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int result = 0;  
        
        c<int, int> count;
        count[0] = 1;
 
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (count.find(sum - k) != count.end()) {
                result += count[sum-k];//every "sum-k" before will contribute to the result
            }
            count[sum]++;
            
        }
        
        return result;
        
    }
};
