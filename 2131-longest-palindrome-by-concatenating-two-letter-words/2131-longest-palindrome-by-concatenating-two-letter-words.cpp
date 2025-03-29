
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> wordCount;
        
        for (string& word : words) {
            wordCount[word]++;
        }

        int length = 0;
        bool hasMiddle = false;

        for (auto& pair : wordCount) {
            string word = pair.first;
            int count = pair.second;

            string rev = {word[1], word[0]}; 

            if (word == rev) { 
                length += (count / 2) * 4;  
                if (count % 2 == 1) { 
                    hasMiddle = true;
                }
            } 
            else if (wordCount.count(rev)) { 
                int minPairs = min(count, wordCount[rev]);
                length += minPairs * 4;
                wordCount[rev] = 0; 
            }
        }

        if (hasMiddle) {
            length += 2;
        }

        return length;
    }
};
