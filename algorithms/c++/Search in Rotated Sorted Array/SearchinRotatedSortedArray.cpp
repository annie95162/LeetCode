// Source : https://leetcode.com/problems/search-in-rotated-sorted-array/
// Author : Min Fang
// Date   : 2025-08-22

/**********************************************************************************
*
* Problem: Search in Rotated Sorted Array
*
* There is an integer array `nums` sorted in ascending order, but it may be
* **rotated** at some unknown pivot index `k`. For example:
*
*   Original sorted:   [0,1,2,4,5,6,7]
*   After rotation k=3: [4,5,6,7,0,1,2]
*
* You are given the rotated array `nums` and an integer `target`.
* Return the index of `target` if found; otherwise return -1.
*
* The solution must run in **O(log n)** time complexity.
*
*
* Example 1:
*   Input:  nums = [4,5,6,7,0,1,2], target = 0
*   Output: 4
*
* Example 2:
*   Input:  nums = [4,5,6,7,0,1,2], target = 3
*   Output: -1
*
* Example 3:
*   Input:  nums = [1], target = 0
*   Output: -1
*
*
* Constraints:
*   - 1 <= nums.length <= 5000
*   - -10^4 <= nums[i], target <= 10^4
*   - All elements in `nums` are unique.
*   - `nums` is sorted in ascending order, possibly rotated.
*
*
* Approach: Modified Binary Search
*
* - This is a variant of classic binary search where the array is rotated.
* - Key insight: in any rotated sorted array, at least one side (left or right)
*   of the current `mid` is guaranteed to be sorted.
*
* Steps:
* 1. Initialize two pointers: `left = 0`, `right = nums.size() - 1`.
* 2. While `left <= right`, compute `mid = (right - left) / 2 + left`.
* 3. If `nums[mid] == target`, return `mid`.
* 4. Determine which half is sorted:
*    - If `nums[mid] >= nums[left]` → left half is sorted.
*        - Check if `target` is in the sorted range: `nums[left] <= target < nums[mid]`
*        - If yes, move `right = mid - 1`; else, search in right half: `left = mid + 1`
*    - Else → right half is sorted.
*        - Check if `target` is in the sorted range: `nums[mid] < target <= nums[right]`
*        - If yes, move `left = mid + 1`; else, search in left half: `right = mid - 1`
* 5. If not found, return -1.
*
*
* Time Complexity: O(log n)
*   - Because we halve the search space each iteration (modified binary search).
*
* Space Complexity: O(1)
*   - No additional space used.
*
**********************************************************************************/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1;
        int mid = 0;
        int left = 0;
        int right = nums.size()-1;

        while(left <= right){
            mid = (right - left)/2 + left;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] >= nums[left]){
                if(target < nums[mid] && target >= nums[left]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }else{
                if(target > nums[mid] && nums[right] >= target){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }                
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
    int search(vector<int>& nums, int target) {
        int ans = -1;
        int ns = nums.size()-1;
        int mid = 0;
        int left = 0;
        int right = ns;
        if(nums[right] > nums[left]){
            while(left <= right){
                mid = (right - left)/2 + left;
                if(nums[mid] == target){
                    return mid;
                }
                if(nums[mid] > target){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
        }else{
            while(left <= right){
                mid = (right - left)/2 + left;
                if(nums[mid] == target){
                    return mid;
                }
                if(nums[mid] < target && nums[left] <= nums[mid]){
                    left = mid + 1;
                }else if(nums[mid] < target && nums[left] <= target){
                    right = mid - 1;
                }else if(nums[mid] < target && nums[left] >= target){
                    left = mid + 1;
                }

                if(nums[mid] > target && nums[right] >= nums[mid]){
                    right = mid - 1;
                }else if(nums[mid] > target && nums[right] >= target){
                    left = mid + 1;
                }else if(nums[mid] > target && nums[right] <= target){
                    right = mid - 1;

                }
            }
        }        
        return ans;
    }
};
