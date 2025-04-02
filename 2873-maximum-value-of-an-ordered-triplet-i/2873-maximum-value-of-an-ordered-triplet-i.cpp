class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
    int n = nums.size();
    int maxVal = 0;
    
    int leftMax = nums[0];
    vector<int> suffixMax(n);
    
    suffixMax[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suffixMax[i] = max(suffixMax[i + 1], nums[i]);
    }
    
    for (int j = 1; j < n - 1; ++j) {
        leftMax = max(leftMax, nums[j - 1]);
        int rightMax = suffixMax[j + 1];
        
        int value = (leftMax - nums[j]) * rightMax;
        maxVal = max(maxVal, value);
    }
    
    return maxVal;
}
    
};