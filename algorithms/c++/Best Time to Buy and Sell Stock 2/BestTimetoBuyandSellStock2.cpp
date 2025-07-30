// Source : https://leetcode.com/problems/group-anagrams/
// Author : Min Fang
// Date   : 2025-07-30

/**********************************************************************************
*
* Problem:
* You are given an integer array `prices` where `prices[i]` is the price of a given stock
* on the iᵗʰ day.
* On each day, you may decide to buy and/or sell the stock. You can only hold at most
* one share at any time. However, you can buy it then immediately sell it on the same day.
* Find and return the maximum profit you can achieve.
*
* Examples:
*   Input: prices = [7,1,5,3,6,4]
*   Output: 7
*   Explanation: Buy on day 2 (price = 1), sell on day 3 (5), profit = 4;
*                then buy on day 4 (3), sell on day 5 (6), profit = 3;
*                total = 7.
*
*   Input: prices = [1,2,3,4,5]
*   Output: 4
*   Explanation: Buy on day 1 (price = 1), sell on day 5 (5) → 4 in profit.
*
*   Input: prices = [7,6,4,3,1]
*   Output: 0
*   Explanation: Prices always down → no profit opportunity.
*
*
* Approach (Greedy):
* - Traverse the array once; maintain `profit = 0`.
* - For each day i from 1 to n−1:
*     if prices[i] > prices[i−1], do `profit += prices[i] − prices[i−1]`.
*   This effectively "buys yesterday and sells today" whenever profitable.
* - Return the sum of all such positive gains.
*
* Intuition:
* Since unlimited transactions are allowed and there's no fee or cooldown,
* accumulating every incremental gain captures the *maximum* possible profit:
* all upward price moves can be harvested independently :contentReference[oaicite:1]{index=1}.
* This greedy strategy is proven optimal in this problem setup :contentReference[oaicite:2]{index=2}.
*
* Time Complexity: O(n)
* - Single pass through `prices`.
*
* Space Complexity: O(1)
* - Only uses constant extra memory.
*
* Edge Cases Handled:
* - Empty or single-day array → loop doesn’t run → profit remains 0.
* - All decreasing or constant prices → no positive difference → profit = 0 :contentReference[oaicite:3]{index=3}.
*
**********************************************************************************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i = 0; i < prices.size()-1; i++){
            ans += max(0, prices[i+1] - prices[i]);
        }
        return ans;
    }
};
/**********************************************************************************
*
* Solution 2
*
**********************************************************************************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int now = 0;
        bool buy = false;
        if(prices.size() == 1){
            return 0;
        }
        if(prices[0] < prices[1]){
            now = prices[0];
            buy = true;
        }
        for(int i = 1; i < prices.size() - 1; i++){
            if(buy && prices[i] >= prices[i-1] && prices[i] > prices[i+1]){
                ans += prices[i] - now;
                buy = false;                
            }
            if(!buy && prices[i] < prices[i+1]){
                now = prices[i];
                buy = true;
            }
        }

        if(buy){
            ans += prices[prices.size()-1] - now;
        }
        return ans;
    }
};
