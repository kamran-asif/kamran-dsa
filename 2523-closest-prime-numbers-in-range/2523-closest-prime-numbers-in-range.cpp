class Solution {
public://sieve of erath
    vector<int> closestPrimes(int left, int right) {
     int limit=right;
     vector<bool>isprime(limit+1,true) ;
     isprime[0]=isprime[1]=false;
     for(int i=2;i*i<=limit;i++){
        if(isprime[i]){
            for(int j=i*i;j<=limit;j+=i){
              isprime[j]=false;
            }
        }
     }
     vector<int>prime;
     for(int i=left;i<=right;i++){
         if(isprime[i]){
            prime.push_back(i);

         }
     }
     if(prime.size()<2)return{-1,-1};
        int mingap=INT_MAX;
        vector<int>result={-1,-1};
        for(int i=1;i<prime.size();i++){
            int gap=prime[i]-prime[i-1];
            if(gap<mingap){
                mingap=gap;
                result={prime[i-1],prime[i]};
            }
                   }
         return result;
    }
};