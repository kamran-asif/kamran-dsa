class Solution {
public:// 1st approach map m dal denge occurences ko or cnt krlenge ;key m arr k no hoga or value m occrncs
//uske baad set m daldenge occrnse ko agr unique hua to true ni to false 
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int &x: arr){
            mp[x]++;
        }
        unordered_set<int>st;
        for(auto &it: mp){
            int freq=it.second;//it.first me number hoga
            if(st.find(freq)!=st.end())
                return false;
                st.insert(freq);
            
          
        }
          return true;
    }
};