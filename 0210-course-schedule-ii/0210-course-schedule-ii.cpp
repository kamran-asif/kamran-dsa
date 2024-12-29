class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Adjacency list representation
        vector<int> adj[numCourses];
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        // Initialize indegree array
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        // Queue to store nodes with indegree 0
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Perform Kahn's Algorithm for Topological Sort
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // If the topo sort includes all courses, return it; otherwise, return an empty array
        if (topo.size() == numCourses) return topo;
        return {};
    }
};
