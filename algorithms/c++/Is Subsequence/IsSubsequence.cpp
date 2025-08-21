// Source : https://leetcode.com/problems/is-subsequence/
// Author : Min Fang
// Date   : 2025-08-21

/**********************************************************************************
*
* Problem: Is Subsequence
*
* Given two strings `s` and `t`, return `true` if `s` is a **subsequence** of `t`,
* and `false` otherwise.
*
* A subsequence of a string is a new string formed by deleting some (can be none)
* of the characters from the original string without changing the order of the
* remaining characters.
*
*
* Example 1:
*   Input:  s = "abc", t = "ahbgdc"
*   Output: true
*
* Example 2:
*   Input:  s = "axc", t = "ahbgdc"
*   Output: false
*
*
* Constraints:
*   - 0 <= s.length <= 100
*   - 0 <= t.length <= 10^4
*   - s and t consist only of lowercase English letters
*
*
* Follow-up:
*   - Suppose we have a lot of strings s1, s2, ..., sk to check against the same `t`
*     where k >= 10^9. How would you optimize your solution?
*
*
* Approach: Two Pointers (Greedy Matching)
*
* - Use two pointers: one to iterate over `t`, and another (`ans`) to track progress in `s`.
* - For each character in `t`, if it matches the current character in `s`, advance the pointer in `s`.
* - If all characters in `s` are matched before finishing `t`, return true.
* - Return false otherwise.
*
* Edge Cases:
*   - If `s` == `t`, it's trivially true.
*   - If `s` is longer than `t`, it cannot be a subsequence.
*
*
* Time Complexity: O(t.length)
*   - We iterate through `t` once, and at most through `s` once.
*
* Space Complexity: O(1)
*   - Only a few integer variables are used.
*
*
* Follow-up Optimization:
*   - If there are many queries for different `s` strings and the same `t`, pre-process `t`:
*     1. Build a hash map of character → list of indices in `t`.
*     2. For each `s`, use binary search to find valid increasing indices in `t`.
*     3. This reduces per-query time to O(m log n), where m = s.length and n = t.length.
*
**********************************************************************************/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ans = 0;
        int ss = s.size();
        int ts = t.size();
        if(s == t){
            return true;
        }
        if(ss > ts){
            return false;
        }
        for(int i = 0; i < ts; i++){
            if(s[ans] == t[i]){
                ans++;
            }
            if(ans == ss){
                return true;
            }
        }
        return false;
    }
};
