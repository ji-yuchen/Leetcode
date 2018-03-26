/*
https://leetcode.com/problems/combination-sum-iii/description/

Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

backtrack
中文称做「回溯法」，穷举多维度数据的方法，可以想作是多维度的Exhaustive Search。
大意是：把多维度数据看做是是一个多维向量（solution vector），然后运用递回依序递回穷举各个维度的值，制作出所有可能的数据（solution space），并且在递回途中避免列举出不正确的数据。


*/


#include <vector>
using std::vector;


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> path;
        backtrack(ret, path, 1, k ,n);
        return ret;

    }
    
    void backtrack(vector<vector<int>> &result, vector<int> &path, int start, int k, int n){
        if(k==0)
        {
            if(n==0)
                result.push_back(path);
            return;
        }
        for(int i = start; i<=10-k&&i<=n; i++)
        {
            path.push_back(i);
            backtrack(result, path, i+1, k-1, n-i);
            path.pop_back();
        }
    }
    
    
    
};
