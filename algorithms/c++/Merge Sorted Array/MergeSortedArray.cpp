// Source : https://leetcode.com/problems/merge-sorted-array/
// Author : Min Fang
// Date   : 2025-07-15

/********************************************************************************** 
* 
* You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
* and two integers m and n, representing the number of elements in nums1 and nums2 
* respectively.
* 
* The task is to merge nums1 and nums2 into a single array sorted in non-decreasing 
* order. The merged result should be stored in the array nums1.
* 
* Approach:
* 
* - We use a two-pointer approach to merge the two sorted arrays.
* - We create a temporary vector `ans` to hold the merged result.
* - We iterate through both arrays using two pointers `a` and `b`, where `a` points 
*   to the current element in `nums1` and `b` points to the current element in `nums2`.
* - We compare the elements from `nums1` and `nums2`, and insert the smaller one into 
*   the `ans` vector.
* - Once we finish iterating through either `nums1` or `nums2`, we append the remaining 
*   elements from the other array to `ans`.
* - Finally, we replace the content of `nums1` with the merged result stored in `ans`.
* 
* Time complexity: O(m + n) - We process each element from `nums1` and `nums2` once.
* Space complexity: O(m + n) - We use a temporary vector `ans` to store the merged result.
* 
* Example 1:
*     Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
*     Output: [1,2,2,3,5,6]
*     Explanation:
*       Merging [1,2,3] and [2,5,6], the result is [1,2,2,3,5,6].
* 
* Example 2:
*     Input: nums1 = [1], m = 1, nums2 = [], n = 0
*     Output: [1]
*     Explanation:
*       Merging [1] and [], the result is [1].
* 
* Example 3:
*     Input: nums1 = [0], m = 0, nums2 = [1], n = 1
*     Output: [1]
*     Explanation:
*       Merging [] and [1], the result is [1].
* 
**********************************************************************************/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int s = m + n;
        int a = 0, b = 0;
        for(int i = 0; i < s; i++){
            if(a == m){
                ans.push_back(nums2[b]);
                b++;
            }else if(b == n){
                ans.push_back(nums1[a]);
                a++;
            }else if(nums1[a] <= nums2[b]){
                ans.push_back(nums1[a]);
                a++;
            }else{
                ans.push_back(nums2[b]);
                b++;
            }
        }
        nums1 = ans;
    }
};
