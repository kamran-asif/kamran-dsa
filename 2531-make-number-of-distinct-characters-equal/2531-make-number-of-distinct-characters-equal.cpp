class Solution {
public:
    bool isItPossible(string word1, string word2) {

        unordered_map<char, int> mp1, mp2;
        for (char ch : word1) mp1[ch]++;
        for (char ch : word2) mp2[ch]++;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                char ch1 = i + 'a', ch2 = j + 'a';

                // ensure both characters exist in their respective words before swapping
                if (mp1.count(ch1) && mp2.count(ch2)) {
                    
                    // remove one occurrence of the characters to simulate a swap
                    if (--mp1[ch1] == 0) mp1.erase(ch1);
                    if (--mp2[ch2] == 0) mp2.erase(ch2);

                    // swap the characters
                    mp1[ch2]++;
                    mp2[ch1]++;

                    // check if both words have the same number of distinct characters
                    if (mp1.size() == mp2.size()) return true;

                    // revert the swap to restore the original frequency state
                    if (--mp1[ch2] == 0) mp1.erase(ch2);
                    if (--mp2[ch1] == 0) mp2.erase(ch1);
                    mp1[ch1]++;
                    mp2[ch2]++;
                }
            }
        }

        return false;
    }
};
