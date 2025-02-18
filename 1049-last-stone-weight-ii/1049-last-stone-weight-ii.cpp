

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total = accumulate(stones.begin(), stones.end(), 0);
        int target = total / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int stone : stones) { 
            for (int j = target; j >= stone; --j) {
                if (dp[j - stone]) {
                    dp[j] = true;
                }
            }
        }
        for (int maxS2 = target; maxS2 >= 0; --maxS2) {
            if (dp[maxS2]) {
                return total - 2 * maxS2;
            }
        }

        return total;
    }
};

