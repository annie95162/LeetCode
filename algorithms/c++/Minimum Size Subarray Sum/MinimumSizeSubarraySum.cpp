// Source : https://leetcode.com/problems/minimum-size-subarray-sum/
// Author : Min Fang
// Date   : 2025-08-20

/**********************************************************************************
*
* Problem: Minimum Size Subarray Sum
*
* Given an array of positive integers `nums` and a positive integer `target`,
* return the minimal length of a **contiguous subarray** of which the sum is
* greater than or equal to `target`. If there is no such subarray, return 0 instead.
*
*
* Example 1:
*   Input:  target = 7, nums = [2,3,1,2,4,3]
*   Output: 2
*   Explanation: The subarray [4,3] has the minimal length of 2.
*
* Example 2:
*   Input:  target = 4, nums = [1,4,4]
*   Output: 1
*
* Example 3:
*   Input:  target = 11, nums = [1,1,1,1,1,1,1,1]
*   Output: 0
*
*
* Constraints:
*   - 1 <= target <= 10^9
*   - 1 <= nums.length <= 10^5
*   - 1 <= nums[i] <= 10^4
*
*
* Approach: Sliding Window (Two Pointers)
*
* - Initialize two pointers: `left` and `i` (right side of the window).
* - Use a running sum to keep track of the current subarray sum.
* - As you expand the window by moving `i`, add `nums[i]` to the sum.
* - When the current sum is greater than or equal to target:
*     - Try to **shrink** the window from the left to find the minimal length.
*     - Move `left` to the right while `sum - nums[left] >= target`.
*     - Update `ans` to store the minimal length found.
* - After the loop, if no valid window is found (`ans` still INT_MAX), return 0.
*
*
* Time Complexity: O(n)
*   - Each element is added and removed from the window at most once.
*
* Space Complexity: O(1)
*   - Constant extra space is used.
*
**********************************************************************************/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int sum = 0;
        int left = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while(sum - nums[left] >= target){
                sum -= nums[left];
                left++;
            }
            if(sum >= target){
                ans = min(ans, i - left + 1);
            }
        }
        if(ans == INT_MAX){
            ans = 0;
        }
        return ans;
    }
};
