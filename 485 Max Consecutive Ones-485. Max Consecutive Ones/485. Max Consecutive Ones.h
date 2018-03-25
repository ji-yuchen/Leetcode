#include<vector>
using std::vector;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count = 0;
        int count = 0;
        for(auto beg = nums.begin(); beg != nums.end(); beg++)
        {
            if(*beg == 1)
                count++;
            else{
                if(count > max_count)
                max_count = count;
                count = 0;

                
            }
                
        
        }  
        if (max_count < count) 
            max_count = count;
        return max_count;
        
    }
};
