// Source : https://leetcode.com/problems/valid-parentheses/
// Author : Min Fang
// Date   : 2025-08-06

/**********************************************************************************
 *
 * Problem:
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid.
 *
 * A string is valid if:
 * - Open brackets are closed by the same type of brackets.
 * - Open brackets are closed in the correct order.
 * - Every closing bracket has a corresponding open bracket of the same type.
 *
 *
 * Constraints:
 * - 1 <= s.length <= 10^4
 * - s consists of parentheses only: '()[]{}'
 *
 *
 * Approach (Stack-Based Matching):
 * --------------------------------
 * Use a stack to keep track of open brackets. For each character in the string:
 *
 * - If it's an opening bracket ('(', '[', '{'), push it onto the stack.
 * - If it's a closing bracket (')', ']', '}'):
 *     - If the stack is empty, return false (no matching open bracket).
 *     - Check whether the top of the stack is the matching open bracket:
 *         - If it matches, pop the top element and continue.
 *         - If it doesn't match, return false.
 *
 * - At the end of the traversal, the stack should be empty if all brackets were matched.
 *
 *
 * Function Breakdown:
 * -------------------
 * isValid(string s):
 *   - Returns false immediately if the string length is odd (can't be matched).
 *   - Uses a stack<char> to store open brackets.
 *   - Iterates through each character in the string:
 *       - Pushes open brackets onto the stack.
 *       - For close brackets, checks for correct matching top of stack.
 *   - Returns true only if the stack is empty after processing.
 *
 *
 * Time Complexity:
 * ----------------
 * - O(n), where n is the length of the input string. Each character is processed once.
 *
 * Space Complexity:
 * - O(n), in the worst case (all opening brackets), due to the stack.
 *
 *
 * Summary:
 * - Simple and efficient stack-based solution for validating parentheses.
 * - Ensures matching bracket type and correct order.
 * - Handles edge cases such as empty stack or unmatched closing brackets.
 *
 **********************************************************************************/
class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2){
            return false;
        }
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }else{
                if(st.empty()){
                    return false;
                }

                if(s[i] == ')'){
                    if(st.top() == '('){
                        st.pop();
                    }else{
                        return false;
                    }

                }else if(s[i] == ']'){
                    if(st.top() == '['){
                        st.pop();
                    }else{
                        return false;
                    }
                    
                }else if(s[i] == '}'){
                    if(st.top() == '{'){
                        st.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        return(st.empty());
    }
};
