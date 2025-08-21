// Source : https://leetcode.com/problems/max-consecutive-ones/
// Author : Min Fang
// Date   : 2025-08-19

/**********************************************************************************
*
* Problem: Max Consecutive Ones
*
* Given a binary array `nums` (only containing 0s and 1s), return the **maximum**
* number of consecutive 1s in the array.
*
*
* Example 1:
*   Input:  nums = [1, 1, 0, 1, 1, 1]
*   Output: 3
*   Explanation: The last three digits are consecutive 1s.
*
* Example 2:
*   Input:  nums = [1, 0, 1, 1, 0, 1]
*   Output: 2
*
*
* Constraints:
*   - 1 <= nums.length <= 1e5
*   - nums[i] is either 0 or 1.
*
*
* Approach:
*
* - Iterate through the array with a loop.
* - Use a variable `cnt` to track the number of consecutive 1s.
* - Reset `cnt` to 0 when a 0 is encountered.
* - At each step, compare `cnt` with `ans` to store the maximum count seen so far.
* - After the loop ends, compare once more in case the array ends with 1s.
*
*
* Time Complexity: O(n)
*   - Traverse the array once.
*
* Space Complexity: O(1)
*   - Uses only a few integer variables.
*
**********************************************************************************/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                ans = max(cnt, ans);
                cnt = 0;
            }else if(nums[i] == 1){
                cnt++;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};
