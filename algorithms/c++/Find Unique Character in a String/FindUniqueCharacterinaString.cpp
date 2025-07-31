// Source : https://leetcode.com/problems/first-unique-character-in-a-string/description/
// Author : Min Fang
// Date   : 2025-07-31

/**********************************************************************************
*
* Problem:
* Given a string `s`, find the first non-repeating character in it and return its index.
* If no such character exists, return -1.
*
* Examples:
*   Input: s = "leetcode"
*   Output: 0
*   Explanation: The character 'l' at index 0 is the first character that does not repeat.
*
*   Input: s = "loveleetcode"
*   Output: 2
*   Explanation: The character 'v' at index 2 is the first unique character.
*
*   Input: s = "aabb"
*   Output: -1
*   Explanation: No unique character exists.
*
* Constraints:
* - 1 <= s.length <= 10^5
* - s consists only of lowercase English letters.
*
* Approach:
* - Use an unordered_map<char, int> to count the frequency of each character.
* - Traverse the string a second time and check each character's count.
* - Return the index of the first character with count == 1.
* - If no such character exists, return -1.
*
* Intuition:
* Counting frequencies first allows O(1) frequency lookup for each character.
* Then a single pass through the string finds the first unique character efficiently.
*
* Time Complexity: O(n)
* - Two passes through the string, each O(n).
*
* Space Complexity: O(1)
* - The map stores counts for lowercase English letters only, constant size (at most 26).
*
* Edge Cases Handled:
* - String with all repeating characters returns -1.
* - String where the first character is unique returns index 0.
* - Single character string always returns 0.
*
**********************************************************************************/
class Solution {
public:
    int firstUniqChar(string s) {
        int ans = -1;
        unordered_map<char,int> map;
        for(int i = 0; i < s.size(); i++){
            map[s[i]]++;
        }
        for(int j = 0; j < s.size(); j++){
            if(map[s[j]] == 1){
                ans = j;
                break;
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
    int firstUniqChar(string s) {
        int ans = -1;
        unordered_map<char,vector<int>> map;
        for(int i = 0; i < s.size(); i++){
            map[s[i]].emplace_back(i);
        }
        for(int j = 0; j < s.size(); j++){
            if(map[s[j]].size() == 1){
                ans = map[s[j]][0];
                break;
            }
        }
        return ans;
    }
};
