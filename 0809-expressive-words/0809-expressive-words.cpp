class Solution {
public:
   
vector<pair<char, int>> encode(const string &s) {
    vector<pair<char, int>> encoded;
    int n = s.size(), i = 0;
    
    while (i < n) {
        char ch = s[i];
        int count = 0;
        while (i < n && s[i] == ch) {
            count++;
            i++;
        }
        encoded.push_back({ch, count});
    }
    return encoded;
}

// function to check if a word can be stretched to match s
bool isStretchy(const string &s, const string &word) {
    vector<pair<char, int>> s_encoded = encode(s);
    vector<pair<char, int>> word_encoded = encode(word);
    
    if (s_encoded.size() != word_encoded.size()) return false;
    
    for (int i = 0; i < s_encoded.size(); ++i) {
        if (s_encoded[i].first != word_encoded[i].first) return false;
        int s_count = s_encoded[i].second;
        int w_count = word_encoded[i].second;
        
        if (s_count < w_count || (s_count != w_count && s_count < 3)) {
            return false;
        }
    }
    
    return true;
}

  int expressiveWords(string s, vector<string>& words) {
    int count = 0;
    for (const string &word : words) {
        if (isStretchy(s, word)) count++;
    }
    return count;
}
};