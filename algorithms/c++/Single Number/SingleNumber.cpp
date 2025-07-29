// Source : https://leetcode.com/problems/group-anagrams/
// Author : Min Fang
// Date   : 2025-07-29

/**********************************************************************************
*
* Problem:
* Given a non-empty array of integers `nums`, every element appears **twice** except for one.
* Find and return the **single** element that appears only once.
*
* Constraints:
* - Time complexity must be **linear** (O(n)).
* - Only **constant extra space** can be used.
*
*
* Example 1:
*   Input: nums = [2, 2, 1]
*   Output: 1
*
* Example 2:
*   Input: nums = [4, 1, 2, 1, 2]
*   Output: 4
*
* Example 3:
*   Input: nums = [1]
*   Output: 1
*
*
* Approach (Map-Based Counting):
*
* - We use an unordered_map to count the frequency of each number.
* - First, iterate through the array and store the count of each number.
* - Then, iterate through the map and return the number with a count of 1.
*
*
* Time Complexity: O(n)
* - We loop through the array once to build the map, and again to find the single element.
*
* Space Complexity: O(n)
* - We store up to `n` elements in the map, which violates the "constant space" requirement.
*
*
* ✅ Notes:
* - While this solution is correct and passes the problem constraints for correctness,
*   it does **not** meet the "constant space" requirement.
* - A more optimal solution uses bit manipulation (XOR) to achieve **O(n)** time and **O(1)** space:
*
*     int singleNumber(vector<int>& nums) {
*         int result = 0;
*         for (int num : nums) {
*             result ^= num;
*         }
*         return result;
*     }
*
*   Explanation:
*   - XOR of a number with itself is 0 (e.g., a ^ a = 0),
*   - XOR of a number with 0 is the number itself (e.g., a ^ 0 = a),
*   - Since all duplicate numbers cancel out, the remaining number is the one that appears once.
*
**********************************************************************************/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]] ++;
        }
        for(auto& j:map){
            if(j.second == 1){
                return j.first;
            }
        }
        return 0;
    }
};
/**********************************************************************************
*
*Solution 2
*
**********************************************************************************/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(),nums.end());
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums[0] != nums[1]){
            return nums[0];
        }
        if(nums[nums.size()-1] != nums[nums.size()-2]){
            return nums[nums.size()-1];
        }
        for(int i = 1; i < nums.size()-1; i++){
            if(nums[i] != nums[i-1] && nums[i] != nums[i+1]){
                ans = nums[i];
                break;
            }
        } 
        return ans;
    }
};
