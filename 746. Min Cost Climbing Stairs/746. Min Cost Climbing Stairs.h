/*
On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

//there is something wrong about the comprehension of " where to end", the value in cost[i] means you have to pay the cost to stride over ith floor.

// time complexity: O(n) ; space complexity: O(1)

*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int add_cost = 0;
        int add_0 = cost[0];
        int add_1 = cost[1];
        if(cost.size() == 2)
            return cost[1];
        for(int i = 2; i<cost.size(); i++)
        {
            add_cost = cost[i] + min(add_0, add_1);
            add_0 = add_1;
            add_1 = add_cost;
        }
        return min(add_cost, add_0);
        
    }
};
