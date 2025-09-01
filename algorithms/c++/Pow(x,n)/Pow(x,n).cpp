// Source : https://leetcode.com/problems/powx-n/
// Author : Min Fang
// Date   : 2025-09-01

/**********************************************************************************
*
* Problem: Pow(x, n)
*
* Implement the function `myPow(x, n)` which calculates x raised to the power n
* (i.e., xⁿ), without using built-in exponent functions such as `pow` or `exp`.
*
* Example 1:
*   Input:  x = 2.00000, n = 10
*   Output: 1024.00000
*
* Example 2:
*   Input:  x = 2.10000, n = 3
*   Output: 9.26100
*
* Example 3:
*   Input:  x = 2.00000, n = -2
*   Output: 0.25000
*
* Constraints:
*   - -100.0 < x < 100.0
*   - -2^31 <= n <= 2^31 - 1
*   - n is an integer
*   - Either x != 0 or n > 0
*   - -10^4 <= xⁿ <= 10^4
*
*
* Approach: Fast Exponentiation (Binary Exponentiation)
*
* The goal is to compute xⁿ efficiently in O(log n) time. We use the method of
* binary exponentiation, which decomposes the exponent into powers of 2.
*
* Every integer `n` can be represented in binary. For example:
*   n = 77 → binary = 1001101
*   => x^77 = x^(64 + 8 + 4 + 1) = x^64 * x^8 * x^4 * x^1
*
* That means:
* - Starting from x, we repeatedly square it to compute x^1, x^2, x^4, x^8, ...
* - For every bit that is set to 1 in the binary representation of n, we include
*   the corresponding power in the result.
*
* Special Handling:
* - Since n can be negative (e.g., INT_MIN = -2^31), we first convert n to a
*   `long long` to avoid overflow when negating it.
* - If n is negative, we compute the reciprocal of x and work with -n.
*
* Algorithm Steps:
* 1. Convert n to long long to safely handle INT_MIN.
* 2. If n < 0, replace x with 1/x and n with -n.
* 3. Initialize result = 1.
* 4. While n > 0:
*      - If the current bit is 1 (i.e., n % 2 == 1), multiply result by x.
*      - Square x.
*      - Divide n by 2.
* 5. Return the result.
*
* Time Complexity: O(log n)
* Space Complexity: O(1)
*
**********************************************************************************/
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        double ans = 1;
        double temp = x;
        if(N < 0){
            temp = 1 / temp;
            N = N * -1;
        }
        while(N > 0){
            if(N % 2){
                ans *= temp;
                cout << ans;
            }
            temp *= temp;
            N = N/2;
        }
        return ans;
    }

};

/**********************************************************************************
*
* Solution 2
*
**********************************************************************************/
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        if(n == 0 || x == 1){
            return ans;
        }
        if(n == INT_MIN){
            if( x == 1 || x == -1){
                return 1;
            }else{
                return 0;                
            }
        }
        if(n == INT_MAX){
            if(x == 1){
                return 1;
            }else if(x == -1){
                return -1;
            }
        }
        while(n > 0){
            ans = ans * x;
            n--;
        }
        n = n * (-1);
        while(n > 0){
            ans = ans / x;
            n--;
        }
        return ans;
    }
};
