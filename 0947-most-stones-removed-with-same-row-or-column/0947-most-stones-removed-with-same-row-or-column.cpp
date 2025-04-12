class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool>visited(n,false);
        int components=0;
        //lamda function
        function<void(int)>dfs=[&](int idx){
            visited[idx]=true;
            for(int j=0;j<n;j++){
                if(!visited[j]&&(stones[idx][0]==stones[j][0]||stones[idx][1]==stones[1][idx])){
                    dfs(j);
                }
            }
        };
        //connected components
        for(int i=0;i<n;i++){
            if(!visited[i]){
                components++;
                dfs(i);
            }
        }
        return-components;
    }
};