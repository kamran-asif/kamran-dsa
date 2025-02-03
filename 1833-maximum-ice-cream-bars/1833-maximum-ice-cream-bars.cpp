class Solution {
public:
// n ice bar,costs-array,length n,costs[i]-price of ith bar,coins,return max no of ice creambar boy buy with coin
    int maxIceCream(vector<int>& costs, int coins){
        int n=costs.size();
     sort(begin(costs),end(costs));
     int cnt=0 ; 
     for(auto & cost:costs){
          if(cost>coins){
              return cnt;
          }else{
            cnt++;
            coins-=cost;
          }
     } 
     return cnt;
    }
};