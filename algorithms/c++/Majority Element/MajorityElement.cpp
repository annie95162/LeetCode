// Source : https://leetcode.com/problems/group-anagrams/
// Author : Min Fang
// Date   : 2025-07-30

/**********************************************************************************
 *
 * Problem:
 * Given an array `nums` of size `n`, return the majority element.
 * The majority element is the one that appears more than ⌊n / 2⌋ times.
 * You may assume the majority element always exists in the array.
 *
 * Examples:
 *   Input: nums = [3,2,3]       → Output: 3
 *   Input: nums = [2,2,1,1,1,2,2] → Output: 2
 *
 *
 * Your Approach (Hash Map Count):
 * --------------------------------
 * Class Solution {
 * public:
 *     int majorityElement(vector<int>& nums) {
 *         unordered_map<int,int> map;
 *         for (int x : nums) map[x]++;
 *         for (auto& p : map) {
 *             if (p.second > nums.size() / 2) return p.first;
 *         }
 *         return 0;  // unreachable since majority always exists
 *     }
 * };
 *
 * - Time Complexity: O(n) — one pass to count, another to find max count.
 * - Space Complexity: O(n) — store counts for all distinct values.
 * - ✅ Works reliably given the problem guarantee that a majority element exists.
 *
 *
 * Alternative Optimal Approach: Boyer‑Moore Majority Vote Algorithm
 * ---------------------------------------------------------------
 * - Single pass to nominate a candidate and maintain a vote count.
 * - Optionally verify that the candidate is indeed > n/2 occurrences.
 *
 * Pseudocode:
 *   candidate = None, count = 0
 *   for each element x in nums:
 *     if count == 0: candidate = x
 *     count += (x == candidate ? 1 : -1)
 *   // Candidate at end must be the majority if one exists
 *
 * Properties:
 * - Time Complexity: O(n)
 * - Space Complexity: O(1)
 * - Elegant and optimal when memory is constrained.
 * - Intuition: pairs of non‑majority elements cancel out and the majority survives.
 *   :contentReference[oaicite:1]{index=1}
 *
 *
 * Summary:
 * - Your hash‑map approach is clear and intuitive, easy to implement and correct.
 * - Boyer‑Moore runs in linear time, uses constant extra space.
 *
 **********************************************************************************/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }
        for(auto j : map){
            if(j.second > nums.size()/2){
                return j.first;
            }
        }
        return 0;
    }
};
