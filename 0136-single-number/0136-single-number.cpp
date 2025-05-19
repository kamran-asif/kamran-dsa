class Solution {
public:
    int singleNumber(vector<int>&nums){
        unordered_map<int,int>hashMap;
        for(int num:nums){
        hashMap[num]++; // count occurrences
        }
        for(auto&pair:hashMap){
            if (pair.second==1) return pair.first; // return the unique number
        }
        return -1; // should never reach here
    }
};
