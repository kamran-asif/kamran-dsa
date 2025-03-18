

class Solution {
public://good question
    bool canDistribute(const vector<int>& candies, long long k, int x) {
        long long count = 0;
        for (int c : candies) {
            count += (c / x);
        }
        return count >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        if (k > 1e12) return 0;  // Edge case: k is too large
        int low = 1, high = *max_element(candies.begin(), candies.end());
        int result = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;  // Fix typo: 'hight' → 'high'

            if (canDistribute(candies, k, mid)) {
                result = mid;  // Store the best possible answer
                low = mid + 1;  // Try to maximize X
            } else {
                high = mid - 1; // Try smaller X
            }
        }
        return result;
    }
};
