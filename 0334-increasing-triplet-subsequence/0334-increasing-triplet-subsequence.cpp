class Solution {
public://revisit
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int>lis;
        for(int i=0;i<n;i++){
            int lb=lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
            if(lb==lis.size()){
                lis.push_back(nums[i]);
                }else{
                lis[lb]=nums[i];
            }
            
        }
        return lis.size()>=3;
    }
};