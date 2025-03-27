class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
    int maxLeft = nums[0], globalMax = nums[0], partitionIdx = 0;
    
    for (int i = 1; i < n; i++) {
        if (nums[i] < maxLeft) {
            partitionIdx = i;
            maxLeft = globalMax; 
        } else {
            globalMax = max(globalMax, nums[i]);
        }
    }
    
    return partitionIdx + 1;
    }
};