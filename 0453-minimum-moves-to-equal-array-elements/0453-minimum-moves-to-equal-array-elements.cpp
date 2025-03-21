class Solution {
public:
    int minMoves(vector<int>& nums) {
           int minVal = *min_element(nums.begin(), nums.end()); // Find minimum element
        int moves = 0;
        
        for (int num : nums) {
            moves += (num - minVal); 
        }
        
        return moves;
    }
};