// Source : https://leetcode.com/problems/word-pattern/
// Author : Min Fang
// Date   : 2025-07-31

/**********************************************************************************
*
* Problem:
* Given a `pattern` and a string `s`, determine if `s` follows the same pattern.
* That is, check whether there is a **bijection** (one-to-one correspondence) between:
*   - each character in `pattern`
*   - and a non-empty word in `s` (split by spaces)
*
* Bijection means:
*   - Each letter in pattern maps to exactly one unique word
*   - Each word in s maps to exactly one unique letter
*
* Examples:
*   Input:  pattern = "abba", s = "dog cat cat dog"
*   Output: true
*
*   Input:  pattern = "abba", s = "dog cat cat fish"
*   Output: false
*
*   Input:  pattern = "aaaa", s = "dog cat cat dog"
*   Output: false
*
*
* Approach:
* - Step 1: Use `istringstream` to split string `s` by spaces into a vector<string>.
* - Step 2: Check that number of words equals length of pattern; if not, return false.
* - Step 3: Use two hash maps:
*     - `unordered_map<char, string> c2s` : maps pattern character → word
*     - `unordered_map<string, char> s2c` : maps word → pattern character
*   This enforces **two-way mapping**, ensuring bijection.
*
* - Step 4: For each index `i`:
*     - If mapping exists in either map, ensure consistency.
*     - If not, insert the new mapping into both maps.
* - If all checks pass, return true.
*
*
* Time Complexity: O(n)
* - n = number of characters in s
* - One pass to split the string, one pass to check pattern → overall linear time
*
* Space Complexity: O(k)
* - k = number of unique letters/words (at most 300 each)
* - Uses 2 hash maps and a vector for words
*
* Edge Cases Handled:
* - Length mismatch between `pattern` and words in `s`
* - Conflicting mappings (e.g., 'a' → "dog", 'a' later maps to "cat")
* - Duplicate words mapping to different pattern letters
*
**********************************************************************************/
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream str(s);
        vector<string> word;
        string w;
        while(str >> w){
            word.push_back(w);
            cout << w;
        }
        unordered_map<char,string> c2s;
        unordered_map<string,char> s2c;

        if(word.size() != pattern.size()){
            return false;
        }
        for(int i = 0; i < pattern.size(); i++){
            if(c2s.find(pattern[i]) != c2s.end()){
                if(c2s[pattern[i]] != word[i]){
                    return false;
                }
            }else{
                c2s[pattern[i]] = word[i];
            }

            if(s2c.find(word[i]) != s2c.end()){
                if(s2c[word[i]] != pattern[i]){
                    return false;
                }
            }else{
                s2c[word[i]] = pattern[i];
            }
        }
        return true;
    }
};
