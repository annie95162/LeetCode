// Source : https://leetcode.com/problems/next-greater-element-i/
// Author : Min Fang
// Date   : 2025-08-07

/**********************************************************************************
*
* Problem:
* --------
* Given two integer arrays `nums1` and `nums2`, where `nums1` is a subset of `nums2`,
* return an array of the next greater elements for each element in `nums1`.
*
* The next greater element for an element `x` in `nums2` is the first greater number
* to the right of `x` in the same array. If there is no greater element, return -1.
*
*
* Examples:
* ---------
* Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
* Output: [-1,3,-1]
*
* Input: nums1 = [2,4], nums2 = [1,2,3,4]
* Output: [3,-1]
*
*
* Constraints:
* ------------
* - 1 <= nums1.length <= nums2.length <= 1000
* - 0 <= nums1[i], nums2[i] <= 10^4
* - All elements in `nums1` and `nums2` are unique.
* - All elements of `nums1` are guaranteed to appear in `nums2`.
*
*
* Approach:
* ---------
* - For each element in `nums1`, search for it in `nums2`.
* - Once found, scan to the right to find the first greater element.
* - If found, record it; otherwise, record -1.
*
* Step-by-step Logic:
* -------------------
* - Loop through each element in `nums1`:
*     1. Set `flag = false` and `temp = -1`.
*     2. Loop through `nums2`:
*         - If `nums2[j]` equals `nums1[i]`, set `flag = true`.
*         - If `flag` is true and `nums2[j] > nums1[i]`, set `temp = nums2[j]` and break.
*     3. Push `temp` into the result array.
*
*
* Time Complexity: O(n * m)
* -------------------------
* - Where `n = nums1.size()` and `m = nums2.size()`.
* - For each element in `nums1`, we may scan through up to `nums2.size()` elements.
*
* Space Complexity: O(n)
* ----------------------
* - Only the output vector `ans` is used to store the result.
*
*
* ✅ Notes:
* --------
* - This solution works correctly but is not optimal.
* - A more efficient O(n + m) solution exists using a monotonic stack
*   and a hash map to preprocess `nums2` for quick lookups.
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
