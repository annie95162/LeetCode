// Source : https://leetcode.com/problems/maximum-average-subarray-i/
// Author : Min Fang
// Date   : 2025-08-19

/********************************************************************************** 
*
* Problem: Maximum Average Subarray I
*
* You are given an integer array `nums` consisting of `n` elements, and an integer `k`.
*
* Find a contiguous subarray whose length is exactly `k` that has the **maximum average value**,
* and return this value. Any answer with a calculation error less than 10^-5 will be accepted.
*
*
* Example 1:
*   Input:  nums = [1,12,-5,-6,50,3], k = 4
*   Output: 12.75000
*   Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
*
* Example 2:
*   Input:  nums = [5], k = 1
*   Output: 5.00000
*
*
* Constraints:
*   - n == nums.length
*   - 1 <= k <= n <= 10^5
*   - -10^4 <= nums[i] <= 10^4
*
*
* Approach:
*
* - Use a **sliding window** of fixed size `k` to compute the sum of each subarray of length `k`.
*
* - Initialize two variables:
*     - `now` to track the current window sum
*     - `ans` to track the maximum sum found
*
* - In the first `k` elements, compute the initial sum.
*   Then, for each position `i >= k`, slide the window:
*     - Add the current element `nums[i]`
*     - Subtract the element that moves out `nums[i - k]`
*     - Update `ans` to keep the max sum so far
*
* - Finally, divide `ans` by `k` to get the maximum average.
*
*
* Key Insight:
* - Since the subarray length is fixed, tracking the sum via a sliding window
*   avoids recomputing sums from scratch, keeping the algorithm efficient.
*
*
* Time Complexity: O(n)
*   - Each element is visited only once.
*
* Space Complexity: O(1)
*   - Only a few variables are used, no extra data structures needed.
*
**********************************************************************************/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans;
        double now;
        for(int i = 0; i < nums.size(); i++){
            if(i < k){
                ans += nums[i];
                now = ans;
            }else{
                now = now + nums[i] - nums[i-k];
                ans = max(ans, now);
            }
        }
        ans /= k;
        return ans;
    }
};
