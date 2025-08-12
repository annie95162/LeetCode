// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// Author : Min Fang
// Date   : 2025-08-12

/********************************************************************************** 
*
* Problem: Longest Substring Without Repeating Characters
*
* Given a string s, find the length of the longest substring without duplicate characters.
*
* Example 1:
*   Input:  s = "abcabcbb"
*   Output: 3
*   Explanation: The longest substring without repeating characters is "abc", length 3.
*
* Example 2:
*   Input:  s = "bbbbb"
*   Output: 1
*   Explanation: The longest substring is "b", length 1.
*
* Example 3:
*   Input:  s = "pwwkew"
*   Output: 3
*   Explanation: The longest substring is "wke", length 3.
*
*
* Constraints:
*   - 0 <= s.length <= 5 * 10^4
*   - s consists of English letters, digits, symbols and spaces.
*
*
* Approach:
*
* - Use a sliding window with two pointers (i for left, right for right) and an unordered_set to
*   track the unique characters currently in the window.
* - Move the right pointer forward and add characters to the set while they are unique.
* - If a duplicate character is found (s[right] in set), move the left pointer forward and remove
*   characters from the set until the duplicate is removed.
* - Update the maximum length (ans) whenever the window is expanded.
*
* Optimization Notes:
* - This method uses a sliding window to achieve linear time complexity.
* - unordered_set allows O(1) average time complexity for insertions and lookups.
*
*
* Time Complexity: O(n)
*   - Each character is visited at most twice (once when added, once when removed).
*
* Space Complexity: O(k)
*   - k is the size of the character set in the current substring (at most all unique characters).
*
**********************************************************************************/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> set;
        int ans = 0;
        int right = 0;
        int i = 0;
        cout << s.size();
        while(right < s.size()){
            if(set.find(s[right]) == set.end()){
                set.insert(s[right]);
                right++;
                ans = max(ans, int(set.size()));
            }else{
                set.erase(s[i]);
                i++;
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
    int lengthOfLongestSubstring(string s) {
        deque<int> q;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(!q.empty() && find(q.begin(),q.end(),s[i]) != q.end()){
                while(find(q.begin(),q.end(),s[i]) != q.end()){
                    q.pop_front();
                }
            }
            q.push_back(s[i]);
            ans = max(ans, int(q.size()));
        }
        return ans;
    }
};
