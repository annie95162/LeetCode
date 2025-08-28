// Source : https://leetcode.com/problems/find-smallest-letter-greater-than-target/
// Author : Min Fang
// Date   : 2025-08-28

/**********************************************************************************
*
* Problem: Find Smallest Letter Greater Than Target
*
* You are given a **sorted array of lowercase letters** and a target letter.
* The goal is to return the **smallest character in the array that is strictly
* greater than the target**.
*
* The array is **circular** in behavior. If no such character exists (i.e., all
* characters in the array are <= target), you should return the **first character**.
*
* ------------------------------------------------------------------------------
* Example 1:
*   Input:  letters = ['c', 'f', 'j'], target = 'a'
*   Output: 'c'
*   Explanation: 'c' is the smallest character > 'a'
*
* Example 2:
*   Input:  letters = ['c', 'f', 'j'], target = 'c'
*   Output: 'f'
*
* Example 3:
*   Input:  letters = ['x', 'x', 'y', 'y'], target = 'z'
*   Output: 'x'
*   Explanation: No character is greater than 'z'; wrap around and return first
*
* ------------------------------------------------------------------------------
* Constraints:
*   - 2 <= letters.length <= 10^4
*   - letters[i] is a lowercase English letter
*   - letters is sorted in non-decreasing order
*   - letters contains at least two different characters
*
*
* Approach: Binary Search
*
* Key Insight:
* - Since the array is sorted, we can perform binary search to find the first
*   character greater than the target.
* - If `letters[mid] <= target`, we discard the left half: move `left = mid + 1`
* - If `letters[mid] > target`, we record `letters[mid]` as a potential answer
*   and continue searching to the left: move `right = mid - 1`
* - If no such character is found in the binary search, we return letters[0]
*   (wrap-around behavior)
*
* Algorithm Steps:
* 1. Initialize `left = 0`, `right = letters.size() - 1`
* 2. Default answer = letters[0] (in case we don't find a greater character)
* 3. While `left <= right`, calculate `mid`
*    - If `letters[mid] <= target`, search right half
*    - Else, update `ans = letters[mid]`, and search left half
* 4. Return `ans`
*
*
* Time Complexity: O(log n)
*   - Binary search reduces search space by half each time
*
* Space Complexity: O(1)
*   - Only constant extra space is used
*
**********************************************************************************/
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;
        int mid = -1;
        char ans = letters[0];
        while(left <= right){
            mid = (right - left)/2 + left;
            if(letters[mid] <= target){
                left = mid + 1;
            }else{
                right = mid - 1;
                ans = letters[mid];
            }
        }
        return ans;
    }
};
