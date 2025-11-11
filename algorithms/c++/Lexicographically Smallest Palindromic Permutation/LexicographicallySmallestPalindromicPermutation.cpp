// Source : https://leetcode.com/problems/lexicographically-smallest-palindromic-permutation-greater-than-target/
// Author : Min Fang
// Date   : 2025-11-04

/**********************************************************************************
*
* Problem: Lexicographically Smallest Palindromic Permutation Greater Than Target
*
* You are given:
*   - Two strings of equal length `s` and `target`, both consisting of lowercase
*     English letters.
*
* Goal:
*   Return the **lexicographically smallest string** that satisfies both:
*     1. It is a **palindromic permutation** of `s`.
*     2. It is **strictly greater** than `target`.
*
*   If no such palindrome exists, return an empty string "".
*
*
* Example 1:
*   Input:  s = "baba", target = "abba"
*   Output: "baab"
*   Explanation:
*     The palindromic permutations of "baba" are ["abba", "baab"].
*     The smallest palindrome strictly greater than "abba" is "baab".
*
* Example 2:
*   Input:  s = "baba", target = "bbaa"
*   Output: ""
*   Explanation:
*     Palindromic permutations are ["abba", "baab"], and none is > "bbaa".
*     Therefore, return "".
*
* Example 3:
*   Input:  s = "abc", target = "abb"
*   Output: ""
*   Explanation:
*     "abc" has no palindromic permutation → return "".
*
* Example 4:
*   Input:  s = "aac", target = "abb"
*   Output: "aca"
*   Explanation:
*     Only palindrome possible is "aca", which is greater than "abb".
*
*
* Constraints:
*   - 1 <= n == s.length == target.length <= 300
*   - s and target consist only of lowercase English letters.
*
*
* -----------------------------------------------------------------------------
* Approach: Character Frequency + Incremental Construction Toward Next Palindrome
* -----------------------------------------------------------------------------
*
* 1. **Count frequencies** of all characters in `s`.
*    - A palindrome can be formed if at most **one character** has an odd frequency.
*    - If more than one character count is odd → impossible, return "".
*
*
* 2. **Identify the middle (odd) character:**
*    - If there is one odd character, store it as `oddc`.
*    - Reduce its count by 1 to make all character counts even.
*
*
* 3. **Construct the palindrome from the center outward:**
*    - We need to find the **smallest palindrome** that is still greater than `target`.
*    - We simulate filling the **first half** of the palindrome (and mirror it).
*    - At each position, we compare characters with the corresponding position in `target`:
*         - If possible, place the same character and continue.
*         - If not possible (due to exhausted frequency or lexicographic constraint),
*           we try to place the **next greater available character** and fill
*           the remaining positions with the smallest possible letters.
*
*
* 4. **Handle edge cases:**
*    - If `s` has length 1, directly compare `s[0] > target[0]`.
*    - If no lexicographically larger palindrome can be formed, return "".
*
*
* 5. **Reconstruct the final palindrome:**
*    - Combine the first half, optional middle character, and the reversed half.
*    - This ensures palindrome symmetry.
*
*
* -----------------------------------------------------------------------------
* Key Mathematical/Algorithmic Notes:
*
*   Palindrome feasibility condition:
*     Σ (count[c] % 2) ≤ 1
*
*   Half-building approach:
*     - Only half of each even-count character is placed explicitly;
*       the other half is implied by mirroring.
*
*   Lexicographic check:
*     - If the constructed palindrome prefix matches the target’s prefix,
*       continue comparing.
*     - Once a prefix becomes lexicographically larger, the rest of the string
*       can be filled with the smallest available characters.
*
*
* -----------------------------------------------------------------------------
* Time Complexity:
*   - O(26 + n) = O(n), since we only iterate through the string and the alphabet.
*   - In the worst case, backtracking during construction adds a small constant factor.
*
* Space Complexity:
*   - O(26) for frequency array + O(n) for palindrome construction = O(n).
*
*
* -----------------------------------------------------------------------------
* Summary:
*   Checks palindrome feasibility via frequency counting.
*   Uses controlled prefix expansion to find the next lexicographically valid palindrome.
*   Builds the result by mirroring the left half and inserting the middle (if any).
*   Returns "" if no valid larger palindrome permutation exists.
*
**********************************************************************************/
class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        if(s.size() == 1 && s[0] > target[0]){
            return s;
        }
        int arr[26] = {0};
        for(int i = 0; i < s.size(); i++){
            arr[s[i] - 'a'] ++;
        }
        int odd = 0;
        char oddc = '\0';
        for(int i = 0; i < 26; i++){
            if(arr[i] % 2){
                odd++;
                arr[i]--;
                oddc = i + 'a';
            }
        }
        if(odd > 1){
            return "";
        }
        stack<int> st;
        bool equal = true;
        bool larger = false;
        bool larthanoth = false;
        int i = target.size()/2;
        int cnt = 0;
        while(equal){
            if(arr[target[cnt]-'a']){
                if(i==1){
                    if(oddc > target[target.size()/2]){
                        arr[target[cnt] - 'a'] -= 2;
                        st.push(target[cnt] - 'a');
                        i--;
                        cnt++;
                        larger = true;
                    }else if(oddc == '\0' || oddc == target[target.size()/2]){
                        arr[target[cnt] - 'a'] -= 2;
                        st.push(target[cnt] - 'a');
                        i--;
                        cnt++;
                        stack<int> st2 = st;
                        int ts = (target.size()+1)/2;
                        while(ts < target.size()){
                            if((st2.top()+'a') > target[ts]){
                                larger = true;
                                break;
                            }else if((st2.top()+'a') < target[ts]){
                                int temp = st.top();
                                arr[temp] += 2;
                                st.pop();
                                i++;
                                cnt--;
                                break;
                            }else{
                                st2.pop();
                                ts++;
                                if(ts == target.size()){
                                    int temp = st.top();
                                    arr[temp] += 2;
                                    st.pop();
                                    i++;
                                    cnt--;
                                    break;
                                }
                            }
                        }
                        
                    }
                    equal = false;
                    break;
                }else{
                    arr[target[cnt] - 'a'] -= 2;
                    st.push(target[cnt] - 'a');
                    i--;
                    cnt++;
                }
            }else{
                equal = false;
                break;
            }
        }
        while(!larger && !equal){
            for(int j = target[cnt] - 'a' + 1; j < 26; j++){
                if(arr[j]){
                    st.push(j);
                    arr[j] -= 2;
                    cnt++;
                    i--;
                    larger = true;
                    break;
                }
            }
            if(!larger){
                if(cnt == 0){
                    return "";
                }
                int t = st.top();
                st.pop();
                arr[t] += 2;
                i++;
                cnt--;
            }
        }
        if(larger && i){
            for(int j = 0; j < 26; j++){
                while(arr[j]){
                    st.push(j);
                    arr[j] -= 2;
                    i--;
                    cnt++;
                }
            }
        }
        string ansb;
        while(!st.empty()){
            ansb += char(st.top() + 'a');
            st.pop();
        }
        string ans = ansb;
        reverse(ans.begin(), ans.end());
        if(oddc != '\0'){
            ans += oddc;
        }
        ans += ansb;
        return ans;
    }
};
