// Source : https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/
// Author : Min Fang
// Date   : 2025-10-07

/**********************************************************************************
*
* Problem: Longest Subsequence with Non-Zero Bitwise XOR
*
* You are given an integer array `nums`.
* Return the length of the longest subsequence in `nums` whose **bitwise XOR**
* is non-zero. If no such subsequence exists, return 0.
*
* ---------------------------------------------------------------------------------
*
* Example 1:
*   Input:  nums = [1, 2, 3]
*   Output: 2
*   Explanation:
*     One valid subsequence is [2, 3] → 2 ^ 3 = 1 (non-zero)
*
* Example 2:
*   Input:  nums = [2, 3, 4]
*   Output: 3
*   Explanation:
*     Entire array is a valid subsequence → 2 ^ 3 ^ 4 = 5 (non-zero)
*
* ---------------------------------------------------------------------------------
*
* Constraints:
*   - 1 <= nums.length <= 10^5
*   - 0 <= nums[i] <= 10^9
*
*
* Approach: XOR Property and Greedy Check
*
* Key Observations:
*   - XOR is associative and commutative → order doesn't matter.
*   - If the XOR of all elements is **non-zero**, the entire array is a valid
*     subsequence.
*   - If the XOR of all elements is **zero**, we need to remove at least one
*     non-zero element to get a non-zero result.
*   - If all elements are zero, no valid subsequence exists → return 0.
*
* Implementation Details:
*   - Use a variable `ans` to store the total XOR of all elements.
*   - Use a boolean flag `nonzero` to check if there is any non-zero number.
*   - Traverse the array once:
*       → For each element, XOR it into `ans`.
*       → Set `nonzero = true` if we encounter any non-zero element.
*   - After the loop:
*       → If `ans != 0`, return full length.
*       → Else if any non-zero number exists, return `length - 1`.
*       → Otherwise, return 0.
*
* Time Complexity: O(n)
*   - We iterate through the array once.
*
* Space Complexity: O(1)
*   - Only constant extra space is used.
*
**********************************************************************************/
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool nonzero = false;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(!nonzero && nums[i] != 0){
                nonzero = true;
            }
            ans = ans ^ nums[i];
        }
        if(ans == 0){
            if(nonzero){
                return nums.size() - 1;
            }else{
                return 0;
            }
        }else{
            return nums.size();
        }
    }
};
            return nums.size();  // Entire array is valid
        }
    }
};
