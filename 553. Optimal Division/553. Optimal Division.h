/*
https://leetcode.com/problems/optimal-division/description/
Given a list of positive integers, the adjacent integers will perform the float division. For example, [2,3,4] -> 2 / 3 / 4.

However, you can add any number of parenthesis at any position to change the priority of operations. You should find out how to add parenthesis to get the maximum result, and return the corresponding expression in string format. Your expression should NOT contain redundant parenthesis.

Example:
Input: [1000,100,10,2]
Output: "1000/(100/10/2)"
Explanation:
1000/(100/10/2) = 1000/((100/10)/2) = 200
However, the bold parenthesis in "1000/((100/10)/2)" are redundant, 
since they don't influence the operation priority. So you should return "1000/(100/10/2)". 

Other cases:
1000/(100/10)/2 = 50
1000/(100/(10/2)) = 50
1000/100/10/2 = 0.5
1000/100/(10/2) = 2

Note:
The length of the input array is [1, 10].
Elements in the given array will be in range [2, 1000].
There is only one optimal division for each test case.

*/
//This problem is easy in math. We only need use a pair of parentheses to include numbers starting from the second position.
#include <string>
using std::string;
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        string res = "";
        if(n == 1){
            res += to_string(nums[0]);
            return res;
        }
        if(n == 2){
            res += to_string(nums[0]) + "/" + to_string(nums[1]);
            return res;
        }
        res += to_string(nums[0]) + "/(";
        for(int i = 1; i < n-1; ++i)
            res += to_string(nums[i]) + "/";
        res += to_string(nums[n-1]) + ")";
        return res;        
    }
};
