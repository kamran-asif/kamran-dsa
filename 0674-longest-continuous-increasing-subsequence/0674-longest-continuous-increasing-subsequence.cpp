class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        if(nums.empty())return 0;
        int maxln=1,crrln=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                crrln++;
            }else{
                crrln=1;
            }
            maxln=max(maxln,crrln);
        }
        return maxln;
    }
};