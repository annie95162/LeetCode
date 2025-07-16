// Source : https://leetcode.com/problems/two-sum/
// Author : Min Fang
// Date   : 2025-07-16

/********************************************************************************** 
* 
* Given an integer array `nums` and an integer `val`, the task is to remove all 
* occurrences of `val` in-place. The order of elements may be changed.
* 
* After removal, the first `k` elements of `nums` should contain the elements 
* not equal to `val`, and the function should return `k`.
* 
* Approach:
* 
* - We use two pointers: `left` and `right`.
* - The `right` pointer iterates through the array from start to end.
* - Every time we encounter an element that is not equal to `val`, we assign it to 
*   the `left` position in the array and increment `left`.
* - This effectively overwrites elements equal to `val` and maintains the required 
*   elements in the front of the array.
* - After the loop ends, `left` holds the count of elements not equal to `val`.
* 
* Time complexity: O(n) - We iterate through the entire array once.
* Space complexity: O(1) - We perform the operation in-place using constant extra space.
* 
* Example 1:
*     Input: nums = [3,2,2,3], val = 3
*     Output: 2, nums = [2,2,_,_]
*     Explanation:
*       The first two elements of nums after removal are 2 and 2.
*       The underscores (_) represent values that are not important.
* 
* Example 2:
*     Input: nums = [0,1,2,2,3,0,4,2], val = 2
*     Output: 5, nums = [0,1,4,0,3,_,_,_]
*     Explanation:
*       The first five elements of nums after removal are 0, 1, 4, 0, 3 in any order.
* 
**********************************************************************************/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = 0;
        for(right; right < nums.size(); right++){
            if(nums[right] != val){
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
};
