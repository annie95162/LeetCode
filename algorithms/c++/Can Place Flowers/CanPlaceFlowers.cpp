// Source : https://leetcode.com/problems/can-place-flowers/
// Author : Min Fang
// Date   : 2025-08-21

/**********************************************************************************
*
* Problem: Can Place Flowers
*
* You have a flowerbed represented as a binary array, where:
*   - 0 indicates an empty plot
*   - 1 indicates a planted plot
*
* Flowers cannot be planted in **adjacent** plots.
* 
* Given the flowerbed and an integer `n`, return `true` if `n` new flowers can be
* planted in it without violating the rule, otherwise return `false`.
*
*
* Example 1:
*   Input:  flowerbed = [1,0,0,0,1], n = 1
*   Output: true
*
* Example 2:
*   Input:  flowerbed = [1,0,0,0,1], n = 2
*   Output: false
*
*
* Constraints:
*   - 1 <= flowerbed.length <= 2 * 10^4
*   - flowerbed[i] is either 0 or 1
*   - No two adjacent flowerbed[i]s are 1 initially
*   - 0 <= n <= flowerbed.length
*
*
* Approach: Greedy Iteration
*
* - Traverse the flowerbed array.
* - For each index `i`, check if the current plot is 0 and both its adjacent plots
*   (i-1 and i+1) are also 0 or out of bounds.
*     - If so, we can plant a flower at index `i`, mark it as 1, and decrement `n`.
* - Special handling is done for:
*     - The first element: check if flowerbed[0] and flowerbed[1] are 0
*     - The last element: check if flowerbed[n-2] and flowerbed[n-1] are 0
*     - Single-element flowerbeds
* - Return true if `n` reaches 0 during traversal, meaning all flowers are planted.
* - Otherwise, return false after the loop.
*
*
* Time Complexity: O(n)
*   - We scan the flowerbed once.
*
* Space Complexity: O(1)
*   - No extra space is used (in-place updates).
*
**********************************************************************************/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size() == 1 && flowerbed[0] == 0 || !n){
            return true;
        }
        if(flowerbed.size() > 1 && n){
            if(flowerbed[0] == 0 && flowerbed[1] == 0){
                flowerbed[0] = 1;
                n--;
            }            
        }
        for(int i = 1; i < flowerbed.size()-1; i++){
            if(n == 0){
                return true;
            }

            if(flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                flowerbed[i] = 1;
                n--;
            }
        }
        if(flowerbed.size() > 1 && n){
            if(flowerbed[flowerbed.size() - 2] == 0 && flowerbed[flowerbed.size() - 1] == 0){
                flowerbed[flowerbed.size() - 1] = 1;
                n--;
            }
        }
        if(n == 0){
            return true;
        }else{
            return false;
        }
    }
};
