// Source : https://leetcode.com/problems/sqrtx/
// Author : Min Fang
// Date   : 2025-09-01

/**********************************************************************************
*
* Problem: Sqrt(x)
*
* Given a non-negative integer x, return the square root of x **rounded down**
* to the nearest integer. The returned integer must also be non-negative.
*
* You must **not** use any built-in exponent functions (like pow or sqrt).
*
* Example 1:
*   Input:  x = 4
*   Output: 2
*   Explanation: The square root of 4 is 2, so return 2.
*
* Example 2:
*   Input:  x = 8
*   Output: 2
*   Explanation: The square root of 8 is about 2.82842..., so rounding down is 2.
*
* Constraints:
*   - 0 <= x <= 2^31 - 1
*
*
* Approach: Binary Search
*
* Key Insight:
* - We are trying to find the largest integer `ans` such that `ans^2 <= x`.
* - Since the square of integers grows fast, we can apply binary search
*   between 0 and x (or a smaller bound) to find this `ans`.
*
* Algorithm:
* 1. Handle base case: if x is 0 or 1, return x directly.
* 2. Initialize search range:
*      - left = 0
*      - right = min(x, INT_MAX - 1) + 1 (safe upper bound)
* 3. While `left <= right`:
*      - mid = left + (right - left) / 2
*      - If `mid * mid <= x`, store `ans = mid` and move `left = mid + 1`
*      - Else, move `right = mid - 1`
* 4. When loop ends, return `ans` — it will be the floor of sqrt(x)
*
* Why use `long long` for mid and mid*mid?
* - To avoid integer overflow when squaring large values of mid (e.g., mid = 46341)
*
*
* Time Complexity: O(log x)
*   - Each iteration cuts the search space in half
*
* Space Complexity: O(1)
*   - No extra space used, constant memory
*
**********************************************************************************/
class Solution {
public:
    int mySqrt(int x) {
        long long int i = 0;
        int left = 0;
        int right = min(x, INT_MAX-1) + 1;
        long long mid = 0;
        int ans = 0;

        while(left <= right){
            mid = (right - left)/2 + left;
            if(mid * mid <= x){
                ans = mid;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
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
