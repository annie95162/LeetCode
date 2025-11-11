// Source : https://leetcode.com/problems/maximum-product-of-three-elements-after-one-replacement/
// Author : Min Fang
// Date   : 2025-11-02

/**********************************************************************************
*
* Problem: Maximum Product After One Replacement
*
* You are given an integer array `nums`.
* You must replace exactly one element in the array with **any integer value**
* within the range [-10^5, 10^5] (inclusive).
*
* After this replacement, determine the **maximum possible product** of any three
* distinct elements from the modified array.
*
* Return an integer representing the maximum achievable product.
*
*
* Example 1:
*   Input:  nums = [-5, 7, 0]
*   Output: 3500000
*   Explanation:
*     Replace 0 with -10^5 → [-5, 7, -100000]
*     Product = (-5) * 7 * (-100000) = 3,500,000
*
* Example 2:
*   Input:  nums = [-4, -2, -1, -3]
*   Output: 1200000
*   Explanation:
*     Replace -2 or -1 with 10^5:
*     Example: [-4, -1, -3] → (-4) * (-3) * (10^5) = 1,200,000
*
* Example 3:
*   Input:  nums = [0, 10, 0]
*   Output: 0
*   Explanation:
*     No matter which 0 is replaced, one 0 remains.
*     Hence, any product of three elements includes 0 → result = 0.
*
*
* Constraints:
*   - 3 <= nums.length <= 10^5
*   - -10^5 <= nums[i] <= 10^5
*
*
* Approach: Greedy Observation using Absolute Maximums
*
* 1. The maximum product of three numbers depends on choosing the combination of
*    largest absolute values (positive or negative) that yield the largest magnitude.
*
* 2. Since we can replace **any one number** with any value in [-10^5, 10^5],
*    the optimal replacement is to introduce ±10^5 to maximize the final product magnitude.
*
* 3. Therefore:
*      - Find the two largest absolute values from the array (`max1` and `max2`).
*      - The maximum product after replacement = max1 * max2 * 10^5
*
* 4. Return this value as the result.
*
*
* Example Walkthrough:
*   nums = [-5, 7, 0]
*   Largest absolute values = 7, 5
*   Product = 7 * 5 * 100000 = 3,500,000
*
*
* Time Complexity: O(n)
*   - Single pass to find top two absolute values.
*
* Space Complexity: O(1)
*   - Only a few variables are used for tracking maximums.
*
**********************************************************************************/
class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int idx = 0;
        int max1 = 0;
        int max2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(max1 < abs(nums[i])){
                max2 = max1;
                max1 = abs(nums[i]);
            }else if(max2 < abs(nums[i])){
                max2 = abs(nums[i]);
            }
        }
        long long ans = max1;
        ans *= max2;
        ans *= 100000;
        return ans;
    }
};
