/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

//dynamic programming QAQ
//there are only two states: we hold a stock or not. the action we do, sell or buy, changes the state to the other. So we maintain two states to record the maximum profits we could have in two states.



*/



class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int cash = 0;
        int hold = -prices[0];
        for(int i =0; i < prices.size(); i++)
        {
            cash = max(cash, hold + prices[i] -fee);
            hold = max(hold, cash - prices[i]);
        }
        return cash;
    }
};
