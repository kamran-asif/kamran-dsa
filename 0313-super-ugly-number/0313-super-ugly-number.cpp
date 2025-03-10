
class Solution {
public://using min heap approach dp with pntr tle de rha ugly no variant acha swal h
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n);
        dp[0] = 1;
        int m = primes.size();
        
        // min-Heap to get the next minimum ugly number efficiently
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        // store (value, prime_index)
        for(int i = 0; i < m; i++) {
            pq.push({primes[i], i});
        }
        
        vector<int> pointers(m, 0);

        for(int i = 1; i < n; i++) {
            // get the next smallest ugly number from the heap
            dp[i] = pq.top().first;
            
            // update all pointers whose value matches the top of heap
            while(!pq.empty() && pq.top().first == dp[i]) {
                int prime_index = pq.top().second;
                pq.pop();
                
                // move the pointer forward and push the new ugly number
                pointers[prime_index]++;
                pq.push({(long long)dp[pointers[prime_index]] * primes[prime_index], prime_index});
            }
        }

        return dp[n-1];
    }
};
