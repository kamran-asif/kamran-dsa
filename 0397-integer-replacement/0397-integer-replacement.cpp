
class Solution {
public:
    unordered_map<long long, int> memo;

    int integerReplacement(long long n) {
        if (n == 1) return 0; // base case

        if (memo.count(n)) return memo[n]; // check memoization

        if (n % 2 == 0) {
            return memo[n] = 1 + integerReplacement(n / 2); // if even, divide by 2
        } else {
            return memo[n] = 1 + min(integerReplacement(n - 1), integerReplacement(n + 1)); // if odd, try both n-1 and n+1
        }
    }
};

