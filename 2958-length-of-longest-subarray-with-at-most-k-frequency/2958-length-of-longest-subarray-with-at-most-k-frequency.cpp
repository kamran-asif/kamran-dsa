class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int i = 0, j = 0, result = 0, culprit = 0;

        while (j < n) {
            mp[nums[j]]++; // current element ka frequency badhao
            if (mp[nums[j]] == k + 1) { // agar koi element k se zyada baar aagaya
                culprit++; // invalid element mil gaya
            }

            while (culprit > 0) { // agar invalid element hai to window chhoti karo
                mp[nums[i]]--; // leftmost element ka frequency kam karo
                if (mp[nums[i]] == k) { // agar culprit remove ho gaya
                    culprit--; // culprit count kam karo
                }
                i++; // left pointer aage badhao
            }

            result = max(result, j - i + 1); // max subarray length update karo
            j++; // right pointer aage badhao
        }
        
        return result;
    }
};
