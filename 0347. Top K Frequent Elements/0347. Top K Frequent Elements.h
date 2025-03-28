/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.


*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            freqs[nums[i]]++;
        }
        vector<vector<int>> buckets(nums.size()+1);
        for(auto& [num, freq] : freqs){
            buckets[freq].push_back(num);
        }
        for(int i = buckets.size()-1; i >=0; i--){
            if(res.size()==k){
                break;
            }
            for(int j = 0; j < buckets[i].size(); j++){
                res.push_back(buckets[i][j]);
                if(res.size()==k){
                    break;
                }
            }
        }
        return res;
    }
};
