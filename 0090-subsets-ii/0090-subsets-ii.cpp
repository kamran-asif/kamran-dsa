class Solution {
public:
void backtrack(int start,vector<int>&nums,vector<int>&current,vector<vector<int>>&result){
    result.push_back(current);
    for(int i=start;i<nums.size();i++){
        //duplicates skipping
        if(i>start&&nums[i]==nums[i-1])continue;
        current.push_back(nums[i]);//include nums[i]
        backtrack(i+1,nums,current,result);//recurse
        current.pop_back();//backtrack
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>current;
        sort(nums.begin(),nums.end());//to handle duplicates
        backtrack(0,nums,current,result);//bcktrckng
        return result;
    }
};