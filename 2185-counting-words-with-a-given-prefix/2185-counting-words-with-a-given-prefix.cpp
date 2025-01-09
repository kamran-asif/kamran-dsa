class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt=0;
        for(auto word:words){
            bool isprefix=true;
            for(int i=0;i<pref[i];i++){
            if(word[i]!=pref[i]){
            isprefix=false;
            break;
        }
    }
    if(isprefix==true)
    cnt++;
        }
    
    return cnt;
    }
};