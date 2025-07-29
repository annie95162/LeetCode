// Source : https://leetcode.com/problems/group-anagrams/
// Author : Min Fang
// Date   : 2025-07-29

/**********************************************************************************
*
* Problem:
* Given an integer array `nums`, return `true` if any value appears at least
* twice in the array, and return `false` if every element is distinct.
*
* Example:
*   Input: nums = [1, 2, 3, 1]
*   Output: true
*
*   Input: nums = [1, 2, 3, 4]
*   Output: false
*
*   Input: nums = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
*   Output: true
*
* Constraints:
* - 1 <= nums.length <= 10^5
* - -10^9 <= nums[i] <= 10^9
*
*
* Approach:
*
* - Use a hash set (`unordered_set`) to store unique elements as we iterate through the array.
* - For each element in `nums`:
*     1. Check if it already exists in the set:
*         - If it does, return `true` immediately → a duplicate is found.
*     2. Otherwise, insert it into the set and continue.
* - If the loop completes without finding any duplicates, return `false`.
*
*
* Time Complexity: O(n)
*   - Each insertion and lookup in `unordered_set` is on average O(1).
*   - We traverse the array once.
*
* Space Complexity: O(n)
*   - In the worst case (no duplicates), we store all `n` elements in the set.
*
*
* ✅ Notes:
* - This is an efficient and common approach to solving duplicate detection problems in arrays.
* - It leverages the constant-time lookup property of hash sets for optimal performance.
*
**********************************************************************************/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++){
            if(s.find(nums[i]) != s.end()){
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++){
            if(s.find(nums[i]) != s.end()){
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};
/**********************************************************************************
*
*Solution 2
*
**********************************************************************************/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                return true;
                break;
            }
        }
        return false;
    }
};
