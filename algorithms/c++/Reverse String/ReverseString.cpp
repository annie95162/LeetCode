// Source : https://leetcode.com/problems/reverse-string/
// Author : Min Fang
// Date   : 2025-07-22

/********************************************************************************** 
*
* Problem:
* Write a function that reverses a string. The input string is given as an array
* of characters s.
*
* You must do this by modifying the input array in-place with O(1) extra memory.
* 
* Approach:
* 
* - Use two pointers: one starting at the beginning (i), one at the end (len - i - 1).
* - Swap the characters at these pointers.
* - Move the pointers towards the center until they meet or cross.
* - This reverses the array in place without using extra space.
* 
* Time complexity: O(n), where n is the length of the input vector.
*   - Each character is swapped at most once.
* Space complexity: O(1), only a temporary variable is used for swapping.
* 
* Example 1:
*     Input: s = ['h', 'e', 'l', 'l', 'o']
*     Output: ['o', 'l', 'l', 'e', 'h']
* 
* Example 2:
*     Input: s = ['H', 'a', 'n', 'n', 'a', 'h']
*     Output: ['h', 'a', 'n', 'n', 'a', 'H']
* 
**********************************************************************************/
class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        char temp = ' ';
        for(int i = 0; i < len/2; i++){
            temp = s[i];
            s[i] = s[len - i - 1];
            s[len - i - 1] = temp;
        }
    }
};
