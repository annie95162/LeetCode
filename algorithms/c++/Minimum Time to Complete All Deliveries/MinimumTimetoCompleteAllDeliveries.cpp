// Source : https://leetcode.com/problems/minimum-time-to-complete-all-deliveries/
// Author : Min Fang
// Date   : 2025-11-03

/**********************************************************************************
*
* Problem: Minimum Total Time for Two Delivery Drones
*
* You are given:
*   - Two integer arrays of size 2:
*       - d = [d1, d2], where di is the number of deliveries Drone i must complete.
*       - r = [r1, r2], where ri means Drone i must recharge every ri hours.
*
* Rules:
*   - Each delivery takes exactly 1 hour.
*   - At any given hour, **only one drone** can perform a delivery.
*   - Drones cannot deliver during their recharge hours (hours that are multiples of ri).
*
* Goal:
*   Return the **minimum total time (in hours)** required for both drones to finish
*   all their assigned deliveries.
*
*
* Example 1:
*   Input:  d = [3, 1], r = [2, 3]
*   Output: 5
*   Explanation:
*     Drone 1 delivers at hours 1, 3, 5 (recharges at 2, 4)
*     Drone 2 delivers at hour 2 (recharges at 3)
*     Total time = 5
*
* Example 2:
*   Input:  d = [1, 3], r = [2, 2]
*   Output: 7
*   Explanation:
*     Drone 1 delivers at hour 3 (recharges at 2, 4, 6)
*     Drone 2 delivers at hours 1, 5, 7 (recharges at 2, 4, 6)
*     Total time = 7
*
* Example 3:
*   Input:  d = [2, 1], r = [3, 4]
*   Output: 3
*   Explanation:
*     Drone 1 delivers at hours 1, 2 (recharge at 3)
*     Drone 2 delivers at hour 3
*     Total time = 3
*
*
* Constraints:
*   - 1 <= di <= 10^9
*   - 2 <= ri <= 3 * 10^4
*
*
* Approach: Binary Search on Time + Counting Deliverable Hours
*
* 1. **Key idea:**
*    For any given total time T, we can calculate how many deliveries
*    each drone could have completed up to hour T.
*
* 2. **Drone i delivery count formula:**
*       ci = T - floor(T / ri)
*    → total hours minus recharge hours.
*
* 3. **Overlap correction:**
*    Since only one drone can deliver at any hour, and both might be recharging
*    or available at the same time, we need to handle overlapping recharges.
*
*    Let:
*      - lcm = least common multiple of r1 and r2
*      - shared downtime correction = ci + c2 - T + floor(T / lcm)
*
*    This ensures we correctly count the total number of delivery hours
*    that can be distributed between the two drones.
*
* 4. **Binary Search Process:**
*    - left = 0, right = 1e18 (large enough upper bound)
*    - For mid = (left + right) / 2:
*         compute:
*            c1 = mid - floor(mid / r1)
*            c2 = mid - floor(mid / r2)
*            overlap = c1 + c2 - mid + floor(mid / lcm)
*    - If both drones can finish their required deliveries (c1 >= d1, c2 >= d2)
*      and total available delivery slots (c1 + c2 - overlap) >= (d1 + d2),
*      then it's feasible → move `right = mid`
*      else → move `left = mid + 1`
*
* 5. **Result:**
*    The minimal feasible `T` after binary search ends is the answer.
*
*
* Mathematical Formulas (for reference):
*   c1 = T - floor(T / r1)
*   c2 = T - floor(T / r2)
*   overlap = c1 + c2 - T + floor(T / lcm(r1, r2))
*
*   Feasibility condition:
*     (c1 >= d1) and (c2 >= d2) and (c1 + c2 - overlap >= d1 + d2)
*
*
* Time Complexity: O(log(1e18)) ≈ O(60)
*   - Each binary search iteration runs in O(1).
*
* Space Complexity: O(1)
*   - Only constant variables used.
*
**********************************************************************************/
class Solution {
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
        
        int d1 = d[0];
        int d2 = d[1];
        int r1 = r[0];
        int r2 = r[1];
        
        int temp = 0;
        int t1 = r1;
        int t2 = r2;
        while(t2){
            temp = t2;
            t2 = t1 % t2;
            t1 = temp;
        }
        long long lcm = r1 * r2 / t1;

        long long left = 0;
        long long right = 1e18;
        long long mid = 0;
        long long c1 = 0;
        long long c2 = 0;
        long long share = 0;
        while(left < right){
            mid = (right + left)/2;
            c1 = mid - int(mid/r1);
            c2 = mid - int(mid/r2);
            share = c1 + c2 - mid + int(mid/lcm);
            if((c1 + c2 - share >= d1 + d2) && (c1 >= d1) && (c2 >= d2)){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;

    }
};share = c1 + c2 - T + floor(T / lcm(r1, r2))
