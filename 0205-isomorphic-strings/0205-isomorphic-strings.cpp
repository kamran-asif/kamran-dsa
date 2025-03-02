class Solution {
    public:
    

bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) return false;
    
    unordered_map<char, char> map;
    unordered_set<char> used;
    
    for (int i = 0; i < s.length(); i++) {
        char c1 = s[i], c2 = t[i];
        
        if (map.find(c1) != map.end()) {
            if (map[c1] != c2) return false;
        } else {
            if (used.find(c2) != used.end()) return false;
            
            map[c1] = c2;
            used.insert(c2);
        }
    }
    
    return true;
      
    }
};