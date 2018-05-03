/*
https://leetcode.com/problems/k-diff-pairs-in-an-array/description/
Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and their absolute difference is k.

Example 1:
Input: [3, 1, 4, 1, 5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.

Example 2:
Input:[1, 2, 3, 4, 5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).

Example 3:
Input: [1, 3, 1, 5, 4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).

Note:
The pairs (i, j) and (j, i) count as the same pair.
The length of the array won't exceed 10,000.
All the integers in the given input belong to the range: [-1e7, 1e7].
*/
#include<vector>
#include<unordered_map>
using std::vector;
using std::unordered_map;

//Solution using unordered_map, which is direct and convinient。
//Time complexity：O(N); Space complexity: O(N)

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0)
            return 0;
        unordered_map<int,int> s;
        int res = 0;
        for(auto i : nums)
            ++s[i];
        for(auto p : s){
            if((!k&&p.second>1)||(k&&s.count(p.first + k)))
                ++res;
        }
        return res;
        
    }
};

//Solution using sorting and two points. Pay attention to skip some loops to save computation.
//Time complexity: O(NlogN); Space complexity: O(1)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for(int i =0, j =0; i < nums.size(); ++i){
            for(j = max(j, i+1); j < nums.size() && ( nums[j] - nums[i] < k); ++j)
                ;
            if(j < nums.size() && nums[j] - nums[i] == k)
                ++res;
            while(i+1 < nums.size() && nums[i] == nums[i+1])
                ++i;
        }
        return res;
    }
};
