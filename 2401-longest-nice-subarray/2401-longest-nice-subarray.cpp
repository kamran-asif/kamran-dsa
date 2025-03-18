class Solution {
public://sliding window
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=0;
        int max_window=0;
        int xor_sum=0;
        int curr_sum=0;
        while(right<n){
            curr_sum+=nums[right];
            xor_sum^=nums[right];
            while(xor_sum!=curr_sum){
                curr_sum-=nums[left];
                xor_sum^=nums[left];
                 left++;
            }
            max_window=max(max_window,right-left+1);
            right++;
        }
        return max_window;
    }
};