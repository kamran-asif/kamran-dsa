class Solution {
public:
// k is source n is node
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    //adj list
      unordered_map<int,vector<pair<int,int>>>adj;
      for(auto&vec:times){
        int u=vec[0];
        int v=vec[1];
        int w=vec[2];// w-weight
        adj[u].push_back({v,w});// u s kha tk arrow hai v tk or weeight ktna hai w yha weight time dya hua hai 
      }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>result(n+1,INT_MAX);
        result[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int d=pq.top().first;//smallest distance in queue
            int node=pq.top().second;// node which is associated with that distance
            pq.pop();// those pair is removed 
            for(auto &vec:adj[node]){
                int adjnode=vec.first;// vec[0] kyu ni hua kyuki pair use kye hai //neighbour node
                int dist=vec.second;//weight of edge btwn crrnt node and nxt node
                if(d+dist<result[adjnode]){
                    result[adjnode]=d+dist;
                    pq.push({d+dist,adjnode});//pair mai isly ye use kiy{}
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            ans=max(ans,result[i]);
        }
        return ans==INT_MAX?-1:ans;
    }
};