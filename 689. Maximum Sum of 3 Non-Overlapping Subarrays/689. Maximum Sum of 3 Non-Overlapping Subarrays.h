/*
https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/description/
In a given array nums of positive integers, find three non-overlapping subarrays with maximum sum.

Each subarray will be of size k, and we want to maximize the sum of all 3*k entries.

Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

//The question asks for three non-overlapping intervals with maximum sum of all 3 intervals. If the middle interval is [i, i+k-1], where k <= i <= n-2k, the left interval has to be in subrange [0, i-1], and the right interval is from subrange [i+k, n-1].

So the following solution is based on DP.

posLeft[i] is the starting index for the left interval in range [0, i];
posRight[i] is the starting index for the right interval in range [i, n-1]; 
Then we test every possible starting index of middle interval, i.e. k <= i <= n-2k, and we can get the corresponding left and right max sum intervals easily from DP. And the run time is O(n).

Time complexity: O(N) ; Space complexity: O(N)
*/

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int max_sum = 0;
        vector<int> sum = {0}, posLeft(n, 0), posRight(n, n-k), ans(3, 0);
        for(int i = 0; i < nums.size(); ++i)
            sum.push_back(sum.back()+nums[i]);
        for(int i = k, max_inv = sum[k] - sum[0]; i < n; ++i){
            if(sum[i+1] - sum[i+1-k] > max_inv)
            {
                max_inv = sum[i+1] - sum[i+1-k];
                posLeft[i] = i+1-k;
            }else
                posLeft[i] = posLeft[i-1];
        }
        for(int i = n-k-1, max_inv = sum[n] - sum[n-k]; i>=0;--i){
            if(sum[i+k] -sum[i]>=max_inv)//here use "=" to minimize the index
            {
                max_inv = sum[i+k] - sum[i];
                posRight[i] = i;
            }
            else
                posRight[i] = posRight[i+1];
        }
        for(int i = k; i<=n-2*k; i++){
            int l = posLeft[i-1];
            int r = posRight[i+k];
            int max_inv = sum[i+k] -sum[i] + sum[l+k] - sum[l] + sum[r+k] - sum[r];
            if(max_inv > max_sum){
                max_sum = max_inv;
                ans = {l,i,r};
            }
        }
        return ans;
    }
};
