class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        while(low<high){
            int mid=low+(high-low)/2;
            //agar mid element high se chhota hai, toh min left side me ho sakta hai including mid
            if(nums[mid]<nums[high]){
                high=mid;
                 //agar mid element bada hai, toh min right side me hoga (exclude mid)
            }else if(nums[mid]>nums[high]){
             low=mid+1;
              //jb equal ho jaye mid and high, toh sure nahi ho sakte so high ko ek step kam kar do
            }else{
                high--;//duplicates ko eliminate karne ke liye
            }
        }
        // jb loop khatam hoga, low pe min element milega
        return nums[low];
    
    }
};