class Solution {
public:
       const int MOD = 1e9 + 7;
    vector<vector<long long>> comb;//to store binomial coeef(ncr)

    void buildComb(int n) {
        comb = vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0));
        //cmputing ncr values
        //base case ic0==ici=1
        for (int i = 0; i <= n; ++i) {
            comb[i][0] = comb[i][i] = 1;
            //using pascal triangle rule
            //icj=(i-1cj-1)+(i-1cj)
            for (int j = 1; j < i; ++j) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }
    }
//if the size is 0, 1, or 2, there's only one way to arrnge them to fom the sme BST (no reordering or swapping needed)
    long long countWays(vector<int>& nums) {
        if (nums.size() <= 2) return 1;

        vector<int> left, right;
        /*first element nums[0] is the root.
     partition remaining elements into:
     left-all elements less than root (go to left subtree)
     right-all elements greater than root (go to right subtree)
*/

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        long long leftWays = countWays(left) % MOD;//recursively call
        long long rightWays = countWays(right) % MOD;//recuresively call

        long long waysToMerge = comb[left.size() + right.size()][left.size()];//(l+rcr)
        return (((waysToMerge * leftWays) % MOD) * rightWays) % MOD;/*Total number of          
BST-consistent reorderings is:
    interleavings×left-ways×right-ways
    multiply step-by-step and take modulo to avoid overflow.*/
    }
 int numOfWays(vector<int>& nums) {
        int n = nums.size();
        buildComb(n);  // precompute combinations
        return (countWays(nums) - 1 + MOD) % MOD;  // subtract original ordering
    }
};   
  