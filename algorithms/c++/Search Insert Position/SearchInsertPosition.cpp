// Source : https://leetcode.com/problems/group-anagrams/
// Author : Min Fang
// Date   : 2025-07-29

/**********************************************************************************
*
* Problem:
* Given a **sorted array** of distinct integers and a **target** value, return the index 
* if the target is found. If not, return the index where it would be **inserted in order**.
*
* You must implement the solution with **O(log n)** runtime complexity.
*
* Example 1:
* Input: nums = [1,3,5,6], target = 5
* Output: 2
*
* Example 2:
* Input: nums = [1,3,5,6], target = 2
* Output: 1
*
* Example 3:
* Input: nums = [1,3,5,6], target = 7
* Output: 4
*
*
* Approach:
* - Use **binary search** since the array is sorted and the required time complexity is O(log n).
* - Maintain two pointers: `left` and `right` to define the current search boundaries.
* - On each iteration:
*     - Compute the middle index `mid = (left + right) / 2`.
*     - If `nums[mid] == target`, return `mid`.
*     - If `nums[mid] < target`, move `left` to `mid + 1`.
*     - If `nums[mid] > target`, move `right` to `mid - 1`.
* - If the loop ends without finding the target, `left` will be the index where the target
*   should be inserted to maintain sorted order.
*
*
* Time Complexity: O(log n)
* - Each iteration cuts the search range in half.
*
* Space Complexity: O(1)
* - Uses only constant extra space for pointers.
*
*
* ✅ Notes:
* - This approach correctly handles all cases, including:
*     - Target smaller than all elements → returns 0.
*     - Target larger than all elements → returns nums.size().
*     - Target in between existing values → returns correct insert position.
*
**********************************************************************************/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        while(left <= right){
            mid = (left+right)/2;
            if(target == nums[mid]){
                return mid;

            }else if(target > nums[mid]){
                left = mid + 1;

            }else{
                right = mid - 1;
            }
        }
        return left;
    }
};
