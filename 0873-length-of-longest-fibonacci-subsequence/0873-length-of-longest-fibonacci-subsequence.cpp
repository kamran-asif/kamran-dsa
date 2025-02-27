
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        vector<vector<int>> t(n, vector<int>(n, 2));
        // t[j][k] = length of the longest Fibonacci-like subsequence that ends at indices j and k in the array arr.

        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }
        
        int max_length = 0;
        for (int j = 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int target = arr[k] - arr[j];
                if (mp.count(target) && mp[target] < j) {
                    int i = mp[target];
                    t[j][k] = t[i][j] + 1;
                }
                max_length = max(max_length, t[j][k]);
            }
        }
        return max_length >= 3 ? max_length : 0;
    }
};
