// Source : https://leetcode.com/problems/binary-search/
// Author : Min Fang
// Date   : 2025-08-21

/**********************************************************************************
*
* Problem: Binary Search
*
* Given a sorted array of integers `nums` in ascending order and an integer `target`,
* return the index of `target` if it exists in `nums`. Otherwise, return -1.
*
* The algorithm must run in O(log n) time complexity.
*
*
* Example 1:
*   Input:  nums = [-1,0,3,5,9,12], target = 9
*   Output: 4
*   Explanation: 9 exists in nums at index 4.
*
* Example 2:
*   Input:  nums = [-1,0,3,5,9,12], target = 2
*   Output: -1
*   Explanation: 2 does not exist in nums, so return -1.
*
*
* Constraints:
*   - 1 <= nums.length <= 10^4
*   - -10^4 < nums[i], target < 10^4
*   - All integers in nums are unique.
*   - nums is sorted in ascending order.
*
*
* Approach: Binary Search (Iterative)
*
* - Initialize two pointers: `left` at 0 and `right` at nums.size() - 1.
* - While `left` is less than or equal to `right`:
*     - Compute `mid = (left + right) / 2`.
*     - If `nums[mid]` equals the `target`, return `mid`.
*     - If `nums[mid]` is greater than `target`, search the left half by setting `right = mid - 1`.
*     - Else, search the right half by setting `left = mid + 1`.
* - If the loop finishes without finding `target`, return -1.
*
*
* Time Complexity: O(log n)
*   - Each iteration halves the search space.
*
* Space Complexity: O(1)
*   - Uses constant extra space.
*
**********************************************************************************/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;

        while(left <= right){
            mid = (left + right)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return -1;
    }
};

/**********************************************************************************
*
* Solution 2
*
**********************************************************************************/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        if(nums[right] == target){
            return right;
        }

        while(true){
            mid = (left + right)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] > target){
                if(mid == right){
                    return -1;
                }
                right = mid;
            }else{
                if(mid == left){
                    return -1;
                }
                left = mid;
            }
        }
        return -1;
    }
};
