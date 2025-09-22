// Source : https://leetcode.com/problems/maximum-total-subarray-value-i/
// Author : Min Fang
// Date   : 2025-09-22

/**********************************************************************************
*
* Problem: Max Total Value of Chosen Subarrays
*
* You are given an integer array `nums` of length `n` and an integer `k`.
*
* You must choose **exactly `k` non-empty subarrays** `nums[l..r]` from the array.
* - Subarrays may overlap.
* - The **same subarray (same `l` and `r`) can be chosen more than once**.
*
* The value of a subarray is defined as:
*   max(nums[l..r]) - min(nums[l..r])
*
* The total value is the **sum of the values** of all chosen subarrays.
*
* Your goal is to return the **maximum total value** you can achieve.
*
*
* Example 1:
*   Input:  nums = [1, 3, 2], k = 2
*   Output: 4
*   Explanation:
*     Choose [1, 3] → max = 3, min = 1 → value = 2
*     Choose [1, 3, 2] → max = 3, min = 1 → value = 2
*     Total value = 2 + 2 = 4
*
* Example 2:
*   Input:  nums = [4, 2, 5, 1], k = 3
*   Output: 12
*   Explanation:
*     Choose [4, 2, 5, 1] three times → each value = 4 (max 5 - min 1)
*     Total = 4 + 4 + 4 = 12
*
*
* Constraints:
*   - 1 <= nums.length <= 5 * 10^4
*   - 0 <= nums[i] <= 10^9
*   - 1 <= k <= 10^5
*
*
* Approach: Global Max - Min × k
*
* - Observe that the value of a subarray is always max - min.
* - To maximize the value of each selected subarray, choose the subarray that gives the biggest difference.
* - The maximum possible value from any subarray is (global_max - global_min).
* - Since we can select the same subarray multiple times, we can simply pick the one with the largest value difference `k` times.
* - Thus, the maximum total value is:
*       (max of nums - min of nums) * k
*
* Steps:
*   - Iterate through the array to find the global maximum and minimum values.
*   - Compute their difference.
*   - Multiply by k to get the result.
*
*
* Time Complexity: O(n)
*   - One pass through the array to find max and min.
*
* Space Complexity: O(1)
*   - Only constant extra space used.
*
**********************************************************************************/

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long max = INT_MIN;
        long long min = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < min){
                min = nums[i];
            }
            if(nums[i] > max){
                max = nums[i];
            }
        }
        return (max-min)*k;
    }
};
