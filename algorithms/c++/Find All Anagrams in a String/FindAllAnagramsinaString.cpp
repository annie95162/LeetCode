// Source : https://leetcode.com/problems/find-all-anagrams-in-a-string/
// Author : Min Fang
// Date   : 2025-08-18

/********************************************************************************** 
*
* Problem: Find All Anagrams in a String
*
* Given two strings s and p, return an array of all the start indices of p's anagrams in s.
* You may return the answer in any order.
*
* Example 1:
*   Input: s = "cbaebabacd", p = "abc"
*   Output: [0,6]
*   Explanation:
*       The substring with start index = 0 is "cba", which is an anagram of "abc".
*       The substring with start index = 6 is "bac", which is an anagram of "abc".
*
* Example 2:
*   Input: s = "abab", p = "ab"
*   Output: [0,1,2]
*   Explanation:
*       The substring with start index = 0 is "ab", which is an anagram of "ab".
*       The substring with start index = 1 is "ba", which is an anagram of "ab".
*       The substring with start index = 2 is "ab", which is an anagram of "ab".
*
* Constraints:
*   - 1 <= s.length, p.length <= 3 * 10^4
*   - s and p consist of lowercase English letters.
*
* Approach:
*
* - Use two frequency vectors of length 26 to store counts of characters:
*     vec1 for string p,
*     vec2 for the current sliding window in string s.
* - Use a sliding window of size at most p.size() on s.
* - Traverse s, increment the count of the current character in vec2.
* - Maintain the sliding window size with a counter `cnt`.
* - When window size exceeds p.size(), decrement the count of the leftmost character and shrink window from left.
* - Each time the frequency vectors vec1 and vec2 match, it means the current window is an anagram of p.
*   Record the start index (i - p.size() + 1).
*
* Optimization Notes:
*
* - Using fixed-size frequency arrays makes frequency comparison efficient (O(26) = O(1)).
* - Sliding window ensures each character is processed at most twice.
*
* Time Complexity: O(n)
*   - n = length of s.
*   - Each character is added once and removed once from the sliding window.
*
* Space Complexity: O(1)
*   - Frequency vectors are fixed size 26.
*
**********************************************************************************/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> vec1(26);
        vector<int> vec2(26);
        vector<int> ans;
        int cnt = 0;
        for(int i = 0; i < p.size(); i++){
            vec1[p[i] - 'a']++;
        }

        for(int i = 0; i < s.size(); i++){
            vec2[s[i] - 'a']++;
            cnt++;
            if(cnt > p.size()){
                cout << i << cnt << p.size();
                vec2[s[i - p.size()] - 'a']--;
                cnt--;
            }
            if(vec1 == vec2){
                ans.push_back(i - p.size() + 1);
            }
        }
        return ans;

    }
};

/********************************************************************************** 
*
* Solution 2
*
**********************************************************************************/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> vec1(26);
        vector<int> vec2(26);
        vector<int> ans;
        for(int i = 0; i < p.size(); i++){
            vec1[p[i] - 'a']++;
            vec2[p[i] - 'a']++;
        }
        int left = 0;
        for(int i = 0; i < s.size(); i++){            
            vec1[s[i] - 'a']--;
            while(vec1[s[i] - 'a'] < 0){
                vec1[s[left] - 'a']++;
                left++;
            }
            if(i - left + 1 == p.size()){
                ans.push_back(left);
                while (i + 1 < s.size() && s[i + 1] == s[left]) {
                    left++;
                    i++;
                    ans.push_back(left);
                }
                vec1 = vec2;
                i = left;
                left++;              
            }
        }
        return ans;

    }
};
