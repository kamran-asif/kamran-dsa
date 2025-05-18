class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n + 1, 0); // prfix[i]=cnt of vowel strngs in words[0..i-1]

        for (int i = 0; i < n; ++i) {
            string& word = words[i];
            // chck if wrd strts and ends with a vwel
            if (isVowel(word.front()) && isVowel(word.back())) {
                prefix[i + 1] = prefix[i] + 1;
            } else {
                prefix[i + 1] = prefix[i];
            }
        }

        vector<int> result;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            result.push_back(prefix[r + 1] - prefix[l]);
        }

        return result;
    }
};
   
    