class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
     sort(nums.begin(),nums.end());
     vector<int>sortednums=nums;
     int mid=(n-1)/2;
        int end=n-1;
     for(int i=0;i<n;i++){
        nums[i]=(i%2==0)?sortednums[mid--]:sortednums[end--];

     }   
    }
};