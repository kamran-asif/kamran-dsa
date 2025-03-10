
class Solution {
public:

    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
      int countVowelSubstrings(string word) {
        int n = word.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            unordered_set<char> st;

            for (int j = i; j < n; ++j) {
                if (isVowel(word[j])) {
                    st.insert(word[j]);
                    if (st.size() == 5) {
                        count++;
                    }
                } else {
                    break;
                }
            }
        }

        return count;
    }
};
