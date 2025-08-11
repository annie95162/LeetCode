// Source : https://leetcode.com/problems/next-greater-element-i/
// Author : Min Fang
// Date   : 2025-08-07

/**********************************************************************************
*
* Problem:
*   You are given two 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
*   The next greater element of an element x in nums2 is the first greater element to the right of x.
*
*   For each element in nums1, find its corresponding "next greater element" in nums2.
*   If no such element exists, return -1 for that entry.
*
* Example 1:
*   Input:
*     nums1 = [4,1,2], nums2 = [1,3,4,2]
*   Output:
*     [-1,3,-1]
*   Explanation:
*     - The next greater element for 4 is -1.
*     - The next greater element for 1 is 3.
*     - The next greater element for 2 is -1.
*
* Example 2:
*   Input:
*     nums1 = [2,4], nums2 = [1,2,3,4]
*   Output:
*     [3,-1]
*   Explanation:
*     - The next greater element for 2 is 3.
*     - The next greater element for 4 is -1.
*
*
* Constraints:
* - 1 <= nums1.length <= nums2.length <= 1000
* - 0 <= nums1[i], nums2[i] <= 10^4
* - All integers in nums1 and nums2 are unique.
* - All elements in nums1 also appear in nums2.
*
*
* Approach:
*
* - This problem can be solved efficiently using a **Monotonic Stack** and a **Hash Map**.
*
* - Step 1: Traverse nums2 from right to left, using a stack to keep track of the next greater element.
*   - Maintain a decreasing stack (top is always greater).
*   - For each element:
*     - Pop all elements smaller than or equal to current element.
*     - If the stack is empty, there's no greater element → map it to -1.
*     - If the stack is not empty, top is the next greater element → map it.
*     - Push the current element into the stack.
*
* - Step 2: After the map is built, iterate nums1 and use the map to build the answer.
*
*
* Time Complexity: O(n + m)
*   - n = nums2.size(), m = nums1.size()
*   - Build map: O(n), Lookup: O(m)
*
* Space Complexity: O(n)
*   - Stack and Hash Map store up to n elements
*
*
* ✅ Notes:
* - This approach satisfies the "Follow up" requirement of O(n + m) complexity.
* - Using a monotonic stack is optimal for such "next greater" problems.
*
**********************************************************************************/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> map;
        stack<int> st;
        for(int i = nums2.size()-1; i >= 0; i--){
            while(!st.empty() && st.top() < nums2[i]){
                st.pop();
            }
            if(st.empty()){
                map[nums2[i]] = -1;
            }else{
                map[nums2[i]] = st.top();
            } 
            st.push(nums2[i]);
            
        }

        for(int i = 0; i < nums1.size(); i++){
            ans.push_back(map[nums1[i]]);
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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++){
            int temp = -1;
            bool flag = false;
            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    flag = true;
                }
                if(flag && nums2[j] > nums1[i]){
                    temp = nums2[j];
                    break;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
