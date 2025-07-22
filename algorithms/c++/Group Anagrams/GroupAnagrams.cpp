// Source : https://leetcode.com/problems/group-anagrams/
// Author : Min Fang
// Date   : 2025-07-22

/**********************************************************************************
*
* Given an array of strings `strs`, the task is to group all anagrams together.
* An anagram is a word or phrase formed by rearranging the letters of another.
* For example: "eat" -> "tea", "tan" -> "nat".
*
* Your solution takes the following approach:
*
* Approach:
*
* - Maintain two parallel vectors:
*     1. `sorted`: stores the sorted version of each string (used as the key).
*     2. `ans`: a vector of groups (each group is a vector of strings), where each group shares the same sorted key.
*
* - For each string in the input:
*     1. Make a copy of the string, sort it alphabetically → this is its "anagram signature".
*     2. Compare it against all existing sorted keys:
*         - If a match is found, it means this word is an anagram of that group → push into corresponding group in `ans`.
*         - If no match is found, start a new group with this word and store its sorted version as a new key.
*
* - Return `ans` which contains all anagram groups.
*
* Time Complexity: O(N * K log K), where
*   - N is the number of strings in `strs`,
*   - K is the maximum length of a single string (because we sort each string).
*
* Space Complexity: O(N*K), for storing results and keys.
*
*
* ✅ Notes:
* - The approach is valid, but uses linear search to match sorted keys (in `sorted`), which makes it slightly less efficient.
* - For optimal performance, a `unordered_map<string, vector<string>>` would avoid the nested loop and improve lookup to O(1).
*
*
* Example:
*
* Input: ["eat", "tea", "tan", "ate", "nat", "bat"]
*
* Process:
*     "eat" -> "aet" → new group → [["eat"]]
*     "tea" -> "aet" → found → [["eat", "tea"]]
*     "tan" -> "ant" → new group → [["eat", "tea"], ["tan"]]
*     "ate" -> "aet" → found → [["eat", "tea", "ate"], ["tan"]]
*     "nat" -> "ant" → found → [["eat", "tea", "ate"], ["tan", "nat"]]
*     "bat" -> "abt" → new group → [["eat", "tea", "ate"], ["tan", "nat"], ["bat"]]
*
* Output:
*     [["eat", "tea", "ate"], ["tan", "nat"], ["bat"]]
*
**********************************************************************************/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string> sorted;
        string temp1;
        string temp2;
        bool in = false;
        //cout << temp1.size() << endl;
        for(int i = 0; i < strs.size(); i++){
            temp1 = strs[i];
            temp2 = strs[i];
            sort(temp2.begin(), temp2.end());
            for(int j = 0; j < sorted.size(); j++){

                //cout << temp1 << temp2 << endl;
                if(temp2 == sorted[j]){
                    ans[j].push_back(temp1);
                    in = true;
                    //cout << "find" << temp1 << "in sorted" << temp2 << endl;
                    continue;
                }
            }
            if(!in){
                ans.push_back(vector<string>{temp1});
                sorted.push_back(temp2);
                //cout << "new" << temp1 << "sorted" << temp2 << endl;
            }
            in = false;
        }
        return ans;

    }
};
