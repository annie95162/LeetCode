// Source : https://leetcode.com/problems/guess-number-higher-or-lower/
// Author : Min Fang
// Date   : 2025-09-02

/**********************************************************************************
*
* Problem: Guess Number Higher or Lower
*
* You are playing a game where you need to guess a number I picked from 1 to n.
* Every time you guess wrong, you'll be told whether the picked number is higher
* or lower than your guess.
*
* You are given a predefined API:
*    int guess(int num);
*      - returns -1 if num is higher than the picked number
*      - returns  1 if num is lower than the picked number
*      - returns  0 if num is the picked number
*
* Implement the function:
*    int guessNumber(int n);
* which returns the number that I picked.
*
*
* Example 1:
*   Input: n = 10, pick = 6
*   Output: 6
*
* Example 2:
*   Input: n = 1, pick = 1
*   Output: 1
*
* Example 3:
*   Input: n = 2, pick = 1
*   Output: 1
*
*
* Constraints:
*   - 1 <= n <= 2^31 - 1
*   - 1 <= pick <= n
*
*
* Approach: Binary Search
*
* Since the number is between 1 and n, and we can receive feedback (higher/lower),
* we can efficiently search for the correct number using binary search.
*
* The idea of binary search:
* - We maintain a search range [left, right], starting with left = 1, right = n.
* - In each iteration:
*     - Compute mid = left + (right - left) / 2
*     - Call guess(mid)
*       - If result is 0: we've found the correct number → return mid
*       - If result is 1: the picked number is higher → search right half (left = mid + 1)
*       - If result is -1: the picked number is lower → search left half (right = mid - 1)
* - Loop continues until left == right, at which point left is the picked number.
*
* Why we use mid = left + (right - left) / 2 instead of (left + right) / 2:
* - To prevent potential integer overflow when left and right are large.
*
*
* Time Complexity: O(log n)
* - Each guess reduces the search space by half.
*
* Space Complexity: O(1)
* - No additional space is used beyond a few integer variables.
*
**********************************************************************************/
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        int mid = 0;
        while(left < right){
            mid = (right - left)/2 + left;
            if(guess(mid) == 0){
                return mid;
            }else if(guess(mid) == 1){
                left = mid + 1;
            }else if(guess(mid) == -1){
                right = mid - 1;
            }
        }
        return left;
    }
};
