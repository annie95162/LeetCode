// Source : https://leetcode.com/problems/peak-index-in-a-mountain-array/
// Author : Min Fang
// Date   : 2025-08-28

/**********************************************************************************
*
* Problem: Peak Index in a Mountain Array
*
* A **mountain array** is defined as an array where:
* - arr.length >= 3
* - There exists an index `i` (0 < i < arr.length - 1) such that:
*     arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
*
* In other words, the array strictly increases up to a peak, and then strictly decreases.
*
* Your task is to find and return the **index of the peak element**.
*
* You must solve this in **O(log n)** time complexity.
*
* ------------------------------------------------------------------------------
* Example 1:
*   Input:  arr = [0, 1, 0]
*   Output: 1
*
* Example 2:
*   Input:  arr = [0, 2, 1, 0]
*   Output: 1
*
* Example 3:
*   Input:  arr = [0, 10, 5, 2]
*   Output: 1
*
* Constraints:
*   - 3 <= arr.length <= 10^5
*   - 0 <= arr[i] <= 10^6
*   - It is guaranteed that `arr` is a mountain array
*
*
* Approach: Binary Search
*
* Key Insight:
* - Since the array increases then decreases, we can use a binary search to
*   efficiently locate the peak element.
*
* Algorithm:
* 1. Initialize `left = 0`, `right = arr.size() - 1`
* 2. While `left < right`:
*    - Compute `mid = (left + right) / 2`
*    - If `arr[mid] > arr[mid + 1]`, then:
*        → You are on the **descending** side of the mountain
*        → So the peak is at `mid` or to the **left**, set `right = mid`
*    - Else:
*        → You are on the **ascending** side of the mountain
*        → So the peak must be to the **right**, set `left = mid + 1`
* 3. When `left == right`, the loop ends, and that index is the peak
*
*
* Time Complexity: O(log n)
*   - We cut the search space in half on every iteration
*
* Space Complexity: O(1)
*   - Only constant extra space used
*
**********************************************************************************/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() -1;
        int mid = 0;

        while(left < right){
            mid = (right - left)/2 + left;
            if(arr[mid] > arr[mid + 1]){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};
