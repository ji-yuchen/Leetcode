#include <vector>
using std::vector

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int head = 1;
        int foot = 1;
        int N = nums.size();
        vector<int> ret(N, 1);
        for(int i = 0; i < N; i++)
        {
            ret[i] *= head;
            ret[N-1-i] *= foot;
            head *= nums[i];
            foot *= nums[N-1-i];
                        
        }
        return ret;
    }
};
