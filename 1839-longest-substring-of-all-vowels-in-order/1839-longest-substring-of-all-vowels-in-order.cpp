class Solution {
public:
//revisit
    int longestBeautifulSubstring(string word) {
       
        int n = word.size();
        int maxLen = 0, i = 0;
        
        while (i < n) {
            // Start of a valid substring
            if (word[i] == 'a') {
                int j = i;
                unordered_set<char> st;
                st.insert(word[j]);
                
                // Move the pointer while it's sorted in increasing order
                while (j + 1 < n && word[j] <= word[j + 1]) {
                    st.insert(word[j + 1]);
                    j++;
                }
                
                // Check if it contains all 5 vowels
                if (st.size() == 5) {
                    maxLen = max(maxLen, j - i + 1);
                }
                
                // Move i to the next possible start
                i = j;
            }
            i++;
        }

        return maxLen;
    }
};
    