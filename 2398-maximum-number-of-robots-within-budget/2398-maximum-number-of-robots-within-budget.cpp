class Solution {
public:
    // check karte hain agar koi window of size k budget ke andar aa sakti hai
    bool isValid(int k,vector<int>&chargeTimes,vector<int>& runningCosts,long long budget){
        deque<int>dq;           // indices of potential maxima, front = max chargeTime
        long long runSum=0;    // sum of runningCosts in current window
        int n=chargeTimes.size();
        
        for (int i=0;i<n;i++){
            runSum+=runningCosts[i];// add new robot ka running cost
            
            // maintain deque monotonic decreasing by chargeTimes
            while(!dq.empty()&&chargeTimes[dq.back()]<=chargeTimes[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            
            // jab window size exceed kare k, toh slide window
            if (i>=k){
                //remove running cost of robot going out of window
                runSum-=runningCosts[i-k];
                // Remove from deque if it was the max at front
                if(dq.front()==i-k){
                    dq.pop_front();
                }
            }
            
            // jab window size exactly ho jaye k, tab cost check karo
            if (i>=k-1){
                long long maxCharge=chargeTimes[dq.front()];
                long long totalCost=maxCharge+(long long)k*runSum;
                if (totalCost<=budget){
                    return true;  // mil gaya ek valid window
                }
            }
        }
        
        return false;
    }

    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n=chargeTimes.size();
        int low=0,high=n,ans=0;
        
        // binary search on window size k
        while (low<=high){
            int mid=low+(high-low)/2;
            if (mid>0&&isValid(mid,chargeTimes,runningCosts,budget)){
                ans=mid;           // mid possible hai
                low=mid+1;       // aur bada try karo
            }else{
                high=mid-1;      // mid nahi hua, chota try karo
            }
        }
        
        return ans;
    }
};
