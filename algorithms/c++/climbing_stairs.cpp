class Solution {
public:
    int climbStairs(int n) {
        int p = 1, q = 1, r = 1;
        for(int i = 2; i <= n; i++){
            r = q;
            q = p + q;
            p = r;
        }
        return q;

    }
};
