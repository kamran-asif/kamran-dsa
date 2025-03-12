class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int start=0,end=n-1;
        while (start<=end){
            int mid=start+(end-start)/2;
            if (nums[mid]==target) return true;
            // hndling duplicates
            if (nums[start]==nums[mid]&&nums[mid]==nums[end]){
                start++;
                end--;
                continue;
            }
            //if lft hlf is sorted
            if (nums[start] <= nums[mid]) {
                if(nums[start]<=target&&target<nums[mid]){
                    end=mid-1; // srch in lft hlf
                }else{
                    start=mid+1; // srch in rght hlf
                }
            }
            // right hlf is srted
            else{
                if(nums[mid]<target&&target<=nums[end]) {
                    start=mid+1; // srch in rght hlf
                }else{
                    end=mid-1; // srch in lft hlf
                }
            }
        }
       return false;
    }
};
