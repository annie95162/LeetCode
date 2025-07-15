// Source : https://leetcode.com/problems/climbing-stairs/
// Author : Min Fang
// Date   : 2025-07-15

/********************************************************************************** 
* 
* You are climbing a staircase. It takes n steps to reach the top.
* Each time you can either climb 1 or 2 steps.
* This function returns the number of distinct ways you can climb to the top.
* 
* Approach:
* 
* - Uses dynamic programming with space optimization.
* - Only keeps track of the last two results to compute the next value.
* - Time complexity: O(n)
* - Space complexity: O(1)
* 
* For example:
*     Input: n = 3
*     Output: 3
*     Explanation:
*       1 step + 1 step + 1 step
*       1 step + 2 steps
*       2 steps + 1 step
* 
**********************************************************************************/
class Solution {
public:
    int climbStairs(int n) {
        int p = 1, q = 1, r = 1;
        for(int i = 2; i <= n; i++){
            r = q;
            q = p + q;
            p = r;
        }
        return q;

    }
};
