// Source : https://leetcode.com/problems/sort-characters-by-frequency/
// Author : Min Fang
// Date   : 2025-08-05

/**********************************************************************************
 *
 * Problem:
 * Given a string `s`, sort it in decreasing order based on the frequency
 * of characters. Return any valid result where characters with higher
 * frequency come before those with lower frequency, and identical characters
 * are grouped together.
 *
 * Examples:
 *   Input: "tree"     → Output: "eert" or "eetr"
 *   Input: "cccaaa"   → Output: "aaaccc" or "cccaaa"
 *   Input: "Aabb"     → Output: "bbAa" or "bbaA"
 *
 *
 * Approach (Hash Map + Bucket Sort):
 * ----------------------------------
 * 1. Count frequency of each character using an unordered_map.
 * 2. Track the maximum frequency encountered.
 * 3. Use a bucket array where each index `i` holds a string consisting
 *    of all characters that appear exactly `i` times.
 * 4. Traverse the buckets in reverse (from high frequency to low),
 *    and construct the result string by repeating each character `i` times.
 *
 * Code:
 * -----------------------------------------------------------------
 * class Solution {
 * public:
 *     string frequencySort(string s) {
 *         unordered_map<char, int> map;
 *         string ans;
 *         int maxf = 0;
 *         for (int i = 0; i < s.size(); i++) {
 *             map[s[i]]++;
 *             maxf = max(maxf, map[s[i]]);
 *         }
 *
 *         vector<string> buc(maxf + 1);
 *         for (auto [ch, num] : map) {
 *             buc[num].push_back(ch);
 *         }
 *
 *         for (int j = maxf; j > 0; j--) {
 *             for (int k = 0; k < buc[j].size(); k++) {
 *                 for (int l = 0; l < j; l++) {
 *                     ans.push_back(buc[j][k]);
 *                 }
 *             }
 *         }
 *         return ans;
 *     }
 * };
 *
 * Properties:
 * - Time Complexity: O(n + k), where n is the length of the string,
 *   and k is the number of distinct characters (at most 62).
 *   - O(n) for counting frequencies.
 *   - O(k) for building buckets.
 *   - O(n) for reconstructing the output.
 *
 * - Space Complexity: O(n + k)
 *   - O(k) for frequency map and buckets.
 *   - O(n) for the output string.
 *
 * Notes:
 * - Bucket sort provides an efficient alternative to sorting a list of pairs,
 *   avoiding O(k log k) overhead.
 * - Valid characters include digits, uppercase and lowercase English letters.
 *
 **********************************************************************************/
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> map;
        string ans;
        int maxf = 0;
        for(int i = 0; i < s.size(); i++){
            map[s[i]]++;
            if(map[s[i]] > maxf){
                maxf = map[s[i]];
            }
        }
        
        vector<string> buc (maxf + 1) ;
        for(auto [ch, num] : map){
            buc[num].push_back(ch);
        }
        for(int j = maxf; j > 0; j--){
            for(int k = 0; k < buc[j].size(); k++){
                for(int l = 0; l < j; l++){
                    ans.push_back(buc[j][k]);
                }
            }
        }
        return ans;

    }
};
