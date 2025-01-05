class Solution {
    #define mod 1000000007
public:
    int uniqueLetterString(string s) {
        int n=s.size();
        vector<vector<int>>hashmap(26);
        for(int i=0;i<26;i++){
            hashmap[i].push_back(-1);

        }
        for(int i=0;i<n;i++)
        hashmap[s[i]-'A'].push_back(i);
        for(int i=0;i<26;i++)
        hashmap[i].push_back(n);
        long long count=0;
        for(int i=0;i<26;i++){
            for(int j=1;j<hashmap[i].size()-1;j++){
                count+=(hashmap[i][j]-hashmap[i][j-1])*(hashmap[i][j+1]-hashmap[i][j]);
                            }
        }
        return count;
    }
};