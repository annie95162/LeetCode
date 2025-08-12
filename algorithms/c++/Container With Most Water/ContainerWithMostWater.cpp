// Source : https://leetcode.com/problems/container-with-most-water/description/
// Author : Min Fang
// Date   : 2025-08-12

/**********************************************************************************
*
* Problem: Container With Most Water
*
* You are given an integer array `height` of length n. There are n vertical lines
* drawn such that the two endpoints of the i-th line are (i, 0) and (i, height[i]).
*
* Find two lines that together with the x-axis form a container, such that the 
* container contains the most water.
*
* Return the maximum amount of water a container can store.
*
* Notice that you may not slant the container (i.e., the container must be vertical).
*
*
* Example 1:
*   Input:  height = [1,8,6,2,5,4,8,3,7]
*   Output: 49
*   Explanation: The container is formed between lines at index 1 and 8:
*                height = min(8, 7) = 7, width = 8 - 1 = 7 → area = 7 * 7 = 49
*
* Example 2:
*   Input:  height = [1,1]
*   Output: 1
*
*
* Constraints:
*   - n == height.length
*   - 2 <= n <= 10^5
*   - 0 <= height[i] <= 10^4
*
*
* Approach:
*
* - Use the two-pointer technique:
*     - Initialize two pointers: one at the beginning (pt1 = 0) and one at the end (pt2 = n - 1).
*     - Calculate the area formed between the two lines: 
*         area = min(height[pt1], height[pt2]) * (pt2 - pt1)
*     - Keep track of the maximum area found so far.
*     - Move the pointer pointing to the shorter line inward:
*         - This is because the area is limited by the shorter height.
*         - Moving the shorter line gives a chance to find a taller one and potentially a bigger area.
* - Repeat until both pointers meet.
*
*
* Optimization Notes:
* - The greedy pointer-moving approach ensures we explore all potential max-area combinations
*   without brute force.
* - This reduces the complexity from O(n^2) to O(n).
*
*
* Time Complexity: O(n)
*   - Each element is visited at most once (by either pointer).
*
* Space Complexity: O(1)
*   - Only a few variables are used; no extra data structures needed.
*
**********************************************************************************/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int pt1 = 0;
        int pt2 = height.size()-1;
        while(pt2 > pt1){
            ans < min(height[pt1], height[pt2]) * (pt2 - pt1)? ans = min(height[pt1], height[pt2]) * (pt2 - pt1): ans = ans;
            height[pt1] == min(height[pt1], height[pt2])? pt1 += 1 : pt2 -= 1;
        }
        return ans;
    }
};
