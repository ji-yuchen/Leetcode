/*
https://leetcode.com/problems/combination-sum-ii/description/
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

This problem differs from "Combination Sum " by excluding duplicate combinations.
*/

#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> local;
        combinationSum2(res, 0, target, local, candidates);
        return res;
    }
    void combinationSum2(vector<vector<int>>& res, int begin, int target, vector<int>& local, vector<int>& candidates){
        if(!target){
            res.push_back(local);
            return;
        }
        
            for(int i = begin; i < candidates.size(); i++){
                if(candidates[i]>target)
                    return;
                if(i > begin && candidates[i] == candidates[i-1]) // try to use [1,1,1],2 as an input to understand this. 
                    continue;
                local.push_back(candidates[i]);
                combinationSum2(res, i+1, target - candidates[i], local, candidates);//Here use i+1 instead of i in "combination-sum" to avoid reuse one element.
                local.pop_back();
        
        }
    }
};
