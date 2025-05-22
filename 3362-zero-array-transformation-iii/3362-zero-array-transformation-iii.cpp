class Solution {
public:
bool ispossible(vector<int>&nums,const vector<vector<int>>&queries,vector<bool>&used){
    int n=nums.size();
    vector<int>diff(n+1,0);
    for(int i=0;i<queries.size();i++){
        if(!used[i])continue;
        int l=queries[i][0];
        int r=queries[i][1];
        diff[l]++;
        if(r+1<n)
        diff[r+1]--;
}
vector<int>ops(n,0);
ops[0]=diff[0];
for(int i=1;i<n;i++){
    ops[i]=ops[i-1]+diff[i];

}
for(int i=0;i<n;i++){
    if(ops[i]<nums[i])
    return false;
}
return true;
}
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
      int m=queries.size();
      vector<bool>used(m,true);
      if(!ispossible(nums,queries,used))
      return -1;
      int removed=0;
      for(int i=0;i<m;i++){
           used[i]=false;
      if(ispossible(nums,queries,used)){
        removed++;
}else{
    used[i]=true;

}   
      }    
return removed;
    }
    
};