#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  
    int check(int mid, vector<int>& nums) {  
        int take = 0;      // kitne houses rob ho sakte hain, iska count rakhne ke liye
        int n = nums.size();  

        for (int i = 0; i < n; i++) {   // sare houses check karenge
            if (nums[i] <= mid) {   // agar house ki value mid se chhoti ya barabar hai
                i++;     // ek house skip karna hai, kyunki adjacent houses nahi le sakte
                take++;    // ek house rob kar liya
            }
        }
        return take;     // total kitne houses rob kiye, ye return karenge
    }

    int minCapability(vector<int>& nums, int k) {
        int l = 1;  
        int r = pow(10, 9);  
        int ans = -1;        // answer ko initially -1 mark krenge

        while (l <= r) {  
            int mid = l + (r - l) / 2;

            if (check(mid, nums) >= k) {     // agar mid value se k ya zyada houses rob ho skte hai
                ans = mid;          // possible answr store krenge
                r = mid - 1;        // chhoti value dhondhenge to kam capability me kam ho ske
            } else {  
                l = mid + 1;         // nhi ho ska, to bdi value try karenge
            }
        }
        return ans;  
    }
};
