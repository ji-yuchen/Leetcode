/*
https://leetcode.com/problems/max-chunks-to-make-sorted-ii/description/

This question is the same as "Max Chunks to Make Sorted" except the integers of the given array are not necessarily distinct, the input array could be up to length 2000, and the elements could be up to 10**8.

Given an array arr of integers (not necessarily distinct), we split the array into some number of "chunks" (partitions), and individually sort each chunk.  After concatenating them, the result equals the sorted array.

What is the most number of chunks we could have made?

*/

//since integers are not distinct here. The "record max value" we do in last problem may encounter some difficulties.
//so we use a sorted array. record the sum of original array and the sum of the sorted array at the same time.
//Time complexity: O(NlogN) ; Space complexity: O(N).

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int sum1 = 0, sum2 = 0, ans = 0;
        vector<int> t = arr;
        sort(t.begin(), t.end());
        for(int i = 0; i < arr.size(); i++) {
            sum1 += t[i];
            sum2 += arr[i];
            if(sum1 == sum2) ans++;
        }
	    return ans;
    }
};

//Algorithm: Iterate through the array, each time all elements to the left are smaller (or equal) to all elements to the right, there is a new chunck.
//Use two arrays to store the left max and right min to achieve O(n) time complexity. Space complexity is O(n) too.
//This algorithm can be used to solve ver1 too.

class Solution {
public:
    int maxChunksToSorted(vector<int>& a) {
        int n = a.size();
        vector<int> b(n);
        b[n-1] = a[n-1];
        for( int i = n-2; i >=0; --i) b[i] = min(a[i],b[i+1]);
        int cnt = 1, ans = 1, mx = a[0];
        for (int i=1; i <n;++i) {
            if (b[i] < mx){
                ++cnt;
                mx = max(mx,a[i]);
            }                
            else{
                cnt = 1;
                ++ans;
                mx = a[i];
            }
                
        }
        return ans;
    }
};
