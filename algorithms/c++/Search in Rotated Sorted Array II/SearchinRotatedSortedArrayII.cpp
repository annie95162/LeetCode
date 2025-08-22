// Source : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Author : Min Fang
// Date   : 2025-08-22
/**********************************************************************************
*
* Problem: Search in Rotated Sorted Array II
*
* Given an integer array `nums` that is **sorted in non-decreasing order** and then
* **rotated at an unknown pivot**, and an integer `target`, return `true` if target
* exists in the array, otherwise return `false`.
*
* The array **may contain duplicates**, which makes the problem more complex.
*
*
* Example 1:
*   Input:  nums = [2,5,6,0,0,1,2], target = 0
*   Output: true
*
* Example 2:
*   Input:  nums = [2,5,6,0,0,1,2], target = 3
*   Output: false
*
*
* Constraints:
*   - 1 <= nums.length <= 5000
*   - -10^4 <= nums[i], target <= 10^4
*
*
* Approach: Modified Binary Search
*
* - Initialize `left` and `right` pointers at the start and end of the array.
* - Perform binary search with additional handling for duplicates.
* - At each step:
*     1. Compute the middle index.
*     2. If `nums[mid]` equals `target`, return true.
*     3. If `nums[mid] > nums[left]`, then the **left half is sorted**:
*         - If `target` is within the range `[nums[left], nums[mid])`, move `right` to `mid - 1`.
*         - Otherwise, move `left` to `mid + 1`.
*     4. Else if `nums[mid] < nums[right]`, then the **right half is sorted**:
*         - If `target` is within the range `(nums[mid], nums[right]]`, move `left` to `mid + 1`.
*         - Otherwise, move `right` to `mid - 1`.
*     5. If `nums[mid] == nums[left]` or `nums[mid] == nums[right]`:
*         - It's ambiguous due to duplicates. Linearly scan to find the first index
*           with a value different from `nums[mid]`, and adjust `left` or `right` accordingly.
*         - If all values in the range are equal to `nums[mid]`, return false.
*
* Time Complexity: O(log n) on average, but can degrade to O(n) due to duplicates.
*
* Space Complexity: O(1) - Only uses pointers and constant extra space.
*
**********************************************************************************/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        bool flag;
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        while(left <= right){
            mid = (right - left)/2 + left;
            if(nums[mid] == target){
                return true;
            }
            if(nums[mid] > nums[left]){
                if(nums[mid] > target && nums[left] <= target){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }else if(nums[mid] < nums[right]){
                if(nums[mid] < target && nums[right] >= target){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }else if(nums[mid] == nums[left] || nums[mid] == nums[right]){
                flag = false;
                cout << flag << left << right;
                for(int i = left; i <= right; i++){
                    if(nums[i] != nums[mid]){
                        if(i < mid){
                            right = mid - 1;
                            flag = true;
                            break;
                        }else{
                            left = mid + 1;
                            flag = true;
                            break;
                        }                        
                    }
                }
                if(!flag){
                    return false;
                }
            }
    
        }
        return false;
    }
};
