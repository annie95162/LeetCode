// Source : https://leetcode.com/problems/intersection-of-two-arrays/
// Author : Min Fang
// Date   : 2025-08-11

/**********************************************************************************
*
* Problem: Intersection of Two Arrays
*
* Given two integer arrays nums1 and nums2, return an array of their intersection.
* Each element in the result must be unique and you may return the result in any order.
*
*
* Example 1:
*   Input: nums1 = [1,2,2,1], nums2 = [2,2]
*   Output: [2]
*
* Example 2:
*   Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
*   Output: [9,4] or [4,9]
*
*
* Constraints:
*   - 1 <= nums1.length, nums2.length <= 1000
*   - 0 <= nums1[i], nums2[i] <= 1000
*
*
* Approach:
*
* - Use an unordered map to record the presence of each unique element in the smaller array.
* - Swap nums1 and nums2 if nums1 is larger, to minimize space usage when building the map.
* - Iterate through the larger array (now nums2):
*     - If the current element exists in the map (non-zero value),
*       add it to the result and mark it as used by setting the value to 0.
*
* - This ensures that each element appears only once in the result, even if there are duplicates.
*
*
* Optimization Notes:
* - Building the map from the smaller array helps reduce memory usage.
* - Using unordered_map allows for average O(1) lookups and insertions.
*
*
* Time Complexity: O(n + m)
*   - n = length of nums1, m = length of nums2
*
* Space Complexity: O(min(n, m))
*   - The map stores at most the number of unique elements from the smaller array.
*
**********************************************************************************/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> map;
        if(nums1.size() > nums2.size()){
            swap(nums1, nums2);
        }
        for(int i = 0; i < nums1.size(); i++){
            map[nums1[i]]++;
        }
        for(int j = 0; j < nums2.size(); j++){
            if(map[nums2[j]]){
                ans.push_back(nums2[j]);
                map[nums2[j]] = 0;
            }
        }
        return ans;
    }
};
