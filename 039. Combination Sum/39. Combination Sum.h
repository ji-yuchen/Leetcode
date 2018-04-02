/*
https://leetcode.com/problems/combination-sum/description/
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

//It's a classical backtracking problem.
//T(n) = T(n-1) + T(n-2) + T(n-2) …
//T(n-1) = T(n-2)+T(n-3)… use this to replace T(n-1) in the above,
//so T(n) = 2 * [ T(n-2) + T(n-3) ], and so on, T(n) = O(2^n)

*/


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> combination;
        combinationSum(candidates, target, ret, combination, 0);
        return ret;
    }
    void combinationSum(vector<int>& candidates, int target, vector<vector<int>>& ret, vector<int>& combination, int begin){
        if(!target){
            ret.push_back(combination);
            return;
        }
        for(int i = begin; i < candidates.size()&&target >= candidates[i]; ++i){
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], ret, combination, i);
            combination.pop_back();
        }
    }
};
