// Source : https://leetcode.com/problems/longest-balanced-substring-ii/
// Author : Min Fang
// Date   : 2025-10-21

/**********************************************************************************
*
* Problem: Longest Balanced Substring
*
* You are given a string `s` consisting only of the characters 'a', 'b', and 'c'.
* A substring of `s` is called *balanced* if all distinct characters in the substring
* appear the same number of times.
*
* Return the length of the longest balanced substring.
*
*
* Example 1:
*   Input:  s = "abbac"
*   Output: 4
*   Explanation:
*     The longest balanced substring is "abba" because both 'a' and 'b' appear twice.
*
* Example 2:
*   Input:  s = "aabcc"
*   Output: 3
*   Explanation:
*     The substring "abc" is balanced since 'a', 'b', and 'c' each appear once.
*
* Example 3:
*   Input:  s = "aba"
*   Output: 2
*   Explanation:
*     The longest balanced substrings are "ab" or "ba", where 'a' and 'b' each appear once.
*
*
* Constraints:
*   - 1 <= s.length <= 1e5
*   - s consists only of characters 'a', 'b', and 'c'
*
*
* Approach: Prefix Difference Hashing
*
* 1. Maintain prefix counts for each character:
*       count_a, count_b, count_c
*
* 2. Observe that a substring is balanced if the relative differences between
*    character counts remain the same at two different positions.
*    Therefore, we can represent the prefix state as:
*       diffAB = count_a - count_b
*       diffAC = count_a - count_c
*
* 3. Use an unordered_map to store the first index where a specific (diffAB, diffAC)
*    pair appears. The same difference pair means the substring between those two
*    indices has equal increments in counts — hence balanced.
*
* 4. For each position:
*       - Update counts based on the current character
*       - Compute (diffAB, diffAC)
*       - If this pair has been seen before, update max_len = max(max_len, i - seen[key])
*       - Otherwise, store its first occurrence
*
* 5. The answer is the longest distance between two equal (diffAB, diffAC) pairs.
*
*
* Example Walkthrough:
*   s = "abbac"
*     i | s[i]  | count_a  | count_b  | count_c  | diffAB  | diffAC  | max_len
*    ---+-------+----------+----------+----------+---------+---------+---------
*     0 |  a    |    1     |    0     |    0     |   +1    |   +1    |   0
*     1 |  b    |    1     |    1     |    0     |    0    |   +1    |   0
*     2 |  b    |    1     |    2     |    0     |   -1    |   +1    |   0
*     3 |  a    |    2     |    2     |    0     |    0    |   +2    |   4  ← "abba"
*     4 |  c    |    2     |    2     |    1     |    0    |   +1    |   4
*
*
* Time Complexity: O(n)
*   - One pass through the string, each step uses O(1) map lookup/update
*
* Space Complexity: O(n)
*   - For storing up to O(n) distinct (diffAB, diffAC) states
*
**********************************************************************************/
class Solution {
public:
    struct pair_hash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<long long>()(((long long)p.first << 32) | (unsigned int)p.second);
        }
    };
    int longestBalanced(string s) {
        unordered_map<pair<int, int>, int, pair_hash> seen;
        seen[{0, 0}] = -1;

        int count_a = 0, count_b = 0, count_c = 0;
        int max_len = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'a') count_a++;
            else if (s[i] == 'b') count_b++;
            else count_c++;

            int diffAB = count_a - count_b;
            int diffAC = count_a - count_c;
            
            auto key = make_pair(diffAB, diffAC);
            
            if (seen.count(key)) {
                max_len = max(max_len, i - seen[key]);
            } else {
                seen[key] = i;
            }
        }
        return max_len;

    }
};
