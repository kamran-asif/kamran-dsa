class Solution {
public:// 1st approach map m dal denge occurences ko or cnt krlenge ;key m arr k no hoga or value m occrncs
//uske baad set m daldenge occrnse ko agr unique hua to true ni to false 
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        //map m value daal rhe hai array s 
        for(int &x: arr){
            mp[x]++;
        }
        unordered_set<int>st;
        //map s set m daal rhe hai 
        for(auto &it: mp){

            int freq=it.second;//it.first me number hoga
            // check kr rhe hai ki freq agr same nhi hai to
            if(st.find(freq)!=st.end())
                return false;
                st.insert(freq);//set m freq daldo
            
          
        }
          return true;
    }
};