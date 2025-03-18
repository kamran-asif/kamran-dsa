class Solution {
public://good question
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>answer(n,1);
        vector<int>lastseen(32,-1);
        for(int i=n-1;i>=0;i--){
            for(int bit=0;bit<32;bit++){
                if(nums[i]&(1<<bit)){
                    lastseen[bit]=i;
                }
            }
            int farthest=i;
            for(int bit=0;bit<32;bit++){
                if(lastseen[bit]!=-1){
                    farthest=max(farthest,lastseen[bit]);
                }
            }
            answer[i]=farthest-i+1;
        }
        return answer;
    }
};