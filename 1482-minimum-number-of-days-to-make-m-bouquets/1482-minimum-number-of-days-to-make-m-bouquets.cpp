class Solution {
public:
//return the no of mzm bouquets that can be made on day mid
int getnumberofbouquets(vector<int>&bloomday,int mid,int k){
    int numofbouquets=0;
    int cnt=0;
    for(int i=0;i<bloomday.size();i++){
        if(bloomday[i]<=mid){
            cnt++;

        }else{
            cnt=0;
        }
        if(cnt==k){
            numofbouquets++;
            cnt=0;
        }
    }
    return numofbouquets;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
     int start=0;
     int end=0;
     for(int day:bloomDay){
        end=max(end,day);

     }       
     int mindays=-1;
     while(start<=end){
        int mid=(start+end)/2;
        if(getnumberofbouquets(bloomDay,mid,k)>=m){
            mindays=mid;
             end=mid-1;
        }else{
          start=mid+1;
        }
     } 
return mindays;
    }
};