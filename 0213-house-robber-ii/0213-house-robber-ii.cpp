class Solution {
public:
    int n;
    
    int rob(vector<int>& nums) {
        n = nums.size();
        if(n == 1)
            return nums[0];
        
        vector<int> t(n+1, 0);
        //t[i] = max money gained from i houses
        
        int result1 = 0;
        int result2 = 0;
        
        //case-1 (take frm 1st hose skip the last house)
        t[0] = 0;
        for(int i = 1; i<=n-1; i++) {
            t[i] = max(t[i-1] , nums[i-1]+ ((i-2 >= 0) ? t[i-2] : 0 ));
        }
        result1 = t[n-1];
        
        t.clear();
        //case-2 (take from 2nd Hose take the last house)
        t[0] = 0;
        t[1] = 0;
        for(int i = 2; i<=n; i++) {
            t[i] = max(t[i-1] , nums[i-1]+ ((i-2 >= 0) ? t[i-2] : 0 ));
        }
        result2 = t[n];
        
        return max(result1, result2);
        
    }
};
