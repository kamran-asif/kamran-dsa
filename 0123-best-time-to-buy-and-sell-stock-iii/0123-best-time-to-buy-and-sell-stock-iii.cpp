class Solution {
public://divide and conquer technique
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0)return 0;
        vector<int>left(n,0),right(n,0);
        int lmin=prices[0];

   for(int i=1;i<n;i++){
              left[i]=max(left[i-1],prices[i]-lmin);
              lmin=min(lmin,prices[i]);
                
            }
          int rmax=prices[n-1];
        for(int i=n-2;i>=0;i--){
          right[i]=max(right[i+1],rmax-prices[i]);
          rmax=max(rmax,prices[i]);
        }
    int maxprofit=0;
    for(int i=0;i<n;i++){
        maxprofit=max(maxprofit,left[i]+right[i]);
    } 
    return maxprofit;
    }
};