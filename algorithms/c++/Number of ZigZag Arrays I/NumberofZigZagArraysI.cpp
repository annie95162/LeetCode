// Source : https://leetcode.com/problems/number-of-zigzag-arrays-i/
// Author : Min Fang
// Date   : 2025-09-29

/**********************************************************************************
*
* Problem: Count Valid ZigZag Arrays
*
* Given three integers `n`, `l`, and `r`, the goal is to count how many arrays
* of length `n` exist such that:
*
*   1. Each element belongs to the range [l, r]
*   2. No two adjacent elements are equal
*   3. No three consecutive elements form a strictly increasing or strictly decreasing sequence
*
* The result must be returned modulo 10^9 + 7.
*
* ---------------------------------------------------------------------------------
* Example 1:
*   Input:  n = 3, l = 4, r = 5
*   Output: 2
*   Explanation:
*     Valid arrays: [4, 5, 4], [5, 4, 5]
*
* Example 2:
*   Input:  n = 3, l = 1, r = 3
*   Output: 10
*
* ---------------------------------------------------------------------------------
*
* Constraints:
*   - 3 <= n <= 2000
*   - 1 <= l < r <= 2000
*
*
* Approach: Dynamic Programming with Prefix Sum Optimization
*
* Define a 3D DP table:
*   - dp[i][dir][x]:
*       Represents the number of valid ZigZag arrays of length `i`,
*       ending with value `x`, with the previous step being in direction `dir`.
*
* Direction `dir` is defined as:
*   - dir = 0 → last move was a "down" (i.e., previous value > current), next must be "up"
*   - dir = 1 → last move was an "up" (i.e., previous value < current), next must be "down"
*
* Transitions:
*   - If current direction is UP (dir = 0):
*       → All previous values must be less than the current value.
*       → dp[i][0][y] = sum(dp[i-1][1][x]) for all x > y
*
*   - If current direction is DOWN (dir = 1):
*       → All previous values must be greater than the current value.
*       → dp[i][1][y] = sum(dp[i-1][0][x]) for all x < y
*
* To avoid O(r²) time complexity, prefix sums are used:
*
* Prefix Sum Optimization:
*   - Use a 2D array `pf[r+2][2]` to maintain running totals.
*     → pf[t][0] stores suffix sums for direction = 0 (going up next)
*     → pf[t][1] stores prefix sums for direction = 1 (going down next)
*
* Initialization:
*   - At i = 1:
*       → Any value from l to r can be the first element.
*       → dp[1][0][x] = 1, dp[1][1][x] = 1 for all x in [l, r]
*
* Recurrence with Prefix Sums:
*   - Before each dp level is computed:
*     → Calculate pf[t][1] = sum(dp[i-1][0][l..t-1])
*     → Calculate pf[t][0] = sum(dp[i-1][1][t+1..r])
*   - Then for each value j in [l, r]:
*     → dp[i][0][j] = pf[j+1][0]
*     → dp[i][1][j] = pf[j-1][1]
*
* Final Answer:
*   - The total number of valid ZigZag arrays of length `n`
*     is the sum of all dp[n][0][k] and dp[n][1][k], for k in [l, r]
*
*
* Time Complexity: O(n * r)
*   - n iterations for array length
*   - r iterations per level, with prefix sums amortizing inner computations
*
* Space Complexity: O(n * 2 * r)
*   - 3D dynamic programming table: dp[n+1][2][r+1]
*   - 2D prefix sum array: pf[r+2][2]
*
**********************************************************************************/
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(2, vector<long long>(r+1,0)));
        // dp[i][0][k] 是 下降完後有i的數字並且停在數字k
        int less = 0;
        int large = 0;
        int ans = 0;
        for(int i = l; i <= r; i++){
            dp[1][0][i] = 1;
            dp[1][1][i] = 1;
        }
        vector<vector<int>> pf(r+2, vector<int>(2,0));
        for(int i = 2; i <= n; i++){
            pf[l-1][1] = 0;
            for(int t = l; t <= r; t++){
                pf[t][1] = (pf[t-1][1] + dp[i-1][0][t]) % MOD;
            }
            pf[r+1][0] = 0;
            for(int t = r; t >= l; t--){
                pf[t][0] = (pf[t+1][0] + dp[i-1][1][t]) % MOD;
            }

            for(int j = l; j <= r; j++){
                dp[i][0][j] = pf[j+1][0];
                dp[i][1][j] = pf[j-1][1];
            }
        }
        for(int k = l; k <= r; k++){
            ans = (ans + dp[n][0][k]) % MOD;
            ans = (ans + dp[n][1][k]) % MOD;
        }
        return ans;
    }
};
