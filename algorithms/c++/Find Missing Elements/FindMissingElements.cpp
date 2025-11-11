// Source : https://leetcode.com/problems/find-missing-elements/
// Author : Min Fang
// Date   : 2025-11-02

/**********************************************************************************
*
* Problem: Find Missing Elements in a Range
*
* You are given an integer array `nums` consisting of unique integers.
* The array originally contained every integer within a certain consecutive range,
* but some integers might be missing. The smallest and largest values of that range
* are still present in the array.
*
* Return a sorted list of all missing integers from that range.
* If no integers are missing, return an empty list.
*
*
* Example 1:
*   Input:  nums = [1, 4, 2, 5]
*   Output: [3]
*   Explanation:
*     Full range = [1, 2, 3, 4, 5]
*     Missing numbers = [3]
*
* Example 2:
*   Input:  nums = [7, 8, 6, 9]
*   Output: []
*   Explanation:
*     Full range = [6, 7, 8, 9]
*     All integers are present → no missing elements.
*
* Example 3:
*   Input:  nums = [5, 1]
*   Output: [2, 3, 4]
*   Explanation:
*     Full range = [1, 2, 3, 4, 5]
*     Missing numbers = [2, 3, 4]
*
*
* Constraints:
*   - 2 <= nums.length <= 100
*   - 1 <= nums[i] <= 100
*   - All elements in `nums` are unique
*
*
* Approach: Sorting and Range Iteration
*
* 1. Sort the input array `nums` to easily determine the consecutive range.
*    - After sorting, the smallest value is `nums[0]`, and the largest is `nums.back()`.
*
* 2. Iterate through the entire range [nums[0], nums.back()]:
*    - Maintain a pointer `j` to track the current index in `nums`.
*    - For each integer `i` in this range:
*        • If `i == nums[j]`, it exists → move `j` forward.
*        • Otherwise, `i` is missing → add it to the result vector.
*
* 3. Return the list of missing numbers.
*
*
* Example Walkthrough:
*   nums = [1, 4, 2, 5]
*   After sorting → [1, 2, 4, 5]
*   Range: [1 ... 5]
*   Compare:
*     i=1 → in nums
*     i=2 → in nums
*     i=3 → missing → add to result
*     i=4 → in nums
*     i=5 → in nums
*   Output: [3]
*
*
* Time Complexity: O(n log n)
*   - Sorting takes O(n log n)
*   - Single pass through range is O(max - min) ≤ O(100)
*
* Space Complexity: O(1)
*   - Only uses a small vector to store missing numbers
*
**********************************************************************************/
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int j = 0;
        for(int i = nums[0]; i <= nums[nums.size()-1]; i++){
            if(i == nums[j]){
                j++;
            }else{
                ans.push_back(i);
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
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int, int> map;
        int mi = INT_MAX;
        int ma = 0;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]] = 1;
            mi = min(mi, nums[i]);
            ma = max(ma, nums[i]);
        }
        vector<int> ans;
        for(int i = mi; i <= ma; i++){
            if(map.find(i) == map.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
