/********************************************************************************** 
* 
* Given an array of integers nums and an integer target, return the indices of the 
* two numbers such that they add up to target.
* Each input will have exactly one solution, and you may not use the same element twice.
* 
* Approach:
* 
* - Brute-force approach using two nested loops to check every pair of numbers.
* - Compares each pair to see if their sum equals the target.
* - If a pair is found, returns the indices of the two numbers.
* - Time complexity: O(n^2)
* - Space complexity: O(1)
* 
* For example:
*     Input: nums = [2,7,11,15], target = 9
*     Output: [0, 1]
*     Explanation:
*       nums[0] + nums[1] = 9
*       So, the answer is [0, 1].
* 
**********************************************************************************/
