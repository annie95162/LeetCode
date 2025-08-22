// Source : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Author : Min Fang
// Date   : 2025-08-22

/**********************************************************************************
*
* Problem: Find First and Last Position of Element in Sorted Array
*
* Given a sorted array of integers `nums` (non-decreasing order) and a target value,
* return the starting and ending position of the given target value.
*
* If the target is not found, return [-1, -1].
*
* The solution must run in O(log n) time.
*
*
* Example 1:
*   Input:  nums = [5,7,7,8,8,10], target = 8
*   Output: [3, 4]
*
* Example 2:
*   Input:  nums = [5,7,7,8,8,10], target = 6
*   Output: [-1, -1]
*
* Example 3:
*   Input:  nums = [], target = 0
*   Output: [-1, -1]
*
*
* Constraints:
*   - 0 <= nums.length <= 10^5
*   - -10^9 <= nums[i], target <= 10^9
*   - `nums` is sorted in non-decreasing order
*
*
* Approach: Binary Search (Twice)
*
* To find both the **first** and **last** positions of the target in O(log n):
*
* 1. **First Occurrence:**
*    - Use binary search to find the **leftmost** index where `nums[mid] == target`.
*    - If found, continue searching to the **left** (i.e., `right = mid - 1`) to check for earlier occurrence.
*
* 2. **Last Occurrence:**
*    - Reset `left` and `right`.
*    - Use binary search to find the **rightmost** index where `nums[mid] == target`.
*    - If found, continue searching to the **right** (i.e., `left = mid + 1`) to check for later occurrence.
*
* 3. Return `[first, last]` — if target not found, both will remain `-1`.
*
*
* Time Complexity: O(log n)
*   - Each binary search runs in log(n), and we run it twice.
*
* Space Complexity: O(1)
*   - Constant extra space is used.
*
**********************************************************************************/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        int first = -1;
        while(left <= right){
            mid = (right - left)/2 + left;

            if(nums[mid] == target){
                first = mid;
                right = mid - 1;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        left = 0;
        right = nums.size()-1;
        mid = 0;
        int last = -1;
        while(left <= right){
            mid = (right - left)/2 + left;

            if(nums[mid] == target){
                last = mid;
                left = mid + 1;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return vector<int>{first, last};
    }
};
