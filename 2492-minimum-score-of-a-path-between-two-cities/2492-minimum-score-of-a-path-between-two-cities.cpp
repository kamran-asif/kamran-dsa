class Solution {
public:
void dfs(int u,unordered_map<int,vector<pair<int,int>>>&adj, vector<bool>&visited,int &result){
    visited[u]=true;
    //neighbour
    for(auto&p:adj[u]){// its ampair so it is p
      int v=p.first;
      int d=p.second;
    result=min(result,d);
    if(!visited[v]){
        dfs(v,adj,visited,result);
    }
    }
}
    
      int minScore(int n,vector<vector<int>>&roads){
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto&vec:roads){
            int u=vec[0];
            int v=vec[1];
            int d=vec[2];
            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }
        vector<bool>visited(n,false);
        int result=INT_MAX;
        dfs(1,adj,visited,result);
        return result;
            }
};