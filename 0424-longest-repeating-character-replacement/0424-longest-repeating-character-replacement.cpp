class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);  // stores character frequencies
        int maxFreq = 0, i = 0, maxLength = 0;

        for (int j = 0; j < s.length(); j++) {
            freq[s[j] - 'A']++;  
            maxFreq = max(maxFreq, freq[s[j] - 'A']);  // max repeating char in window

            // if non-max chars > k, shrink window
            while ((j - i + 1) - maxFreq > k) {  
                freq[s[i] - 'A']--;  
                i++;  
            }

            maxLength = max(maxLength, j - i + 1);  // update max length
        }

        return maxLength;
    }
};
