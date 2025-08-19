// Source : https://leetcode.com/problems/max-consecutive-ones-iii/
// Author : Min Fang
// Date   : 2025-08-20

/**********************************************************************************
* 
* Problem: Max Consecutive Ones III
* 
* Given a binary array nums and an integer k, return the maximum number of 
* consecutive 1s in the array if you can flip at most k 0s to 1s.
* 
* Example 1:
* Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
* Output: 6
* Explanation: Flip 2 zeros at indices 3 and 4 → [1,1,1,0,0,1,1,1,1,1,1].
* The longest subarray is of length 6.
* 
* Example 2:
* Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
* Output: 10
* 
* Constraints:
* - 1 <= nums.length <= 10^5
* - nums[i] is either 0 or 1
* - 0 <= k <= nums.length
* 
* Approach: Sliding Window
* 
* - Use two pointers, left and i (right), to maintain a sliding window.
* - Traverse the array and count the number of zeros in the window (cnt).
* - If the number of zeros exceeds k, shrink the window from the left until
*   we have at most k zeros.
* - During each iteration, update the maximum window size (ans).
* 
* Key Logic:
* - cnt: Number of zeros in the current window.
* - When cnt > k, move left forward until cnt <= k.
* - If nums[left] is 0, decrement cnt as we remove it from the window.
* 
* Time Complexity: O(n)
* - Each element is visited at most twice (once by i, once by left).
* 
* Space Complexity: O(1)
* - Uses a constant amount of extra space.
* 
**********************************************************************************/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                cnt++;
            }
            if(cnt > k){
                while(nums[left]){
                    left++;
                }
                left++;
                cnt--;
            }
            ans = max(ans, i - left + 1);
            cout << i << left << endl;
        }
        return ans;
    }
};
