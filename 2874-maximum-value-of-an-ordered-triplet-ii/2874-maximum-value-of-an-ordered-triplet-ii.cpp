class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
          int n = nums.size();
    if (n < 3) return 0;

    vector<int> prefix_max(n, 0), suffix_max(n, 0);
    
    // Compute prefix max
    prefix_max[0] = nums[0];
    for (int i = 1; i < n; i++) {
        prefix_max[i] = max(prefix_max[i - 1], nums[i]);
    }
    
    // Compute suffix max
    suffix_max[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffix_max[i] = max(suffix_max[i + 1], nums[i]);
    }
    
    int max_value = 0;
    
    // Iterate through the middle element j
    for (int j = 1; j < n - 1; j++) {
        if (prefix_max[j - 1] > nums[j] && suffix_max[j + 1] > 0) {
            max_value = max(max_value, (prefix_max[j - 1] - nums[j]) * suffix_max[j + 1]);
        }
    }
    
    return max_value;
}
};