
// union-find (Disjoint Set Union) class
class UnionFind {
public:
    vector<int> parent;
    
    UnionFind(int n) {
        parent.resize(n + 1); // 1-based indexing
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    bool unionSet(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py)
            return false; // Cycle detected
        parent[py] = px;
        return true;
    }
};

// Solution class
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n);

        for (auto& edge : edges) {
            if (!uf.unionSet(edge[0], edge[1]))
                return edge; // This edge created a cycle
        }

        return {};
    }
};
