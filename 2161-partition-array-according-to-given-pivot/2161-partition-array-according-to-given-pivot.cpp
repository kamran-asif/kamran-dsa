class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> result;
        
        // First, add elements smaller than pivot
        for (int num : nums) {
            if (num < pivot) result.push_back(num);
        }

        // Then, add elements equal to pivot
        for (int num : nums) {
            if (num == pivot) result.push_back(num);
        }

        // Finally, add elements greater than pivot
        for (int num : nums) {
            if (num > pivot) result.push_back(num);
        }

        return result;
    }
};
