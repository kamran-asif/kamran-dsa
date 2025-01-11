class Solution {
public:
bool issubset(vector<int>&freq2,vector<int>&temp){
    
}
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>result;
        vector<int>frreq2(26);
        for(string &word:words2){
            int temp[26]={0};
            for(char &ch:word){
                temp[ch-'a']++;
                freq2[ch-'a']=max(freq2[ch-'a'],temp[ch-'a']);
            }
        }
    for(string &word:words1){
        vector<int>temp(26,0);
        for(char  &ch:word){
            temp[ch-'a']++;
        }
        if(issubset(freq2,temp)==true){
            result.push_back(word);

        }
    }
    return result;
    }

};