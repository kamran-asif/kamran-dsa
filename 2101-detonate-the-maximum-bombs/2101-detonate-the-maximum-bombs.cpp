class Solution {
public:
typedef long long ll;
int dfs(int u,unordered_set<int>&visited,  unordered_map<int,vector<int>>&adj){
    visited.insert(u);//jst avi phoda h
    // u phta uske neighbour m jo h vo phtega
    int cnt=1;
    for(int &v:adj[u]){
        if(visited.find(v)==visited.end()){
            // visited ni h tbhi dfs call hoga
            cnt+=dfs(v,visited,adj);
        }
    }
    return cnt;
}
    int maximumDetonation(vector<vector<int>>& bomb) {
        int n=bomb.size();
        unordered_map<int,vector<int>>adj;
        //mKing graph
        for(int i=0;i<n;i++){//detonate bomb
           for(int j=0;j<n;j++){
               if(i==j)continue;
               ll x1=bomb[i][0];
               ll y1=bomb[i][1];
               ll r1=bomb[i][2];
              ll x2=bomb[j][0];
              ll y2=bomb[j][1];
               ll r2=bomb[j][2];
               ll dx=x2-x1;
               ll dy=y2-y1;
              ll distance=(dx*dx)+(dy*dy);
              ll radius=r1*r1;
                  if((radius)>=distance){
                    adj[i].push_back(j);
                  }


           }
        }
        int result=0;
        vector<int>memo(n,-1);

       // unordered_set<int>visited;//
        //hr node k liy dfs call krna h
        for(int i=0;i<n;i++){
            if(memo[i]==-1){
                unordered_set<int>visited;
                int cnt=  dfs(i,visited,adj);
                result=max(result,cnt);
                for(int v:visited){
                    memo[v]=cnt;
                }
            }
        /*  dfs(i,visited,adj);
          int cnt=visited.size();//visited k size chck kr rh h isse ye pta chl rh h ki ktne bomb phtt chuke h
          result=max(result,cnt);
          visited.clear();*/
        }
        return result;
    }
};