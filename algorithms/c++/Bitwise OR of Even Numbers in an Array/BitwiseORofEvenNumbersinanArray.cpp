// Source : https://leetcode.com/problems/bitwise-or-of-even-numbers-in-an-array/description/
// Author : Min Fang
// Date   : 2025-09-22

/**********************************************************************************
*
* Problem: Bitwise OR of Even Numbers in an Array
*
* Given an integer array `nums`, return the bitwise OR of all even numbers in the array.
* If there are no even numbers, return 0.
*
* Example 1:
*   Input:  nums = [1, 2, 3, 4, 5, 6]
*   Output: 6
*   Explanation: The even numbers are 2, 4, and 6. Their bitwise OR is 6.
*
* Example 2:
*   Input:  nums = [7, 9, 11]
*   Output: 0
*   Explanation: No even numbers exist.
*
* Example 3:
*   Input:  nums = [1, 8, 16]
*   Output: 24
*   Explanation: 8 | 16 = 24.
*
*
* Constraints:
*   - 1 <= nums.length <= 100
*   - 1 <= nums[i] <= 100
*
*
* Approach: Bitwise Decomposition and Recombination
*
* - Step 1: Filter out all even numbers from the array.
* - Step 2: If no even numbers exist, return 0 immediately.
* - Step 3: Sort the even numbers to find the maximum value.
* - Step 4: Build a list of powers of two up to the max even number.
* - Step 5: For each even number, decompose it into its binary components by subtracting the largest powers of two.
*          If a power of two is used, mark it as present (set its flag to 1).
* - Step 6: After processing all even numbers, sum up all powers of two whose flags are set.
*          This reconstructs the result of bitwise OR of all even numbers.
*
*
* Time Complexity: O(n log n)
*   - O(n) for filtering evens
*   - O(n log n) for sorting (dominant term)
*   - O(n * log M) for decomposing numbers (M is max value, at most 100)
*
* Space Complexity: O(log M)
*   - Space used to store powers of two and flags
*
**********************************************************************************/
class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        vector<int> even;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 0){
                even.push_back(nums[i]);
            }
        }
        if(even.size() == 0){
            return 0;
        }
        sort(even.begin(),even.end());
        int twos = 2;
        vector<vector<int>> twosvec;
        int maxeven = even[even.size()-1];
        while(maxeven >= twos){
            twosvec.push_back({twos, 0});
            twos *= 2;
        }
        for(int i = 0; i < even.size(); i++){
            int j = twosvec.size()-1;
            while(j >= 0){
                if(even[i] >= twosvec[j][0]){
                    twosvec[j][1] = 1;
                    even[i] -= twosvec[j][0];
                }
                j--;
            }
        }
        int ans = 0;
        for(int i = 0; i < twosvec.size(); i++){
            if(twosvec[i][1]){
                ans += twosvec[i][0];
            }
        }
        return ans;

    }
};
