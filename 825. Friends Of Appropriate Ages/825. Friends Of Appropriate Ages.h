/*
https://leetcode.com/problems/friends-of-appropriate-ages/description/

Some people will make friend requests. The list of their ages is given and ages[i] is the age of the ith person. 

Person A will NOT friend request person B (B != A) if any of the following conditions are true:

age[B] <= 0.5 * age[A] + 7
age[B] > age[A]
age[B] > 100 && age[A] < 100
Otherwise, A will friend request B.

Note that if A requests B, B does not necessarily request A.  Also, people will not friend request themselves.

How many total friend requests are made?

Example 1:

Input: [16,16]
Output: 2
Explanation: 2 people friend request each other.

Notes:

1 <= ages.length <= 20000.
1 <= ages[i] <= 120.

*/
//The value of ages is limited within 1 to 120. So we can rearrange the array to reduce the computation.
//At first I just use brute force which result time limit exceeding=.=
//Time complexity: O(A^2+N) where N is the number of people, and A is the number of ages.
//Space complexity: O(A)

#include<vector>
using std::vector;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        int res = 0;
        vector<int> count(121,0);
        for(auto i : ages){
            ++count[i];
        }
        for(int ageA = 1; ageA <= 120; ++ageA){
            int countA = count[ageA];
            for(int ageB = 0.5 * ageA + 7 + 1; ageB<=ageA; ++ageB){
                int countB = count[ageB];
                res += countA*(countB-(ageA==ageB));
            }
            //res += countA*(countA-1);//Though A=B, they must satisfy condition(1)
        }
        
        return res;
    }
};
