// Source : https://leetcode.com/problems/sum-of-perfect-square-ancestors/
// Author : Min Fang
// Date   : 2025-10-21

/**********************************************************************************
*
* Problem: Sum of Ancestors with Perfect Square Product
*
* You are given:
*   - An integer `n` representing the number of nodes in a tree (rooted at node 0)
*   - A list of undirected edges `edges` representing the tree connections
*   - An integer array `nums`, where nums[i] is the value assigned to node i
*
* Define:
*   For each node i (excluding the root), let ti be the number of its ancestors
*   such that nums[i] * nums[ancestor] is a *perfect square*.
*
* Task:
*   Return the sum of all ti for i in [1, n - 1].
*
*
* Example 1:
*   Input:  n = 3, edges = [[0,1],[1,2]], nums = [2,8,2]
*   Output: 3
*
*   Explanation:
*       i | Ancestors | nums[i] * nums[ancestor] | Perfect Square | ti
*      ---+------------+--------------------------+----------------+---
*       1 | [0]        | 8 * 2 = 16              | yes             | 1
*       2 | [1,0]      | 2 * 8 = 16              | yes             | 
*                     | 2 * 2 = 4               | yes             | 2
*       → Total = 1 + 2 = 3
*
*
* Example 2:
*   Input:  n = 3, edges = [[0,1],[0,2]], nums = [1,2,4]
*   Output: 1
*
*   Explanation:
*       i | Ancestors | nums[i] * nums[ancestor] | Perfect Square | ti
*      ---+------------+--------------------------+----------------+---
*       1 | [0]        | 2 * 1 = 2               | no              | 0
*       2 | [0]        | 4 * 1 = 4               | yes             | 1
*       → Total = 0 + 1 = 1
*
*
* Constraints:
*   - 1 <= n <= 1e5
*   - 1 <= nums[i] <= 1e5
*   - edges represents a valid tree
*
*
* Approach: Square-Free Factorization + DFS Path Counting
*
* Key Observation:
*   The product nums[i] * nums[ancestor] is a perfect square  ⇔  nums[i] and nums[ancestor] have the same *square-free part*.
*
* Step 1: Precompute smallest prime factors (SPF) for numbers up to 1e5.
*         This allows efficient prime factorization in O(log n).
*
* Step 2: For each node value nums[i], compute its *square-free core*:
*         Remove all prime factors that appear an even number of times.
*
*         Example:
*            nums[i] = 12 = 2² * 3¹ → square-free part = 3
*            nums[i] = 18 = 2¹ * 3² → square-free part = 2
*
* Step 3: Traverse the tree using DFS.
*         Maintain a frequency map of square-free parts along the current path
*         from root → current node.
*
*         For each node u:
*           - Count how many ancestors share the same square-free part
*             → increment answer by map[oddfac[u]]
*           - Add current node’s square-free part to map
*           - Recursively process children
*           - Remove current node’s part after backtracking
*
* Step 4: Return the accumulated answer.
*
*
* Mathematical Meaning:
*   Let f(x) be the square-free core of x.
*   nums[i] * nums[j] is a perfect square  ⇔  f(nums[i]) == f(nums[j])
*
*
* Example Walkthrough:
*   nums = [2, 8, 2]
*   f(2) = 2, f(8) = 2, f(2) = 2
*   Tree edges: 0–1–2
*
*   DFS Path:
*     - Node 0 (f=2)
*     - Node 1 → ancestor with f=2 → +1
*     - Node 2 → ancestors with f=2 (two of them) → +2
*   → Total = 3
*
*
* Time Complexity: O(n log A)
*   - O(A log A) for smallest prime factor sieve (A = 1e5)
*   - O(n log A) for factorization of all node values
*   - O(n) for tree traversal
*
* Space Complexity: O(n)
*   - For adjacency list, square-free values, and map tracking during DFS
*
**********************************************************************************/
class Solution {
    vector<int> smallprimefactor(int N) {
        vector<int> spf(N + 1);
        for(int i = 2; i <= N; i++){
            if(i % 2 == 0){
                spf[i] = 2;
            }else{
                spf[i] = 0;
            }
        }

        for(int i = 3; 1LL*i*i <= N; i+=2){
            if(spf[i] == 0){
                spf[i] = i;
                for(long long j = 1LL*i*i; j <= N; j+=1LL*i*2){
                    if(spf[j] == 0){
                        spf[j] = i;
                    }
                }
            }
        }
        for(int i = 2; i <= N; i++){
            if(spf[i] == 0){
                spf[i] = i;
            }
        }
        spf[1] = 1;
        return spf;
    }
    int oddtimefactor(int x, const vector<int>& spf) {
        if(x == 1){
            return 1;
        }
        int res = 1;
        int p = 0;
        int cnt = 0;
        while(x > 1){
            p = spf[x];
            cnt = 0;
            while(x % p == 0){
                x /= p;
                cnt++;
            }
            if (cnt%2 == 1){
                res *= p; 
            }
        }
        return res;
    }
public:
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        vector<vector<int>> tree(n);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        vector<int> spf = smallprimefactor(100000);
        vector<int> oddfac(n);
        for(int i = 0; i < n; i++){
            oddfac[i] = oddtimefactor(nums[i], spf);
        }

        vector<int> parent(n, -1);
        vector<pair<int,int>> st;
        st.push_back({0, 0});
        unordered_map<int,int> map;
        long long ans = 0;

        while(!st.empty()){
            auto [u, state] = st.back();
            st.pop_back();
            if(state == 0){
                if(u != 0){
                    auto it = map.find(oddfac[u]); // find oddfac[u] appears past or not
                    if(it != map.end()){
                        ans += it->second;
                    }
                }
                map[oddfac[u]]++;
                st.push_back({u, 1});

                for(int v : tree[u]){
                    if(v != parent[u]){
                        parent[v] = u;
                        st.push_back({v, 0});
                    }
                }
            }else{
                auto it = map.find(oddfac[u]);
                if(it != map.end()){
                    it->second--;
                    if (it->second == 0) {
                        map.erase(it);
                    }
                }
            }
        }
        return ans;
    }
};
