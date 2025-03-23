
class Solution {
public:
    unordered_map<long long, int> memo; // Use long long for memoization keys

    int integerReplacement(long long n) { // Use long long to prevent overflow
        if (n == 1) return 0; // Base case

        if (memo.count(n)) return memo[n]; // Check memoization

        if (n % 2 == 0) {
            return memo[n] = 1 + integerReplacement(n / 2); // If even, divide by 2
        } else {
            return memo[n] = 1 + min(integerReplacement(n - 1), integerReplacement(n + 1)); // If odd, try both n-1 and n+1
        }
    }
};

