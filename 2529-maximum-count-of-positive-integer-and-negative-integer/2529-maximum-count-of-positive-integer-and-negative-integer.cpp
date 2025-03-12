class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        
        int left = 0, right = n - 1, posindx = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > 0) {
                posindx = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        left = 0, right = n - 1;
        int negindx = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < 0) {
                negindx = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        int poscnt = n - posindx; 
        int negcnt = negindx + 1; 

        return max(poscnt, negcnt);
    }
};