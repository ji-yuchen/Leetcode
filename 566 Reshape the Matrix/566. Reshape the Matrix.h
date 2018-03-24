#include<vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int r_in = nums.size();
        int c_in = nums[0].size();
        if((r_in*c_in)!=(r*c))
            return nums;
        vector<vector<int>> nums_re(r, vector<int>(c,0));
        int count_r = 0;
        int count_c = 0;
        for(int i = 0; i != r; i++)
        {
            for(int j =0; j != c; j++)
            {
                if(count_c == c_in)
                {
                    count_r++;
                    count_c = 0;
                }
                nums_re[i][j]=nums[count_r][count_c];
                count_c++;

            }
        }
        return nums_re;
    }
};
