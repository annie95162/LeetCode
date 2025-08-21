// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Author : Min Fang
// Date   : 2025-08-21

/**********************************************************************************
*
* Problem: Best Time to Buy and Sell Stock
*
* Given an array `prices` where `prices[i]` is the price of a given stock on day `i`,
* you want to maximize your profit by choosing a single day to buy one stock and a
* different day in the future to sell that stock.
*
* Return the maximum profit you can achieve from this transaction. If no profit is
* possible, return 0.
*
*
* Example 1:
*   Input:  prices = [7,1,5,3,6,4]
*   Output: 5
*   Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6),
*                profit = 6 - 1 = 5.
*
* Example 2:
*   Input:  prices = [7,6,4,3,1]
*   Output: 0
*   Explanation: No profitable transaction is possible, so return 0.
*
*
* Constraints:
*   - 1 <= prices.length <= 10^5
*   - 0 <= prices[i] <= 10^4
*
*
* Approach: One-pass Greedy Algorithm
*
* - Initialize `min` to the first price to track the lowest buying price seen so far.
* - Initialize `ans` to 0 to track the maximum profit.
* - Iterate through the prices starting from the second day:
*     - Calculate the potential profit if selling on the current day: `prices[i] - min`.
*     - Update `ans` if this profit is higher than the current max profit.
*     - Update `min` if the current price is lower than any seen before (better buying day).
* - Return `ans` as the maximum profit found.
*
*
* Time Complexity: O(n)
*   - Single pass through the array.
*
* Space Complexity: O(1)
*   - Uses only a few integer variables.
*
**********************************************************************************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int min = prices[0];
        int ps = prices.size();
        for(int i = 1; i < ps; i++){
            ans = max(ans, prices[i] - min);
            if(prices[i] < min){
                min = prices[i];
            }
        }
        return ans;
    }
};
