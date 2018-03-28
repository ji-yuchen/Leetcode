/*
https://leetcode.com/problems/subsets/description/

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.


//It's a very important problem for me in case that i'm not familiar with these three solutions now.
*/

//Iterative 
//Initially: [[]]
//Adding the first number to all the existed subsets: [[], [1]];
//Adding the second number to all the existed subsets: [[], [1], [2], [1, 2]];
//Adding the third number to all the existed subsets: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]].
#include<vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs (1, vector<int>());
        for(int i = 0; i< nums.size(); i++)
        {
            int n = subs.size();
            for( int j =0; j < n; j++)
            {
                subs.push_back(subs[j]);
                subs.back().push_back(nums[i]);
            }
        }
        
        return subs;
    }
};


//recursive(backtracking)
//Initially: [[]]
//[[], [1], [1, 2], [1, 2, 3]]
//[[], [1], [1, 2], [1, 2, 3], [1, 3], [2], [2, 3], [3]]


class Solution{
public:
    vector<vector<int>> subsets(vector<int>& nums){
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs;
        vector<int> sub;
        ret_subsets(nums, 0, sub, subs);
        return subs;
    }
    void ret_subsets(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& subs){
        subs.push_back(sub);
        for(int i =start; i < nums.size(); i++)
        {
            sub.push_back(nums[i]);
            ret_subsets(nums, i+1, sub, subs);
            sub.pop_back();
        }
    }
    
}

//Bit Manipulation
//[], [], [], [], [], [], [], []
//[], [1], [], [1], [], [1], [], [1]
//[], [1], [2], [1, 2], [], [1], [2], [1, 2]
//[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]
class Solution{
public:
    vetor<vector<int>> subsets(vector<int>& nums){
        sort(nums.begin(), nums.end());
        int num_subset = pow (2, nums.size());
        vector<vector<int>> ret(num_subset, vector<int>());
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < num_subset; j++)
                if((j >> i) & 1)
                    ret[j].push_back(nums[i]);
        }
        return ret;
    }
}
