class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
         unordered_map<int, int> hashMap;
    
    for (const auto& pair : nums1) {
        hashMap[pair[0]] += pair[1];
    }
    
    for (const auto& pair : nums2) {
        hashMap[pair[0]] += pair[1];
    }
    
    vector<vector<int>> result;
    for (const auto& entry : hashMap) {
        result.push_back({entry.first, entry.second});
    }
    
    sort(result.begin(), result.end());
    return result;
    }
};