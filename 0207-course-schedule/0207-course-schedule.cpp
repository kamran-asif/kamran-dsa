class Solution {
public:
    bool topologicalsortcheck(unordered_map<int, vector<int>>& adj, int n, vector<int>& indegree) {
        queue<int> que;
        int count = 0;

        // sare nodes jinka indegree 0 hai, unko queue mein daalo
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }

        // bfs chalao
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            count++; // har visited node ke liye count badhao

            for (int& v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        // check karo ki saare nodes visit hue ya nahi
        return count == n; // agar saare courses complete ho gaye toh true return karo
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // graph banao
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0); // indegree ko vector<int> rakho

        // prerequisites ke basis pe graph banao
        for (auto& vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            // edge from b -> a
            adj[b].push_back(a);
            indegree[a]++;
        }

        // cycle check karo topological sort se
        return topologicalsortcheck(adj, numCourses, indegree);
    }
};
