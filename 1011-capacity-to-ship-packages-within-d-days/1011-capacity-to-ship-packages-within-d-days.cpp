class Solution {
public:
int finddays(vector<int>&weights,int cap){
    int days=1;
    int load=0;
    int n=weights.size();
    for(int i=0;i<n;i++){
        if(weights[i]+load>cap){
            days+=1;
            load=weights[i];
        }else{
            load+=weights[i];
        }
    }
    return days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            int noofdays=finddays(weights,mid);
            if(noofdays<=days){
            high=mid-1;
            }else{
            low=mid+1;
        }
        }
        return low;
    }
};