// Source : https://leetcode.com/problems/sum-of-elements-with-frequency-divisible-by-k/
// Author : Min Fang
// Date   : 2025-10-20

/**********************************************************************************
*
* Problem: Sum of Elements Whose Frequency is Divisible by k
*
* Given an integer array `nums` and an integer `k`, return the sum of all elements
* in `nums` such that the frequency of the element is divisible by `k`.
*
* Important Notes:
*   - The element should be counted in the sum exactly as many times as it appears
*     in the array if its total frequency is divisible by `k`.
*   - If no such element exists, return 0.
*
*
* Example 1:
*   Input:  nums = [1, 2, 2, 3, 3, 3, 3, 4], k = 2
*   Output: 16
*   Explanation:
*     - 2 appears 2 times → divisible by 2 → included → 2 + 2
*     - 3 appears 4 times → divisible by 2 → included → 3 + 3 + 3 + 3
*     Total sum = 2 + 2 + 3 + 3 + 3 + 3 = 16
*
* Example 2:
*   Input:  nums = [1, 2, 3, 4, 5], k = 2
*   Output: 0
*   Explanation: No elements appear with frequency divisible by 2
*
* Example 3:
*   Input:  nums = [4, 4, 4, 1, 2, 3], k = 3
*   Output: 12
*   Explanation: 4 appears 3 times → 4 + 4 + 4 = 12
*
*
* Constraints:
*   - 1 <= nums.length <= 100
*   - 1 <= nums[i] <= 100
*   - 1 <= k <= 100
*
*
* Approach: Frequency Counting using Hash Map
*
* 1. Traverse the array and use a hash map (unordered_map) to count
*    how many times each unique element appears in `nums`.
*
* 2. Traverse the map:
*    - For each (element, count) pair, check if count is divisible by `k`
*    - If yes, add element * count to the total sum
*
* 3. Return the total sum. If no element meets the criteria, sum remains 0.
*
*
* Time Complexity: O(n)
*   - One pass to count frequencies
*   - One pass to compute the sum based on conditions
*
* Space Complexity: O(n)
*   - For storing frequency counts in hash map
*
**********************************************************************************/
class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }
        for(auto& num : map){
            if(num.second % k == 0){
                ans += num.first*num.second;
            }
        }
        return ans;
    }
};
