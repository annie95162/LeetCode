// Source : https://leetcode.com/problems/pascals-triangle/
// Author : Min Fang
// Date   : 2025-08-11

/**********************************************************************************
*
* Problem: Pascal's Triangle
*
* Given an integer numRows, return the first numRows of Pascal's triangle.
* In Pascal's triangle, each number is the sum of the two numbers directly above it.
*
* Example 1:
*   Input: numRows = 5
*   Output: [[1],
*            [1,1],
*            [1,2,1],
*            [1,3,3,1],
*            [1,4,6,4,1]]
*
* Example 2:
*   Input: numRows = 1
*   Output: [[1]]
*
* Constraints:
*   - 1 <= numRows <= 30
*
*
* Approach:
*
* - Initialize an empty 2D vector `ans` to store each row of Pascal's Triangle.
*
* - For each row index `i` from 0 to numRows - 1:
*     - Add a new empty vector to `ans` to represent the current row.
*     - For each position `j` in the current row (from 0 to i):
*         - If `j == 0` or `j == i`, append 1 to the row.
*         - Otherwise, calculate the value as the sum of the two values
*           directly above from the previous row:
*           ans[i][j] = ans[i-1][j-1] + ans[i-1][j]
*
* - After building all rows, return the result.
*
*
* Time Complexity: O(n^2)
* - A total of n(n+1)/2 values are computed, where n = numRows.
*
* Space Complexity: O(n^2)
* - The entire triangle is stored in memory as a 2D vector.
*
**********************************************************************************/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0; i < numRows; i++){
            ans.push_back(vector<int>());
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i){
                    ans[i].push_back(1);
                }else{
                    ans[i].push_back(ans[i-1][j-1] + ans[i-1][j]);
                }
            }
        }
        return ans;


    }
};
