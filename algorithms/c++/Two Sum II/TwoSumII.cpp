// Source : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Author : Min Fang
// Date   : 2025-08-12

/**********************************************************************************
*
* Problem: Two Sum II - Input Array Is Sorted
*
* Given a 1-indexed array of integers `numbers` that is sorted in non-decreasing order,
* find two numbers such that they add up to a specific target number. Let these two 
* numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
*
* Return the indices of the two numbers, index1 and index2, added by one 
* as an integer array [index1, index2] of length 2.
*
* The tests are generated such that there is exactly one solution.
* You may not use the same element twice.
* Your solution must use only constant extra space.
*
*
* Example 1:
*   Input:  numbers = [2,7,11,15], target = 9
*   Output: [1,2]
*   Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2.
*
* Example 2:
*   Input:  numbers = [2,3,4], target = 6
*   Output: [1,3]
*
* Example 3:
*   Input:  numbers = [-1,0], target = -1
*   Output: [1,2]
*
*
* Constraints:
*   - 2 <= numbers.length <= 3 * 10^4
*   - -1000 <= numbers[i] <= 1000
*   - numbers is sorted in non-decreasing order.
*   - -1000 <= target <= 1000
*   - Exactly one solution exists.
*
*
* Approach:
*
* - Since the input array is sorted, we can use a two-pointer approach:
*   - Initialize one pointer at the beginning (pt1) and one at the end (pt2) of the array.
*   - In each iteration:
*       - Compute the sum of the two pointed numbers.
*       - If the sum equals the target, return the indices (converted to 1-based).
*       - If the sum is greater than the target, move the end pointer left.
*       - If the sum is less than the target, move the start pointer right.
* - This approach works in linear time and uses constant extra space.
*
*
* Optimization Notes:
* - The sorted property allows us to avoid using a hashmap.
* - The use of constant pointers meets the problem's space constraint.
*
*
* Time Complexity: O(n)
*   - Each element is visited at most once by either pointer.
*
* Space Complexity: O(1)
*   - No extra space is used except for return value.
*
**********************************************************************************/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int pt1 = 0;
        int pt2 = numbers.size() - 1;
        int t = 0;
        while(pt1 < pt2){
            t = numbers[pt1] + numbers[pt2];
            if(t == target){
                return {pt1+1, pt2+1};
                break;
            }else if(t > target){
                pt2 -= 1;
            }else{
                pt1 += 1;
            }
        }
        return {0,0};
    }
};
