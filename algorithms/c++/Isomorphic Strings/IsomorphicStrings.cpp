// Source : https://leetcode.com/problems/isomorphic-strings/
// Author : Min Fang
// Date   : 2025-08-05
/**********************************************************************************
 *
 * Problem:
 * Given two strings `s` and `t`, determine if they are isomorphic.
 *
 * Two strings are isomorphic if characters in `s` can be replaced to form `t`,
 * with the following rules:
 *   - Each character in `s` must map to a single character in `t`.
 *   - No two characters in `s` may map to the same character in `t`.
 *   - Character mapping must preserve order and be consistent across positions.
 *
 * Examples:
 *   Input: s = "egg",   t = "add"   → Output: true
 *   Input: s = "foo",   t = "bar"   → Output: false
 *   Input: s = "paper", t = "title" → Output: true
 *
 *
 * Approach (Double Hash Map):
 * ----------------------------
 * 1. Use two hash maps to maintain the one-to-one mapping:
 *    - `StoT`: maps each character from `s` to its counterpart in `t`
 *    - `TtoS`: maps each character from `t` back to `s` (to ensure no two `s`
 *      characters map to the same `t` character)
 * 2. Traverse each character pair (s[i], t[i]):
 *    - If a mapping already exists in either direction, ensure it is consistent.
 *    - If no mapping exists, store the new pair in both maps.
 * 3. If any inconsistency is found, return false.
 * 4. If all pairs are valid and consistent, return true.
 *
 * Properties:
 * - Time Complexity: O(n), where n is the length of the strings.
 *   - Each character is processed once.
 * - Space Complexity: O(k), where k is the number of distinct characters (max 128 for ASCII).
 *
 * Notes:
 * - Using two maps guarantees a bijective (one-to-one and onto) mapping.
 * - If only one map is used (e.g., s → t), cases like s = "ab", t = "cc" will return true incorrectly.
 *
 **********************************************************************************/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> StoT;
        unordered_map<char, char> TtoS;
        for(int i = 0; i < s.size(); i++){
            if(StoT.find(s[i]) != StoT.end()){
                if(StoT[s[i]] != t[i]){
                    return false;
                }
            }else{
                StoT[s[i]] = t[i];
            }

            if(TtoS.find(t[i])!= TtoS.end()){
                if(TtoS[t[i]] != s[i]){
                    return false;
                }
            }else{
                TtoS[t[i]] = s[i];
            }
        }
        return true;
    }
};
