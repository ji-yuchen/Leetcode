/*
https://leetcode.com/problems/third-maximum-number/description/

Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]
Output: 1
Explanation: The third maximum is 1.

Example 2:
Input: [1, 2]
Output: 2
Explanation: The third maximum does not exist, so the maximum (2) is returned instead.

Example 3:
Input: [2, 2, 3, 1]
Output: 1
Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
*/
//THIS FIRST SOLUTION IS FALSE!!
//At first, I tried traversal this array and record three max values=.= But there exist some problems with setting initial values with max1,2,3.

#include <vector>
#include <set>
#include <limits.h>
using std::vector;
using std::set;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int flag = 0;
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        for(int i = 0; i<nums.size(); ++i){
            if(nums[i] == max1 || nums[i] == max2 || nums[i] == max3)
                continue;
            else if(nums[i] > max1){
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
                ++flag;
            }else if(nums[i] > max2){
                max3 = max2;
                max2 = nums[i];
                ++flag;
            }else if(nums[i] > max3){
                max3 = nums[i];
                ++flag;
            }     
        }
        
        return flag>=3? max3:max1;
    }
};

//This solution uses set, which is easy and correct=.=(Of course, most work has been done by STL...)
//It can be accelerated by judging and inserting one by one, which avoids some sorting.lol
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        while(s.size()>3)s.erase(s.begin());        
        return s.size()==3? *s.begin():*s.rbegin();
    }
};

//This is awesome!!!!
//I found that in submission succss pageQAQ
//Based on that I write my edition.
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        int max1 = nums[0];
        int max2 = nums[0];
        int max3 = nums[0];
        for(int i = 1; i<nums.size(); ++i){
            if(nums[i] == max1 || nums[i] == max2 || nums[i] == max3)
                continue;
            else if(nums[i] > max1){
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
                
            }else if(nums[i] > max2||max2 == max1){
                max3 = max2;
                max2 = nums[i];
                
            }else if(nums[i] > max3||max3 == max2||max3 == max1){
                max3 = nums[i];
                
            }     
        }
        
        return (max1> max2&&max2>max3)? max3:max1;
    }
};
