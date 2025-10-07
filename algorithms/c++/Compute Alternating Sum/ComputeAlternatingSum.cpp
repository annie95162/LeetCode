// Source : https://leetcode.com/problems/compute-alternating-sum/
// Author : Min Fang
// Date   : 2025-10-07

/**********************************************************************************
*
* Problem: Alternating Sum of an Array
*
* Given an integer array `nums`, compute its **alternating sum**, defined as:
*   nums[0] - nums[1] + nums[2] - nums[3] + ... (i.e., alternate between adding
*   and subtracting elements based on index parity).
*
* ---------------------------------------------------------------------------------
*
* Example 1:
*   Input:  nums = [1, 3, 5, 7]
*   Output: -4
*   Explanation:
*     Alternating sum = 1 - 3 + 5 - 7 = -4
*
* Example 2:
*   Input:  nums = [100]
*   Output: 100
*   Explanation:
*     Only one element (even index), so result is 100
*
* ---------------------------------------------------------------------------------
*
* Constraints:
*   - 1 <= nums.length <= 100
*   - 1 <= nums[i] <= 100
*
*
* Approach: Greedy Linear Scan
*
* Key Idea:
*   - Traverse the array once while alternating the sign of each element
*     depending on its index.
*   - Use a `cov` (coefficient) variable initialized to +1, and flip its sign
*     after each iteration.
*
* Implementation Details:
*   - Initialize `ans = 0` to store the result.
*   - Initialize `cov = 1` to apply alternating sign (+1, -1, +1, ...).
*   - For each element `nums[i]`, do:
*       → ans += nums[i] * cov
*       → cov *= -1
*
* Time Complexity: O(n)
*   - We visit each element of the array exactly once.
*
* Space Complexity: O(1)
*   - Only a few integer variables are used; no extra memory required.
*
**********************************************************************************/
class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int ans = 0;
        int cov = 1;
        for(int i = 0; i < nums.size(); i++){
            ans += nums[i]*cov;
            cov *= -1;
        }
        return ans;
    }
};
