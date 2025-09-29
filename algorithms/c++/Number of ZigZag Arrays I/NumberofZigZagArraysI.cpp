class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(r+1,0)));
        for(int i = l; i <= r; i++){
            dp[1][0][i] = 1;
            dp[1][1][i] = 1;
        }
        vector<vector<int>> pf(r+1, vector<vector<int>>(2,0));
        for(int )
        for(int i = 2; i <= n; i++){
            
        }
    }
};
