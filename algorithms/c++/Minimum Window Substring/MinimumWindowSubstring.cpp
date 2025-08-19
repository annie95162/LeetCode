// Source : https://leetcode.com/problems/minimum-window-substring/
// Author : Min Fang
// Date   : 2025-08-19

/**********************************************************************************
*
* Problem: Minimum Window Substring
*
* Given two strings `s` and `t`, return the smallest substring of `s` that contains
* all the characters in `t` (including duplicates). If no such substring exists,
* return the empty string "".
*
* Example 1:
*   Input:  s = "ADOBECODEBANC", t = "ABC"
*   Output: "BANC"
*   Explanation: The substring "BANC" contains all characters of t ("A", "B", "C")
*
* Example 2:
*   Input:  s = "a", t = "a"
*   Output: "a"
*
* Example 3:
*   Input:  s = "a", t = "aa"
*   Output: ""
*   Explanation: Only one "a" exists in s, but two are required.
*
* Constraints:
*   - 1 <= s.length, t.length <= 1e5
*   - s and t consist of uppercase and lowercase English letters.
*
*
* Approach:
*
* - This solution uses a **sliding window** and two frequency arrays (vec1 and vec2).
* - `vec2` stores the frequency of characters in `t`.
* - `vec1` is a dynamic count, used to track characters within the current window in `s`.
* - Use a queue `q` to simulate the current window and store characters.
* - Count how many characters (`cnt`) from `t` are matched with required frequency.
* - When the number of matched characters equals `t.size()`, it means we found a valid window.
* - Try to minimize the window by moving the left pointer and updating the result if smaller.
*
* - The final result is the smallest valid substring formed during this process.
*
*
* Time Complexity: O(m + n)
*   - `m` is the length of `s`, `n` is the length of `t`
*   - Each character is processed at most twice (once added, once removed)
*   - `queue` operations and copying strings could take extra time, but overall linear.
*
* Space Complexity: O(1)
*   - Fixed-size frequency arrays for 58 characters (to cover A-Z and a-z)
*   - Additional space for queue and result string.
*
**********************************************************************************/
class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()){
            return "";
        }
        int cnt = 0;
        bool flag = false;
        int left = 0;
        int minsize = INT_MAX;
        string ans;
        char f;
        queue<char> q;
        queue<char> q2;
        vector<int> vec1(58);
        vector<int> vec2(58);
        for(int i = 0; i < t.size(); i++){
            vec1[t[i] - 'A']++;
            vec2[t[i] - 'A']++;
        }
        for(int i = 0; i < s.size(); i++){
            //cout << "i " << i << endl;
            if(vec2[s[i] - 'A']){
                //cout << s[i] << vec2[s[i] - 'A'] << endl;
                if(!flag){
                    flag = true;
                    left = i;
                }
                if(vec1[s[i] - 'A'] - 1 >= 0){
                    //cout << s[i] << endl;
                    cnt++;
                }
                vec1[s[i] - 'A']--;
            }
            if(flag){
                q.push(s[i]);
            }
            if(cnt == t.size()){
                
                while(left < s.size() && (vec2[s[left] - 'A'] == 0 || vec1[s[left] - 'A']+1 <= 0)){
                    if(vec2[s[left] - 'A']){
                        vec1[s[left] - 'A']++;
                    }
                    left++;
                    q.pop();
                }
                cout << "q" << q.size() << endl;
                if(minsize > q.size()){
                    minsize = q.size();
                    ans = "";
                    q2 = q;
                    //cout << q2.size();
                    while(!q2.empty()){
                        //cout << q2;
                        ans += q2.front();
                        //cout << q2.front();
                        q2.pop();
                    }
                }
                f = q.front();
                q.pop();
                vec1[f - 'A']++;
                cnt--;
                while(left+1 < s.size() && (!vec2[s[left+1] - 'A'] || vec1[s[left+1] - 'A']+1 <= 0)){
                    if(vec2[s[left+1] - 'A']){
                        vec1[s[left+1] - 'A']++;
                    }
                    left++;
                    q.pop();
                }
                left++;

            }
            
        }
        return ans;
    }
};
