
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> charcnt;
        
        for (char c : s) {
            charcnt[c]++;
        }
        
        int length = 0;
        bool oddfnd = false;
        
        for (auto& pair : charcnt) {
            int cnt = pair.second;
            if (cnt % 2 == 0) {
                length += cnt;
            } else {
                length += cnt - 1;
                oddfnd = true;
            }
        }
        
        if (oddfnd) {
            length += 1;
        }
        
        return length;
    }
};
