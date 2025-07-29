// Source : https://leetcode.com/problems/group-anagrams/
// Author : Min Fang
// Date   : 2025-07-29

/**********************************************************************************
*
* Problem:
* Given a sorted integer array `nums`, remove duplicates **in-place** so that each 
* unique element appears only once. The relative order of elements should be maintained.
* Return the number of unique elements `k`.
*
* After the function returns, the first `k` elements of `nums` should contain the
* unique elements in order. The elements beyond `k` are not important.
*
* Example:
* Input: nums = [0,0,1,1,1,2,2,3,3,4]
* Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
*
*
* Approach:
* - Use two pointers:
*   - `left` points to the last unique element found.
*   - Iterate `i` from 1 to end of array.
*   - When `nums[i]` is different from `nums[left]`, increment `left` and swap 
*     `nums[left]` and `nums[i]` to move the new unique element forward.
*
* Time Complexity: O(n), where n is the length of nums.
* Space Complexity: O(1), in-place with no extra space.
*
**********************************************************************************/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        bool flag = false;
        int temp = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[left] != nums[i]){
                left ++;
                temp = nums[left];
                nums[left] = nums[i];
                nums[i] = temp;    
            }
       }
       left++;
       return left;
    }
};
