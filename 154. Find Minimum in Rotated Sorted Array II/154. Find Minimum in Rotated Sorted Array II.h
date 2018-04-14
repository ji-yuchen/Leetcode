/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/

Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

please compare with "Find Minimum in Rotated Sorted Array":
https://github.com/JupiterXXX/Leetcode/blob/master/153.%20Find%20Minimum%20in%20Rotated%20Sorted%20Array/153.%20Find%20Minimum%20in%20Rotated%20Sorted%20Array.h
the difference is marked as below.
*/
#include <vector>
using std::vector;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        if(start == end)
            return nums[start];
        if(nums[start]<nums[end])
            return nums[start];
        while(start < end){
            int mid=(start + end)/2;
            if(nums[mid] > nums[end]){
                start = mid+1;
            }
            else if(nums[mid] < nums[end]){
                end = mid;
            }
            else if(nums[start]==nums[mid]){
                //num[mid]==num[end]
                start++;
                end--;
            }
            else
                end = mid;
            }
        return nums[end];                
    }
};

//https://blog.csdn.net/feliciafay/article/details/42962131
//maybe I prefer this method=.= It's more clear.
int findMin(vector<int> &num) {  
    int start = 0, end = num.size() - 1, mid = 0;  
    while (start < end) {   
        while (start < end && num[start] == num[end]) //滤重，本题最重要的地方！  
            ++start;   
        mid  = start + (end - start)/2;  
        if (num[start] <= num[mid] && num[mid] <= num[end]) //如果是正常的升序数组  
            return num[start];  
        if (num[start] > num[mid]) { //和Find Minimum in Rotated Sorted Array I类似的逻辑  
            end = mid;  
        } else if (num[mid] > num[end]) { //和Find Minimum in Rotated Sorted Array I类似的逻辑  
            start = mid + 1;  
        }  
    }  
    return num[start] < num[end] ? num[start] : num[end]; //化简到最后，可能是1个元素或者2个元素。  
    }  
};  
