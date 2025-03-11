class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s); //tokenize the string
        string token;
        int countwords = 0; //
        //tokenize kr rhe hai 
        //getline krlya kispr chla rhe hai ss pr chla rhe hai or jo bhi token milega usko token m store krlenge split space k hisab s krna hai
        while (getline(ss, token, ' ')) {
            words.push_back(token); //token ko dal rhe hai
            countwords++;
        }
        int n = pattern.length();
        if (n != countwords) //agr pattern k length count wrds k brabr ni hai to false
            return false;
        
        unordered_map<string, char> mp;
        unordered_set<char> used; // corrected from set to unordered_set
        for (int i = 0; i < n; i++) {
            string word = words[i];
            char ch = pattern[i];
            //word ye kbhi use hi ni hua or chck kro ki set m bhi ye word ni hona chaye agr aisa hai to daldo set m
            if (mp.find(word) == mp.end() && used.find(ch) == used.end()) {
                used.insert(ch); //set m aise dalte hai 
                mp[word] = ch; //map m aise dalte hai
            } 
            else if (mp.find(word) == mp.end() || mp[word] != ch) { // corrected logic for mismatch
                return false;
            }
        }
        return true;
    }
};
