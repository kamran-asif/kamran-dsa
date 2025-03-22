class Solution {
public:
//asn h bss no of edgecount krlo or dfs lgado bss

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
vector<vector<int>>adj(n);
for(auto &edge:edges){
    int u=edge[0],v=edge[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
}        
vector<bool>visited(n,false);
int completecomponents=0;
for(int i=0;i<n;i++){
    if(!visited[i]){
        unordered_set<int>nodes;
        int edgecount=0;
        dfs(i,adj,visited,nodes,edgecount);
        int nodecount=nodes.size();
        int expectededges=nodecount*(nodecount-1)/2;
        if(edgecount/2==expectededges){
            completecomponents++;

        }

    }

}
return completecomponents;
    }
    private:
    void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited,unordered_set<int>&nodes,int &edgecount){
        visited[node]=true;
        nodes.insert(node);
        for(int neighbour:adj[node]){
            edgecount++;
            if(!visited[neighbour]){
                dfs(neighbour,adj,visited,nodes,edgecount);
            }
        }
    }
};
