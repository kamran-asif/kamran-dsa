class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
         vector<string> stack; // to store the final words after removing anagrams
    
    for (const string& word : words) {
        if (!stack.empty()) {
            string lastWord = stack.back();
            string sortedLast = lastWord, sortedWord = word;
            sort(sortedLast.begin(), sortedLast.end());
            sort(sortedWord.begin(), sortedWord.end());

            if (sortedLast == sortedWord) {
                continue; // skip anagram words
            }
        }
        stack.push_back(word); // push non-anagram words
    }
    
    return stack;

   
    }
};