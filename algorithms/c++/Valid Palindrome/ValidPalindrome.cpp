/********************************************************************************** 
* 
* 125. Valid Palindrome
*
* A phrase is a palindrome if, after converting all uppercase letters into 
* lowercase letters and removing all non-alphanumeric characters, it reads 
* the same forward and backward. Alphanumeric characters include letters 
* and numbers.
* 
* Approach:
* 
* - First, iterate through the input string and filter out all non-alphanumeric
*   characters using `isalnum()`.
* - During this process, convert all characters to lowercase using `tolower()`
*   and store them in a vector.
* - Then, use a loop to check whether this cleaned-up character sequence is
*   a palindrome by comparing characters from both ends inward.
* - If a mismatch is found, return false. If the loop completes, return true.
* 
* Time complexity: O(n), where n is the length of the input string.
*   - We pass through the string twice: once to clean it, once to check palindrome.
* Space complexity: O(n), because we use a vector to store the cleaned string.
* 
* Example 1:
*     Input: s = "A man, a plan, a canal: Panama"
*     Output: true
*     Explanation:
*       After removing non-alphanumerics and converting to lowercase:
*       "amanaplanacanalpanama" is a palindrome.
* 
* Example 2:
*     Input: s = "race a car"
*     Output: false
*     Explanation:
*       Cleaned version is "raceacar", which is not a palindrome.
* 
* Example 3:
*     Input: s = " "
*     Output: true
*     Explanation:
*       After removing non-alphanumerics, the string becomes empty.
*       An empty string is considered a valid palindrome.
* 
**********************************************************************************/
class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> c;
        for(char i:s){
            if(isalnum(i)){
                i = tolower(i);
                c.push_back(i);
            }
        }
        for(int j = 0; j < c.size(); j++){
            if(c[j] != c[c.size() - j - 1]){
                return false;
            }
        }

        return true;

    }
};
