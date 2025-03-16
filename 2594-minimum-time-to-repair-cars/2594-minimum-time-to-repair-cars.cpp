class Solution {

        #define ll long long

    bool canAssign(vector<int>& ranks, ll mid, int cars){
        ll count=0;
        for (ll rank:ranks){
            count+=sqrt(mid/rank);
        }
        return count>=cars;
    }

public:
     long long repairCars(vector<int>& ranks, int cars){
        ll n=ranks.size();
        ll low=1;//for 1 car and 1 rank
        ll high=(*min_element(ranks.begin(),ranks.end()))*(ll)cars*cars;

        ll ans;
        while (low<=high){
            ll mid=low+(high-low)/2;
            if (canAssign(ranks,mid,cars)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
   