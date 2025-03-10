
class Solution {
public:
    // helper function to find the longest substring
    int longestsubstringhlpr(string &s, int start, int end, int &k) {
        // base case: if the window size is less than k, no valid substring
        if (end - start < k) return 0;

        // frequency array to count character occurrences
        vector<int> freq(26, 0);
        for (int i = start; i < end; i++) {
            freq[s[i] - 'a']++;
        }

        // traverse the current substring
        for (int i = start; i < end; i++) {
            // if the frequency of the current character is less than k, split the substring
            if (freq[s[i] - 'a'] > 0 && freq[s[i] - 'a'] < k) {
                // split the substring and solve for both halves
                int leftPart = longestsubstringhlpr(s, start, i, k);
                int rightPart = longestsubstringhlpr(s, i+1, end, k);
                return max(leftPart, rightPart);
            }
        }

        //if all characters satisfy the condition, return the current substring length
        return end - start;
    }

    int longestSubstring(string s, int k) {
        int n = s.size();
        return longestsubstringhlpr(s, 0, n, k);
    }
};