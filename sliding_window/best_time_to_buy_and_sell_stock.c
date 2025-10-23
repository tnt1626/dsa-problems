// -----------------------------------------------------------------------------
// Problem: Best Time to Buy and Sell Stock
// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Author : Ngoc-Tien To
// -----------------------------------------------------------------------------

// ---------------------------------- DESCRIPTION ----------------------------------
//
// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock 
// and choosing a different day in the future to sell that stock.
//
// Return the maximum profit you can achieve from this transaction.
// If you cannot achieve any profit, return 0.
//
// ----------------------------------------------------------------------------------


// ---------------------------------- IDEA ----------------------------------
//
// 1. Use one pass through the array.
// 2. Keep track of the minimum price seen so far (`buyPrice`).
// 3. At each day, compute potential profit = prices[i] - buyPrice.
// 4. Update the maximum profit if this profit is greater.
// 5. Return the final maximum profit.
//
// Time Complexity  : O(n)
// Space Complexity : O(1)
//
// -----------------------------------------------------------------------------


int maxProfit(int* prices, int pricesSize) {
    int profit = 0;             // 1. Track maximum profit found so far
    int buyPrice = prices[0];   // 2. Track minimum stock price seen so far (best day to buy)

    // 3. Iterate through all days
    for(int i = 0; i < pricesSize; i++){
        // 4. Update buyPrice if a lower price is found
        buyPrice = prices[i] < buyPrice ? prices[i] : buyPrice;

        // 5. Calculate profit if sold today, and update maximum profit
        profit = prices[i] - buyPrice > profit ? prices[i] - buyPrice : profit;
    }

    // 6. Return the maximum profit
    return profit;
}
