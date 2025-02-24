class Solution {
public:
    bool findBobPath(vector<vector<int>>& adj, int bob, int parent, vector<int>& curr_path, vector<int>& bob_path) {
        curr_path.push_back(bob);
        if (bob == 0) { // If Bob reaches the root, store the path
            bob_path = curr_path;
            return true;
        }
        
        for (int nbr : adj[bob]) {
            if (nbr != parent && findBobPath(adj, nbr, bob, curr_path, bob_path)) {
                return true;
            }
        }
        
        curr_path.pop_back(); // Backtrack if not found
        return false;
    }

    int findMaxIncome(vector<vector<int>>& adj, int alice, int parent, vector<int>& amount) {
        int max_income = INT_MIN;
        bool isLeaf = true; // Track if Alice is at a leaf node

        for (int nbr : adj[alice]) {
            if (nbr != parent) {
                isLeaf = false;
                int income = findMaxIncome(adj, nbr, alice, amount);
                max_income = max(max_income, income);
            }
        }
        
        return (isLeaf) ? amount[alice] : amount[alice] + max_income;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);

        // Step 1: Build the adjacency list
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Step 2: Find Bob's path to the root
        vector<int> curr_path, bob_path;
        findBobPath(adj, bob, -1, curr_path, bob_path);

        // Step 3: Modify the amount array for Alice
        int path_size = bob_path.size();
        for (int i = 0; i < path_size / 2; ++i) {
            amount[bob_path[i]] = 0; // Bob takes full
        }
        if (path_size % 2 == 1) {
            amount[bob_path[path_size / 2]] /= 2; // Split at meeting point
        }

        // Step 4: Use DFS to find the maximum sum path for Alice
        return findMaxIncome(adj, 0, -1, amount);
    }
};
