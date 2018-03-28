/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

//Think about what we need to get max_profit at prices[i]. Then use variables to save them.

time complexity: O(n) ; space complexity: O(1).

*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_price = INT_MAX;
        for(int i =0; i<prices.size(); i++)
        {
            if(prices[i]<min_price)
                min_price = prices[i];
            else if(prices[i] - min_price > max_profit)
            {
                max_profit = prices[i] - min_price;
            }
                
        }
        return max_profit;
    }
};
