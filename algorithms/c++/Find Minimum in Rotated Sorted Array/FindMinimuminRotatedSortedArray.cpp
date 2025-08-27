// Source : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Author : Min Fang
// Date   : 2025-08-27

/**********************************************************************************
*
* Problem: Find Minimum in Rotated Sorted Array
*
* You are given an integer array `nums` that is sorted in ascending order, 
* but then rotated at some unknown pivot between 1 and n times.
*
* For example:
*   Original sorted:    [0,1,2,4,5,6,7]
*   After rotation k=4: [4,5,6,7,0,1,2]
*
* You need to find the **minimum element** in the array.
* 
* The array contains **unique** elements.
* 
* The solution must run in **O(log n)** time complexity.
*
*
* Example 1:
*   Input:  nums = [3,4,5,1,2]
*   Output: 1
*
* Example 2:
*   Input:  nums = [4,5,6,7,0,1,2]
*   Output: 0
*
* Example 3:
*   Input:  nums = [11,13,15,17]
*   Output: 11
*
*
* Constraints:
*   - 1 <= nums.length <= 5000
*   - -5000 <= nums[i] <= 5000
*   - All elements are unique.
*   - nums is sorted and rotated between 1 and n times.
*
*
* Approach: Modified Binary Search
*
* - Since the array was originally sorted and only rotated, the smallest element
*   is the "pivot point" where the rotation occurred.
*
* - Observation:
*   - In a sorted rotated array, the minimum element is the only element such that
*     the element before it is greater than it (or it's the first element if array
*     is not rotated).
*   - If the middle element is less than the rightmost element, it means the minimum
*     must be in the **left half** (including mid).
*   - If the middle element is greater than the rightmost element, then the minimum
*     is in the **right half** (excluding mid).
*
*
* Steps:
* 1. Initialize two pointers: `left = 0`, `right = nums.size() - 1`
* 2. While `left < right`:
*    - Compute `mid = (right - left) / 2 + left`
*    - If `nums[mid] < nums[right]`, the minimum is in the **left half**, move `right = mid`
*    - Else, the minimum is in the **right half**, move `left = mid + 1`
* 3. When the loop ends, `left` points to the minimum element
* 4. Return `nums[left]`
*
*
* Time Complexity: O(log n)
*   - Binary search halves the search space each iteration.
*
* Space Complexity: O(1)
*   - Constant space, no additional data structures used.
*
**********************************************************************************/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while(right > left){
            mid = (right - left) / 2 + left;
            if(nums[mid] < nums[right]){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return nums[left];
    }
};

/**********************************************************************************
*
* Solution 2
*
**********************************************************************************/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int ns = nums.size();
        int right = ns - 1;
        int mid = 0;
        if(ns == 1){
            return nums[0];
        }
        while(right >= left){
            mid = (right - left)/2 + left;
            if(mid != 0){
                if(nums[mid] > nums[mid-1]){
                    right = mid - 1;
                }else if(nums[mid] < nums[mid-1]){
                    return nums[mid];
                }
            }else{
                if(nums[0] < nums[ns-1]){
                    return nums[0];
                }else{
                    ns--;
                    while(true){
                        if(nums[ns] < nums[ns-1]){
                            return nums[ns];
                        }
                        ns--;
                    }
                }
                
            }
        }
        return nums[0];
    }
};
