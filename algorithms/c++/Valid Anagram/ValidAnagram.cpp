// Source : https://leetcode.com/problems/valid-anagram/
// Author : Min Fang
// Date   : 2025-07-22

/********************************************************************************** 
*
* Problem:
* Given two strings s and t, return true if t is an anagram of s, and false otherwise.
* 
* An Anagram means both strings contain the same characters with the same frequency,
* but possibly in different orders.
* 
* Approach:
* 
* - Sort both strings.
* - If after sorting, the strings are identical, then t is an anagram of s.
* - Otherwise, it is not.
* 
* Time complexity: O(n log n), where n is the length of the strings (sorting).
* Space complexity: O(1) or O(n) depending on the sorting implementation.
* 
* Follow-up (Unicode):
* - Sorting still works for Unicode strings but may be less efficient.
* - Alternatively, use a hash map (unordered_map) to count frequencies of each character.
* - This allows handling all Unicode characters without relying on ASCII.
* 
* Example 1:
*     Input: s = "anagram", t = "nagaram"
*     Output: true
* 
* Example 2:
*     Input: s = "rat", t = "car"
*     Output: false
* 
**********************************************************************************/
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s == t){
            return true;
        }
        return false;
    }
};
