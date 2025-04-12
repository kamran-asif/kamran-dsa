class Solution {
public:
    typedef long long ll;
    ll fact[11];

    void compute_factorials() {
        fact[0] = 1;
        for (int i = 1; i <= 10; ++i) {
            fact[i] = fact[i - 1] * i;
        }
    }

    string get_key(const vector<int>& count) {
        string key = "";
        for (int c : count) {
            key += to_string(c) + ",";
        }
        return key;
    }

    ll count_permutations(const vector<int>& count, int n) {
        ll total = fact[n];
        for (int i = 0; i < 10; ++i) {
            total /= fact[count[i]];
        }

        if (count[0] == 0) return total;

        vector<int> temp = count;
        temp[0]--;
        ll bad = fact[n - 1];
        for (int i = 0; i < 10; ++i) {
            bad /= fact[temp[i]];
        }

        return total - bad;
    }

    vector<int> generate_palindromes(int n) {
        vector<int> result;
        int half = (n + 1) / 2;
        int start = pow(10, half - 1);
        int end = pow(10, half);

        for (int i = start; i < end; ++i) {
            string s = to_string(i);
            string rev = s;
            if (n % 2 == 1) rev.pop_back();
            reverse(rev.begin(), rev.end());
            int num = stoi(s + rev);
            result.push_back(num);
        }

        return result;
    }

    long long countGoodIntegers(int n, int k) {
        compute_factorials();
        unordered_set<string> seen;
        vector<int> pals = generate_palindromes(n);
        ll total = 0;

        for (int num : pals) {
            if (num % k != 0) continue;

            vector<int> count(10, 0);
            int temp = num;
            for (int i = 0; i < n; ++i) {
                count[temp % 10]++;
                temp /= 10;
            }

            string key = get_key(count);
            if (seen.count(key)) continue;
            seen.insert(key);

            total += count_permutations(count, n);
        }

        return total;
    }
};
