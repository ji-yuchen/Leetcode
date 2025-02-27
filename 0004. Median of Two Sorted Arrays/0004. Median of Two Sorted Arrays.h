/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106


*/



class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size_1 = nums1.size();
        int size_2 = nums2.size();
        if(size_1>size_2){
            return findMedianSortedArrays(nums2, nums1);
        }
        //find a partition pos in [0, size_1] of nums1
        //to make nums1[i-1] <= nums[j] && nums[j-1] <= nums1[i]
        int length = size_1 + size_2;
        int totalLeft = (length + 1) / 2; // the nums of nums on the left of the partition pos for both nums1 and nums2
        int low = 0;
        int high = size_1;
        int median1 = 0;
        int median2 = 0;
        while(low <= high){
            int i = low + (high - low)/2;   // the partition pos for nums1 in this round
            int j = totalLeft - i;              // the partition pos for nums2..
            int nums1LeftMax = ((i == 0)? INT_MIN:nums1[i-1]);
            int nums1RightMin = ((i == size_1)? INT_MAX:nums1[i]);
            int nums2LeftMax = ((j == 0)? INT_MIN:nums2[j-1]);
            int nums2RightMin = ((j == size_2)? INT_MAX:nums2[j]);
            if(nums1LeftMax <= nums2RightMin){
                 low = i+1;
                 median1 = max(nums1LeftMax, nums2LeftMax);
                 median2 = min(nums1RightMin, nums2RightMin);
            }else{
                high = i-1;
            }
        }
        return (length%2==0)? (median1+median2)/2.0 : median1;

    }
};
