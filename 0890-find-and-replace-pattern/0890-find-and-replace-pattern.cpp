class Solution {
public:
bool ismatch(string &word, string &pattern){
            if(word.length()!=pattern.length())
            return false;
           unordered_map<char,char>mp1;
           unordered_map<char,char>mp2;
           int n=word.length();
           for(int i=0;i<n;i++){
            char w=word[i];
            char p=pattern[i];
            if(mp1.find(w)!=mp1.end()&&mp1[w]!=p){
                return false;
            }
            if(mp2.find(p)!=mp2.end()&&mp2[p]!=w){
                return false;
            }
            mp1[w]=p;
            mp2[p]=w;
           }
return true;

}
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
       vector<string>ans; 
          for(string word:words){
            if(ismatch(word,pattern)){
                ans.push_back(word);
            }
          }
    return ans;
    }
};