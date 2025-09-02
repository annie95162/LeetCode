// Source : https://leetcode.com/problems/divide-two-integers/
// Author : Min Fang
// Date   : 2025-09-02

/**********************************************************************************
*
* Problem: Divide Two Integers
*
* Given two integers dividend and divisor, divide the two integers without using
* multiplication, division, or mod operators.
*
* The integer division should truncate toward zero (i.e., lose its fractional part).
* You must also ensure the result fits within the 32-bit signed integer range.
*
*
* Approach: Bit Manipulation + Doubling (Greedy)
*
* Key Ideas:
* - Since we cannot use multiplication or division, we simulate division using
*   repeated subtraction.
* - To make the subtraction more efficient, we use a "doubling" strategy:
*     - Keep doubling the divisor and store the results in a vector.
*     - Each doubling represents a multiple of the divisor (e.g., divisor*1, divisor*2, etc.)
*     - Then we go backwards through the vector, subtracting the largest possible
*       multiple from the dividend and accumulating the result.
*
* Edge Case:
* - INT_MIN is -2^31, whose absolute value is 1 more than INT_MAX. So abs(INT_MIN) overflows.
*   → Special-case this when divisor is -1 to avoid overflow (INT_MAX returned).
*
* Sign Handling:
* - We convert both dividend and divisor to negative numbers to avoid overflow
*   (since abs(INT_MIN) is invalid).
* - We track the final sign of the result with a multiplier `m`.
*
* Example:
*   dividend = 10, divisor = 3 → result = 3
*   dividend = 7, divisor = -3 → result = -2
*
*
* Time Complexity: O(log N)
* - The number of doublings is proportional to log(dividend).
* - The second loop also runs at most log(dividend) times.
*
* Space Complexity: O(log N)
* - The vector stores at most log(dividend) elements.
*
**********************************************************************************/
class Solution {
public:
    int divide(int dividend, int divisor) {
        int m = 1;
        int ans = 0;
        vector<int> div;
        if(dividend == INT_MIN){
            if(divisor == 1){
                return INT_MIN;
            }else if(divisor == -1){
                return INT_MAX;
            }
        }
        if(divisor > 0){
            divisor *= -1;
            m *= -1;
        }
        if(dividend > 0){
            dividend *= -1;
            m *= -1;
        }
        int mul = divisor;
        div.push_back(mul);
        while(dividend - mul <= mul){           
            mul = mul + mul;
            div.push_back(mul);
        }
        for(int i = div.size() - 1; i >= 0; i--){
            if(dividend <= div[i]){
                dividend -= div[i];
                ans += (1 << i);
            }
        }
        ans *= m;
        return ans;
    }
};
