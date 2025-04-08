class Solution {
public:
    static const int T = 15; // maxmm number of “hlving” states we consder
    int n, k;                // n = number of nodes; k = penalty parameter
    vector<int> coins;       // coins[i] = number of coins at node i
    vector<vector<int>> adj; // adjcncy list for the tree

    // dp[u][t] = best points frm sbtree rooted at u, given t hlvings have been applied above u
    vector<array<long long, T>> dp;

    // dfS helper to fill dp[u][*] for the sbtree at u
    void dfs(int u, int parent) {
        array<long long, T> sum_t{}, sum_t1{};

        for (int v : adj[u]) {
            if (v == parent) continue;
            dfs(v, u);
            for (int t = 0; t < T; ++t) {
                sum_t[t] += dp[v][t];
                if (t + 1 < T)
                    sum_t1[t] += dp[v][t + 1];
            }
        }

        for (int t = 0; t < T; ++t) {
            long long opt1 = (coins[u] >> t) - k + sum_t[t];
            long long opt2 = LLONG_MIN;
            if (t + 1 < T) {
                opt2 = (coins[u] >> (t + 1)) + sum_t1[t];
            }
            dp[u][t] = max(opt1, opt2);
        }
    }

    // pblic intrface: given edges, coins, and k, return the maxmum points
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        this->coins = coins; // use this-> to access class member
        this->k = k;
        n = coins.size();

        adj.assign(n, {});
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dp.assign(n, array<long long, T>{});
        dfs(0, -1);
        return dp[0][0];
    }
};
