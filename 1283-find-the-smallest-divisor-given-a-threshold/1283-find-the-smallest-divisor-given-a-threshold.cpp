class Solution {
public:
        int computesum(const vector<int>& nums, int divisor) {
        int sum=0;
        for(int num:nums){
            //ciel division k mtlb h hmesha uppr ki trf round krna
            //sum+=(num+divisor-1)/divisor=ceil(num/divisor)without using float;
            sum+=(num+divisor-1)/divisor;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
     int left=1;//min possible divisor
     int right=*max_element(nums.begin(),nums.end());//max element tk hi sense bnta h divisor k
      int result=right;//initial answer assume krlete h max value
      while(left<=right){
        int mid=left+(right-left)/2;//mid divisor nkal rhe h
        int currentsum=computesum(nums,mid);
        if(currentsum<=threshold){
            result=mid;
            right=mid-1;//aur chota divisor try kro
        }else{
            //sum agr threshold s zda h to bda divisor
            left=mid+1;
        }
      }
      return result;//sbse chota return krna h valid divisor
    }
};