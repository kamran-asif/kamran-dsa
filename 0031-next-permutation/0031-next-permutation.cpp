class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i, j;

        //find the first dcreasing elment frm the right
        for (i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) break;
        }

        // if found, find the nxt lrger elment and swap
        if (i >= 0) { 
            for (j = n - 1; j > i; j--) {
                if (nums[j] > nums[i]) break;
            }
            swap(nums[i], nums[j]);
        }

        // rvrse the sffix to get the next permutation
        reverse(nums.begin() + i + 1, nums.end());
    }
};
