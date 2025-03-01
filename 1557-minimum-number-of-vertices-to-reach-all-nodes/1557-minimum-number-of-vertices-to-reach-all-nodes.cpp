class Solution {
public:
 
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            
        }
        vector<int>result;

        vector<int>indegre(n,0);
        for(int i=0;i<n;i++){
         for(auto it : adj[i]){
            indegre[it]++;
        }

        }

        for(int i=0;i<n;i++){
            if(indegre[i]==0){
                result.push_back(i);
            }
        }
    

     

        return result;

    }
};