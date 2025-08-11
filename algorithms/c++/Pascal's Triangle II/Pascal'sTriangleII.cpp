// Source : https://leetcode.com/problems/pascals-triangle-ii/
// Author : Min Fang
// Date   : 2025-08-11

/**********************************************************************************
*
* Problem: Pascal's Triangle II
*
* Given an integer rowIndex, return the rowIndex-th (0-indexed) row of Pascal's triangle.
*
* In Pascal's triangle, each number is the sum of the two numbers directly above it.
*
* Example 1:
*   Input: rowIndex = 3
*   Output: [1,3,3,1]
*
* Example 2:
*   Input: rowIndex = 0
*   Output: [1]
*
* Example 3:
*   Input: rowIndex = 1
*   Output: [1,1]
*
* Constraints:
*   - 0 <= rowIndex <= 33
*
* Follow-up:
*   - Use only O(rowIndex) extra space.
*
*
* Approach:
*
* - Use the combinatorial formula for the elements in Pascal's triangle:
*     1. C(n, k) = C(n - 1, k) + C(n - 1, k - 1)
*     2. C(n, k) = C(n, k - 1) * (n - k + 1) / k
*     This formula allows calculating the k-th element of the row in O(1) time from the previous one.
*
* - Initialize the result vector `ans` with the first element as 1.
* - Use a loop from i = 1 to rowIndex to compute each element based on the previous one.
*
* - A `long long` temporary variable `t` is used to avoid overflow during intermediate computation.
* - Each computed value is then cast back to int before appending to the result.
*
*
* Time Complexity: O(n)
*   - Only one pass through the row is needed.
*
* Space Complexity: O(n)
*   - Only a single vector of size rowIndex + 1 is used.
*
**********************************************************************************/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        int temp = 0;
        long long t = 1;
        ans.push_back(1);
        for(int i = 1; i <= rowIndex; i++){
            temp = t * (ans[i-1]) * (rowIndex - i + 1) / i;
            ans.push_back(int(temp));
        }
        return ans;
    }
};

