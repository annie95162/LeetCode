// Source : https://leetcode.com/problems/split-array-with-minimum-difference/
// Author : Min Fang
// Date   : 2025-09-29

/**********************************************************************************
*
* Problem: Split Array Into Strictly Increasing and Decreasing Subarrays
*
* Given an integer array `nums`, split it into exactly two non-empty subarrays:
*     - `left` must be strictly increasing
*     - `right` must be strictly decreasing
*
* Return the **minimum possible absolute difference** between the sums of `left` and `right`.
* If **no valid split exists**, return -1.
*
*
* Example 1:
*   Input:  nums = [1, 3, 2]
*   Output: 2
*   Explanation:
*     Valid splits:
*       [1] and [3,2] → |1 - 5| = 4
*       [1,3] and [2] → |4 - 2| = 2 (minimum)
*
* Example 2:
*   Input:  nums = [1, 2, 4, 3]
*   Output: 4
*
* Example 3:
*   Input:  nums = [3, 1, 2]
*   Output: -1
*   Explanation: No valid split into increasing and decreasing subarrays.
*
*
* Constraints:
*   - 2 <= nums.length <= 10^5
*   - 1 <= nums[i] <= 10^5
*
*
* Approach: One-Pass Greedy Split
*
* 1. Start traversing from the beginning:
*     - Build a strictly increasing `left` subarray
*     - Accumulate the sum of `left` while traversing
*
* 2. When increasing order breaks (nums[i] >= nums[i+1]):
*     - Stop left part at current position
*     - If nums[i] == nums[i+1], it's invalid as neither increasing nor decreasing
*       → In this case, break and return -1
*
* 3. Continue with the rest of the array and:
*     - Verify that it forms a strictly decreasing subarray
*     - Accumulate the sum of `right`
*
* 4. At the point of split, we try two ways of accounting for the mid element:
*     - Either consider `mid` as part of `left` or `right`
*     - Compute both absolute differences and take the minimum
*
* 5. Return the minimum absolute difference
*
*
* Edge Cases Handled:
* - Equal adjacent numbers → invalid split
* - Entire array is increasing or decreasing → invalid split
*
*
* Time Complexity: O(n)
*   - One pass to find the increasing sequence
*   - Another pass to validate and sum the decreasing sequence
*
* Space Complexity: O(1)
*   - Only integer counters are used
*
**********************************************************************************/
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        long long ans = -1;
        long long lefts = 0;
        long long rights = 0;
        int mid = nums[0];
        lefts += mid;
        int i = 0;
        while(i < nums.size()-1){
            if(nums[i] < nums[i+1]){
                lefts += nums[i+1];
                i++;
            }else if(nums[i] == nums[i+1]){
                rights += nums[i];
                i++;
                break;
            }else{
                break;
            }
        }
        mid = nums[i];
        while(i < nums.size()-1){
            if(nums[i] > nums[i+1]){
                rights += nums[i];
                i++;
            }else{
                return ans;
            }
        }
        rights += nums[i];
        ans = min(abs(rights-mid-lefts), abs(rights+mid-lefts));
        return ans;
    }
};
