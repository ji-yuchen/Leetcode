/*
https://leetcode.com/problems/maximum-swap/description/

Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

DP solution
Time Complexity: O(N); Space Complexity: O(N)

*/

class Solution {
public:
    int maximumSwap(int num) {
        string numString = to_string(num);
        int n = numString.size();
        vector<int> max_index(n, 0);
        max_index[n-1]=n-1;
        for(int i = n - 2; i >= 0; i--){
            if(numString[i] > numString[max_index[i+1]]){
                max_index[i] = i;
                
            }else{
                max_index[i] = max_index[i+1];    
            }                            
        }
        int i = 0;
        while(i < n){
            if(numString[i] < numString[max_index[i]]){
                swap(numString[i], numString[max_index[i]]);
                return stoi(numString);
            }
            ++i;
                
        }
        return stoi(numString);
    }
