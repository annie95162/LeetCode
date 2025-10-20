// Source : https://leetcode.com/problems/longest-balanced-substring-i/
// Author : Min Fang
// Date   : 2025-10-20

/**********************************************************************************
*
* Problem: Longest Balanced Substring
*
* You are given a string `s` consisting of lowercase English letters.
*
* A substring of `s` is called "balanced" if all **distinct characters** in the
* substring appear **the same number of times**.
*
* Return the length of the longest balanced substring of `s`.
*
*
* Examples:
*
* Example 1:
*   Input: s = "abbac"
*   Output: 4
*   Explanation:
*     The substring "abba" has 'a' and 'b' both appearing twice → balanced.
*
* Example 2:
*   Input: s = "zzabccy"
*   Output: 4
*   Explanation:
*     The substring "zabc" has 'z', 'a', 'b', and 'c' each appearing once → balanced.
*
* Example 3:
*   Input: s = "aba"
*   Output: 2
*   Explanation:
*     The substrings "ab" and "ba" both have 'a' and 'b' once → balanced.
*
*
* Constraints:
*   - 1 <= s.length <= 1000
*   - s consists of lowercase English letters
*
*
* Approach:
*
* 1. Use two nested loops to enumerate all substrings of `s`:
*    - Outer loop sets the start index `i`
*    - Inner loop expands to end index `j`
*
* 2. Use an `unordered_map<char, int>` to count frequency of characters in the current substring.
*
* 3. Maintain two variables during the inner loop:
*    - `diff`: the number of distinct characters seen so far
*    - `maxcnt`: the maximum frequency among all characters in the current substring
*
* 4. For a substring to be balanced:
*    - All characters must appear the same number of times
*    - Therefore: length of substring == `maxcnt * diff`
*
* 5. If the above condition is satisfied, update the longest balanced length.
*
*
* Time Complexity: O(n^2)
*   - Enumerates all substrings in O(n^2)
*   - Each substring update uses O(1) map access (since only 26 lowercase letters)
*
* Space Complexity: O(1)
*   - Map holds at most 26 entries at any time (a–z)
*
**********************************************************************************/
class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            unordered_map<char, int> map;
            int maxcnt = 0;
            int diff = 0;
            for(int j = i; j < s.size(); j++){
                if(map[s[j]] == 0){
                    diff++;
                }
                map[s[j]]++;
                maxcnt = max(maxcnt, map[s[j]]);
                if((j-i+1) == maxcnt*diff){
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};
