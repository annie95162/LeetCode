// Source : https://leetcode.com/problems/compute-decimal-representation/
// Author : Min Fang
// Date   : 2025-09-29

/**********************************************************************************
*
* Problem: Decimal Representation Using Base-10 Components
*
* You are given a positive integer `n`.
*
* A **base-10 component** is a number that can be expressed as:
*     - a single digit from 1 to 9, **multiplied by a non-negative power of 10**
*     - e.g., 500, 30, 7 are valid; 537, 102, 11 are not.
*
* Your task is to express `n` as a sum of the **fewest possible base-10 components**,
* and return them in **descending order**.
*
*
* Example 1:
*   Input:  n = 537
*   Output: [500, 30, 7]
*   Explanation: 537 = 500 + 30 + 7 (all valid base-10 components)
*
* Example 2:
*   Input:  n = 102
*   Output: [100, 2]
*
* Example 3:
*   Input:  n = 6
*   Output: [6]
*   Explanation: 6 is already a base-10 component.
*
*
* Constraints:
*   - 1 <= n <= 10^9
*
*
* Approach: Digit-by-Digit Decomposition (Right-to-Left)
*
* - Initialize a temporary list `temp` to store base-10 components (not necessarily ordered).
* - Start with the lowest digit (ones place), and process digit by digit (right to left):
*     - If the current digit is non-zero, compute its base-10 component by:
*         digit_value = (digit) × (current place value)
*         → Push this value into `temp`
* - After processing all digits, reverse `temp` to obtain descending order.
*
* - Example (n = 537):
*     - Ones place: 7 → 7×1 = 7
*     - Tens place: 3 → 3×10 = 30
*     - Hundreds: 5 → 5×100 = 500
*     → temp = [7, 30, 500]
*     → Reverse → [500, 30, 7]
*
*
* Time Complexity: O(log₁₀(n))
*   - We iterate over each digit of n (maximum 10 digits for n ≤ 10^9)
*
* Space Complexity: O(log₁₀(n))
*   - We store each non-zero digit’s base-10 component in a vector
*
**********************************************************************************/
class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> temp;
        int cnt = 1;
        while(n >= 10){
            if(n%10){
                temp.push_back(cnt*(n%10));
            }
            n = n/10;
            cnt *= 10;
        }
        if(n%10){
            temp.push_back(cnt*n);
        }

        vector<int> ans;
        for(int i = temp.size()-1; i >= 0; i--){
            ans.push_back(temp[i]);
        }
        return ans;
    }
};
