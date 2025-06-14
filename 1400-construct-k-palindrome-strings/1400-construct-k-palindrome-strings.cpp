class Solution {
public:
    bool canConstruct(string s, int k) {
         // agar total characters hi k se kam hain, to k alag strings banana possible nahi
        if (s.length() < k) return false;

        unordered_map<char, int> freq;
        // sabhi characters ka frequency count nikal lo
        for (char c : s) {
            freq[c]++;
        }

        int oddCount = 0;
        // count karo kitne characters ka frequency odd hai
        for (auto& pair : freq) {
            if (pair.second % 2 != 0) {
                oddCount++;
            }
        }

        // agar odd character count > k ho gaya, to possible nahi
        return oddCount <= k;
    
    }
};