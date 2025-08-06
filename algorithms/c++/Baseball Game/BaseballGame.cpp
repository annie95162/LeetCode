// Source : https://leetcode.com/problems/baseball-game/
// Author : Min Fang
// Date   : 2025-08-06

/**********************************************************************************
 *
 * Problem:
 * ----------
 * You are given a list of strings `operations`, representing baseball game operations.
 * The operations follow these rules:
 * - Integer `x`: Record a new score of x.
 * - '+'       : Record a score equal to the sum of the previous two scores.
 * - 'D'       : Record a score that is double the previous score.
 * - 'C'       : Invalidate and remove the previous score.
 *
 * Goal:
 * -----
 * After performing all operations, return the total sum of the scores recorded.
 *
 *
 * Approach:
 * ---------
 * - Use a `vector<int> a` to simulate the record of scores.
 * - Use an integer `now` to track the current number of valid scores in the record.
 * - Use an integer `ans` to store the running total of the scores.
 *
 * Step-by-step Logic:
 * -------------------
 * For each operation:
 * - If it is "C":
 *     - Remove the last score from the record.
 *     - Subtract that score from the total `ans`.
 *     - Decrement `now`.
 *
 * - If it is "+":
 *     - Calculate the sum of the previous two scores in the record.
 *     - Add it to the record and update `ans`.
 *     - Increment `now`.
 *
 * - If it is "D":
 *     - Double the previous score and record it.
 *     - Add it to `ans`.
 *     - Increment `now`.
 *
 * - Otherwise (numeric string):
 *     - Convert the string to integer using `stoi`.
 *     - Push it into the record.
 *     - Add to `ans`.
 *     - Increment `now`.
 *
 *
 * Time Complexity:
 * ----------------
 * - O(n), where n is the number of operations (each processed once).
 *
 * Space Complexity:
 * -----------------
 * - O(n), for storing all valid scores in the record.
 *
 *
 * Notes:
 * ------
 * - The use of `now` is a manual index tracking method (like a pointer to top of the stack).
 * - It could also be replaced with using `a.size()` directly, but `now` is kept for clarity.
 *
 **********************************************************************************/
class Solution {
public:
    int calPoints(vector<string>& operations) {
        int now = 0;
        int ans = 0;;
        vector<int> a;
        for(int i = 0; i < operations.size(); i++){
            if(operations[i][0] == 'C'){
                a.pop_back();
                ans -= a[now-1];
                now -= 1;
            }else if(operations[i][0] == '+'){
                a.push_back(a[now-1] + a[now-2]);
                ans += a[now-1] + a[now-2];
                now += 1;
            }else if(operations[i][0] == 'D'){
                a.push_back(a[now-1]*2);
                ans += a[now-1]*2;
                now += 1;
            }else{
                int t = stoi(operations[i]);
                a.push_back(t);
                ans += t;
                now += 1;
            }
        }
        return ans;
    }
};
