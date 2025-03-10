class Solution {
public:// yha dp with min heap ni hoga kyuki conyraint zda h
    

    // function to calculate GCD
    long long gcd(long long a, long long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    // function to calculate LCM
    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    // function to count how many ugly numbers <= mid
    long long count(long long mid, long long a, long long b, long long c) {
        long long ab = lcm(a, b);
        long long bc = lcm(b, c);
        long long ac = lcm(a, c);
        long long abc = lcm(a, bc);

        return (mid / a) + (mid / b) + (mid / c)
             - (mid / ab) - (mid / bc) - (mid / ac)
             + (mid / abc);
    }

 int nthUglyNumber(int n, int a, int b, int c) {
        long long low = 1, high = 2 * 1e9;
        long long ans = 0;
        
        // apply binary search
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (count(mid, a, b, c) >= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};

