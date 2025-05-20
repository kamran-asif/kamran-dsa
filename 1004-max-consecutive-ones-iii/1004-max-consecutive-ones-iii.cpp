class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,maxlen=0,zeroes=0;
        int len;
        while(r<nums.size()){
            if(nums[r]==0)
            zeroes++;
            if(zeroes>k){
                if(nums[l]==0)
                zeroes--;
                l++;
            }
            if(zeroes<=k)
             len=r-l+1;
         maxlen = max(maxlen, len);
            r++;
        }
        return maxlen;
    }
};