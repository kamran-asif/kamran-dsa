class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        // if there's only one node, there's exactly one way to stay at it  
        if (n == 1) return 1;
        if (roads.empty()) return 0;

        // creating an adjacency list for the given graph  
        vector<vector<pair<int, int>>> adj(n);
        for (auto &it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // priority queue (min heap)  
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        // initializing the distance and ways arrays  
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

      
        int mod = 1e9 + 7;

        // dijkstra's algorithm with path counting  
        while (!pq.empty())
        {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto &it : adj[node])
            {
                int adjNode = it.first;
                int edW = it.second;

                // if a new shortest path is found  
                if (dis + edW < dist[adjNode])
                {
                    dist[adjNode] = dis + edW;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                // if another shortest path of the same length is found  
                else if (dis + edW == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};
