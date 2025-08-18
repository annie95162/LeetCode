// Source : https://leetcode.com/problems/permutation-in-string/
// Author : Min Fang
// Date   : 2025-08-18

/********************************************************************************** 
*
* Problem: Permutation in String
*
* Given two strings s1 and s2, return true if s2 contains a permutation of s1,
* or false otherwise.
*
* In other words, return true if one of s1's permutations is the substring of s2.
*
* Example 1:
*   Input:  s1 = "ab", s2 = "eidbaooo"
*   Output: true
*   Explanation: s2 contains one permutation of s1 ("ba").
*
* Example 2:
*   Input:  s1 = "ab", s2 = "eidboaoo"
*   Output: false
*   Explanation: s2 does not contain any permutation of s1.
*
*
* Constraints:
*   - 1 <= s1.length, s2.length <= 10^4
*   - s1 and s2 consist of lowercase English letters.
*
*
* Approach:
*
* - Use a sliding window to traverse s2 while maintaining a count of characters
*   needed to match s1 using a frequency array `vec` of size 26.
*
* - First, populate the frequency array with s1's character counts.
*
* - Then, iterate over s2:
*   - For each character added to the window (i.e., s2[i]), decrease its count in `vec`.
*   - If the count goes below zero, it means we have more of that character than needed.
*     In this case, shrink the window from the left until the count becomes valid again.
*
* - Whenever the current window size equals s1's length, and no extra characters exist,
*   it means a valid permutation of s1 exists in s2 — return true.
*
* - If no such window is found after traversing s2, return false.
*
*
* Key Insight:
* - The idea is that if we subtract the characters from s1 and then add characters
*   from s2 while keeping the counts valid, once the window matches the length of s1
*   and all character counts are satisfied, we have a match.
*
* Time Complexity: O(n)
*   - n is the length of s2.
*   - Each character is processed at most twice (once when added to the window,
*     once when removed during shrinkage).
*
* Space Complexity: O(1)
*   - Fixed-size frequency array of 26 lowercase letters.
*
**********************************************************************************/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        vector<int> vec(26);
        for(int i = 0; i < s1.size(); i++){
            vec[s1[i] - 'a']++;
        }
        int left = 0;
        for(int i = 0; i < s2.size(); i++){
            vec[s2[i] - 'a']--;
            while(vec[s2[i] - 'a'] < 0){
                vec[s2[left] - 'a']++;
                left++;
            }
            if(i - left + 1 == s1.size()){
                return true;
            }
        }
        return false;
    }
};
