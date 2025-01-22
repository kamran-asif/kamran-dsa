class Solution {
public:
    unordered_set<string>st;
    int t[301];
    bool solve(int idx,string &s){
        int n=s.size();

        if(idx>=n){
          return true;

        } 
        if(t[idx]!=-1)
        return t[idx];
        if(st.find(s)!=st.end())
        return t[idx]=true;

        for(int l=0;l<=n;l++){
            string temp=s.substr(idx,l);
            if(st.find(temp)!=st.end()&& solve(idx+l,s)){
                return t[idx]= true;
            }
        }
        return t[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        
          for (int i = 0; i < sizeof(t) / sizeof(t[0]); i++) {
    t[i] = -1;
}

        for(string &word:wordDict){
               st.insert(word);
        }
        return solve(0,s);
    }
};