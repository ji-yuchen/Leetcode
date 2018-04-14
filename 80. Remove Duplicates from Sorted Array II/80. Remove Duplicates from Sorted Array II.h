/**/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = 1;
        int count = 2;//If set count = 1 here, the res may out the bound. Such as{0,1,2,2} the nums[count] != nums[res-1] at first.
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return 1;
        while(count < nums.size()){
            if(nums[count]!=nums[res-1]){
                swap(nums[++res],nums[count]);
            }
            ++count;
        }
        return res+1;       
    }
};
