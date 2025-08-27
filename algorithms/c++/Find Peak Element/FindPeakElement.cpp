// Source : https://leetcode.com/problems/find-peak-element/
// Author : Min Fang
// Date   : 2025-08-27

/**********************************************************************************
*
* Problem: Find Peak Element
*
* A **peak element** is an element that is strictly greater than its neighbors.
*
* You are given a 0-indexed integer array `nums`. Your task is to find any one
* peak element and return its **index**.
*
* You can assume that:
* - `nums[-1] = nums[n] = -∞`, i.e., elements outside the array are considered 
*   as negative infinity, which means the edge elements can also be peaks.
* - The input guarantees that no two adjacent elements are equal.
*
* Your solution must run in **O(log n)** time.
*
* ------------------------------------------------------------------------------
* Example 1:
*   Input:  nums = [1,2,3,1]
*   Output: 2
*   Explanation: 3 is a peak element at index 2.
*
* Example 2:
*   Input:  nums = [1,2,1,3,5,6,4]
*   Output: 5
*   Explanation: 6 is a peak element at index 5.
*
* ------------------------------------------------------------------------------
* Constraints:
*   - 1 <= nums.length <= 1000
*   - -2^31 <= nums[i] <= 2^31 - 1
*   - nums[i] != nums[i + 1] for all valid i
*
*
* Approach: Modified Binary Search
*
* Key Insight:
* - You don’t need to find the **maximum** element, just any **peak**.
* - If `nums[mid] > nums[mid + 1]`, the peak must be on the **left side** (including mid)
* - If `nums[mid] < nums[mid + 1]`, the peak must be on the **right side**
* - This is based on the fact that a "slope" up or down will always lead to a peak
*
* Algorithm Steps:
* 1. Initialize `left = 0`, `right = nums.size() - 1`
* 2. While `left < right`:
*    - Compute `mid = (left + right) / 2`
*    - Compare `nums[mid]` with `nums[mid + 1]`
*      - If `nums[mid] > nums[mid + 1]`, then move `right = mid`
*      - Else move `left = mid + 1`
* 3. Return `left` (or `right`), since at loop end `left == right` and it's a peak
*
*
* Time Complexity: O(log n)
*   - The search space is halved each iteration
*
* Space Complexity: O(1)
*   - Only constant extra space is used
*
**********************************************************************************/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //左邊大於右邊救回傳左邊index
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while(left < right){
            mid = (right - left) / 2 + left;
            if(nums[mid] > nums[mid + 1]){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};
