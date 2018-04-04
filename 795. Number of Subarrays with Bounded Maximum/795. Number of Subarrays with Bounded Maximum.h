/*
https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/description/

We are given an array A of positive integers, and two positive integers L and R (L <= R).

Return the number of (contiguous, non-empty) subarrays such that the value of the maximum array element in that subarray is at least L and at most R.


emmmm maybe i am not able to think of the solution at a short time.
*/

#include <vector>
using std::vector;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int ret = 0;
        int left = -1;
        int right = -1;
        for(int i =0; i<A.size(); i++){
            if(A[i] > R)
                left = i;
            if(A[i] >= L)
                right = i;
            ret += right - left;
        }
        return ret;
    }
};
