// Source : https://leetcode.com/problems/remove-zeros-in-decimal-representation/
// Author : Min Fang
// Date   : 2025-10-30

/**********************************************************************************
*
* Problem: Remove All Zeros From a Number
*
* You are given a positive integer `n`.
* Your task is to return a new integer formed by *removing all zeros*
* from the decimal representation of `n`.
*
*
* Example 1:
*   Input:  n = 1020030
*   Output: 123
*   Explanation:
*     Removing all zeros → "1020030" → "123" → integer value = 123
*
* Example 2:
*   Input:  n = 1
*   Output: 1
*   Explanation:
*     The number 1 contains no zeros, so it remains unchanged.
*
*
* Constraints:
*   - 1 <= n <= 10^15
*
*
* Approach: Digit Extraction and Reconstruction
*
* 1. Initialize an empty container (vector) to store non-zero digits.
*
* 2. Extract digits from `n` starting from the least significant digit (rightmost side):
*      - If the digit is non-zero, push it into the vector.
*      - Divide `n` by 10 each step to move to the next digit.
*
* 3. After the loop, reconstruct the new number in the correct order:
*      - Iterate through the stored digits in reverse (since digits were collected backward).
*      - For each digit, multiply the current result by 10 and add the digit.
*
* 4. Return the reconstructed number.
*
*
* Example Walkthrough:
*   n = 1020030
*   Step 1 → Extract non-zero digits: [1, 2, 3] (after reversing)
*   Step 2 → Build number: 0*10+1=1 → 1*10+2=12 → 12*10+3=123
*   Output = 123
*
*
* Time Complexity: O(log₁₀(n))
*   - Each digit of `n` is processed once.
*
* Space Complexity: O(log₁₀(n))
*   - To store non-zero digits temporarily before reconstruction.
*
**********************************************************************************/
class Solution {
public:
    long long removeZeros(long long n) {
        long long ans = 0;
        vector<int> temp;
        while(n > 0){
            if(n%10){
                temp.push_back(n%10);
            }
            n /= 10;
        }
        for(int i = temp.size()-1; i >= 0; i--){
            ans *= 10;
            ans += temp[i];
        }
        return ans;
    }
};
