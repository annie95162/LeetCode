// Source : https://leetcode.com/problems/first-bad-version/
// Author : Min Fang
// Date   : 2025-08-21

/**********************************************************************************
*
* Problem: First Bad Version
*
* You are a product manager and are leading a team to develop a product. 
* Unfortunately, the latest version fails the quality check.
*
* Every version is built upon the previous one, so once a version is bad, 
* all following versions are also bad.
*
* Your task is to find the **first bad version** given `n` versions `[1, 2, ..., n]`.
* 
* You are given a helper function:
*     bool isBadVersion(int version);
* that returns `true` if the version is bad, and `false` otherwise.
*
* You want to minimize the number of calls to `isBadVersion`.
*
*
* Example 1:
*   Input:  n = 5, bad = 4
*   Output: 4
*   Explanation:
*       isBadVersion(3) -> false
*       isBadVersion(5) -> true
*       isBadVersion(4) -> true
*       => First bad version is 4
*
* Example 2:
*   Input:  n = 1, bad = 1
*   Output: 1
*
*
* Constraints:
*   - 1 <= bad <= n <= 2^31 - 1
*
*
* Approach: Binary Search
*
* - We use binary search to minimize the number of `isBadVersion` calls.
* - Define `left = 0` and `right = n`, and compute mid in each step:
*     mid = left + (right - left) / 2  // prevents integer overflow
*
* - If `isBadVersion(mid)` is true:
*     ➜ The first bad version is at `mid` or before it ➜ move `right = mid - 1`
*
* - If `isBadVersion(mid)` is false:
*     ➜ The first bad version must be after `mid` ➜ move `left = mid + 1`
*
* - The loop stops when `left > right`, and `left` will point to the first bad version.
*
*
* Time Complexity: O(log n)
*   - Classic binary search — the search space is halved each time.
*
* Space Complexity: O(1)
*   - Only uses a few variables.
*
**********************************************************************************/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int mid = 0;
        int left = 0;
        int right = n;
        while(left <= right){
            mid = (right-left)/2 + left;
            if(isBadVersion(mid)){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};
