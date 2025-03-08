class Solution {
public://revisit
    bool checkInclusion(string s1, string s2) {
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        for(char c:s1){
           freq1[c-'a']++;
           
        
        }
        int windowsize=s1.length();
        for(int i=0;i<s2.length();i++){
            freq2[s2[i]-'a']++;
            if(i>=windowsize)
            {
              freq2[s2[i-windowsize]-'a']--;
            }
            if(freq1==freq2)return true;
            
                    }
                    return false;
    }
};