class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>globalset;
        unordered_set<int>currentset;
        for(int num:arr){
            unordered_set<int>newset;
            newset.insert(num);
            for(int val:currentset){
                newset.insert(val|num);
            }
            currentset=newset;
            globalset.insert(currentset.begin(),currentset.end());
        }
        return globalset.size();
    }
};