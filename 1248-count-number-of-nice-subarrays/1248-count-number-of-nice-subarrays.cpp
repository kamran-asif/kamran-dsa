class Solution{
    public:
int numberOfSubarrays(vector<int>& nums, int k) {
    if (k < 0) return 0;
    int left = 0, right = 0, sum = 0, count = 0;
    int n = nums.size();
    while (right < n) {
        sum += (nums[right] % 2); // increment sum by 1 if the number is odd
        while (sum > k) {
            sum -= (nums[left] % 2); // shrink window until `sum <= k`
            left++;
        }
        if (sum == k) {
            int temp = left;
            while (temp <= right && nums[temp] % 2 == 0) {
                temp++; // count the number of even numbers at the start of the subarray
            }
            count += (temp - left + 1); // add all possible valid subarrays
        }
        right++;
    }
    return count;
}
};
