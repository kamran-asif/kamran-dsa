class Solution {
public://revisit
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int>lis;//simulate the longest increasing subsequence
        for(int i=0;i<n;i++){
            //find the 1st index of 1st element in lis which is not less than nums[i]
            //this is the posn where nums[i] can be placed to maintain sorted order
            int lb=lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
            if(lb==lis.size()){
                //if nums[i] is greater than all elements in'lis' which is not less than nums[i]
                //this is the posn where nums[i] can be placed to maintain sorted order
                lis.push_back(nums[i]);
                }else{
                lis[lb]=nums[i];
            }
            
        }
        //if we managed to build subsequence of length 3 return true
        // exist a subsequence of triplet subsequence
        return lis.size()>=3; 
    }
};