// Source : https://leetcode.com/problems/merge-sorted-array/
// Author : Min Fang
// Date   : 2025-07-16

/********************************************************************************** 
* 
* Given an integer array nums, move all 0's to the end of it while maintaining 
* the relative order of the non-zero elements.
* 
* Approach:
* 
* - We use a two-pointer technique to solve this problem in-place.
* - The pointer `zero` keeps track of the next position where a non-zero 
*   element should be placed.
* - The pointer `left` is used to traverse the entire array.
* - Every time a non-zero element is encountered, we swap it with the element 
*   at the `zero` position, then move the `zero` pointer forward.
* - This ensures that all non-zero elements are moved to the front, while 
*   zeros are pushed to the end of the array.
* 
* Time complexity: O(n), where n is the length of the array. 
*   We only need to go through the array once.
* Space complexity: O(1), because we are modifying the array in-place and using 
*   only a few extra variables.
* 
* Example 1:
*     Input: nums = [0, 1, 0, 3, 12]
*     Output: [1, 3, 12, 0, 0]
*     Explanation:
*       We move all 0's to the end while maintaining the relative order of 
*       non-zero elements.
* 
* Example 2:
*     Input: nums = [0]
*     Output: [0]
*     Explanation:
*       Since there's only one 0, it remains in place.
* 
**********************************************************************************/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = 0; //第一個0
        int left = 0; //非0
        int temp;
        for(left; left < nums.size(); left++){
            if(nums[left] != 0){
                temp = nums[left];
                nums[left] = nums[zero];
                nums[zero] = temp;
                zero++;
            }
        }

    }
};
