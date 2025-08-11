// Source : https://leetcode.com/problems/intersection-of-two-arrays-ii/
// Author : Min Fang
// Date   : 2025-08-11

/**********************************************************************************
*
* Problem: Intersection of Two Arrays II
*
* Given two integer arrays nums1 and nums2, return an array of their intersection.
* Each element in the result must appear as many times as it shows in both arrays.
* The result can be returned in any order.
*
*
* Example 1:
*   Input: nums1 = [1,2,2,1], nums2 = [2,2]
*   Output: [2,2]
*
* Example 2:
*   Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
*   Output: [4,9] or [9,4]
*
*
* Constraints:
*   - 1 <= nums1.length, nums2.length <= 1000
*   - 0 <= nums1[i], nums2[i] <= 1000
*
*
* Approach:
*
* - Use a hash map to store the frequency count of each element in the smaller array.
* - Swap nums1 and nums2 if necessary, to always iterate the smaller array when building the map.
* - Iterate the larger array:
*     - If the current element exists in the map with a non-zero count,
*       append it to the result and decrement its count in the map.
*
* - This ensures that each common element is recorded only as many times
*   as it appears in both arrays.
*
*
* Optimization Notes:
* - Using the smaller array to build the map reduces space complexity in practice.
* - This approach runs in O(n + m) time where n and m are the lengths of nums1 and nums2.
*
*
* Time Complexity: O(n + m)
*   - n = length of nums1, m = length of nums2
*
* Space Complexity: O(min(n, m))
*   - The hash map stores at most the number of unique elements from the smaller array.
*
**********************************************************************************/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> map;
        if(nums1.size() >= nums2.size()){
            swap(nums1, nums2);
        }
        for(int i = 0; i < nums1.size(); i++){
            map[nums1[i]]++;
        }
        for(int j = 0; j < nums2.size(); j++){
            if(map[nums2[j]]){
                ans.push_back(nums2[j]);
                map[nums2[j]]--;
            }
        }
        return ans;
    }
};
