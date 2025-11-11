// Source : https://leetcode.com/problems/lexicographically-smallest-palindromic-permutation-greater-than-target/
// Author : Min Fang
// Date   : 2025-11-04

/**********************************************************************************
*
* Problem: Lexicographically Smallest Palindromic Permutation Greater Than Target
*
* You are given two strings `s` and `target`, both of the same length `n`,
* consisting only of lowercase English letters.
*
* You must find:
*   - The lexicographically smallest string that is:
*       1. A **palindromic permutation** of `s`
*       2. **Strictly greater than** `target`
*
* If no such string exists, return an empty string.
*
*
* Example 1:
*   Input:  s = "baba", target = "abba"
*   Output: "baab"
*   Explanation:
*     Palindromic permutations of "baba": ["abba", "baab"]
*     "baab" is the smallest palindrome greater than "abba".
*
*
* Example 2:
*   Input:  s = "baba", target = "bbaa"
*   Output: ""
*   Explanation:
*     Palindromic permutations of "baba": ["abba", "baab"]
*     None of them are greater than "bbaa" → return "".
*
*
* Example 3:
*   Input:  s = "abc", target = "abb"
*   Output: ""
*   Explanation:
*     "abc" has no valid palindromic permutation → return "".
*
*
* Example 4:
*   Input:  s = "aac", target = "abb"
*   Output: "aca"
*   Explanation:
*     Only palindrome possible: "aca", and "aca" > "abb".
*
*
* Constraints:
*   - 1 <= n <= 300
*   - s.length == target.length == n
*   - s and target consist of lowercase English letters.
*
*
* -----------------------------------------------------------------------------
* Approach: Palindromic Construction + Lexicographic Comparison
* -----------------------------------------------------------------------------
*
* Step 1: **Check for palindromic feasibility**
*   - Count frequency of each character in `s`.
*   - For a palindrome to exist:
*       - If `n` is even → all characters must have even counts.
*       - If `n` is odd → only one character may have an odd count.
*   - If more than one character has an odd frequency → return "".
*
*
* Step 2: **Form the smallest possible palindrome**
*   - Construct the **left half** of the palindrome using half of each character count.
*   - If there is one odd-count character, keep it as the **center**.
*   - Mirror the left half to form the full palindrome.
*   - This yields the lexicographically smallest palindromic permutation of `s`.
*
*
* Step 3: **Find the next lexicographically greater palindrome**
*   - Treat the left half of the palindrome as a separate sequence.
*   - Use `next_permutation()` on the left half to find the next possible arrangement.
*   - For each permutation:
*       - Form the full palindrome (left + center + reversed(left)).
*       - Check if it is strictly greater than `target`.
*       - Return the first one that satisfies this condition.
*   - If no greater palindrome can be formed → return "".
*
*
* Step 4: **Lexicographic comparison**
*   - Comparison is performed on full palindrome vs. `target`.
*   - Once a valid palindrome greater than `target` is found, it’s guaranteed
*     to be the smallest since we iterate in lexicographic order.
*
* -----------------------------------------------------------------------------
* Time Complexity:
*   - O(n log n) for sorting + next_permutation operations
*   - Efficient since n ≤ 300
*
* Space Complexity:
*   - O(n) for temporary palindrome construction
*
* -----------------------------------------------------------------------------
* Mathematical Summary:
*   - Palindrome valid if:
*       count_odd ≤ 1
*   - Left half construction:
*       left = concat(char(i) * (freq[i] / 2))
*   - Full palindrome:
*       palindrome = left + middle + reverse(left)
*   - Search for smallest palindrome s.t.
*       palindrome > target
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
