#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int N = nums.size();
        vector<int> ret;
        for(int i = 0; i < N; i++)
        {
            int index = abs(nums[i]) - 1;
            if(nums[index] > 0) 
                nums[index] = -nums[index];
            
        }
        for(int i = 0; i < N; i++)
        {
            if(nums[i] > 0)
                ret.push_back(i + 1);
        }
        return ret;
    }
};
