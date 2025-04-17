class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, vector<int>> idxMap;

        // Store indices for each number
        for (int i = 0; i < nums.size(); i++) {
            idxMap[nums[i]].push_back(i);
        }

        // Iterate over each group of indices
        for (auto& entry : idxMap) {
            vector<int>& items = entry.second;
            unordered_map<int, int> gcdCount;

            for (int index : items) {
                int gcd_i_k = gcd(index, k);
                for (auto& pair : gcdCount) {
                    int gcd_j_k = pair.first;
                    int count_j = pair.second;
                    if ((1LL * gcd_i_k * gcd_j_k) % k == 0) {
                        count += count_j;
                    }
                }
                gcdCount[gcd_i_k]++;
            }
        }
        return count;
    }
};