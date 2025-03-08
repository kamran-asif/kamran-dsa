class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int, int>> diff;
    
    // Calculate the absolute difference and store in the vector
    for(int i = 0; i < arr.size(); i++) {
        diff.push_back({abs(x - arr[i]), arr[i]});
    }
    
    // Sort the vector by absolute difference first, and element value second
    sort(diff.begin(), diff.end());
    
    // Extract the first k elements
    vector<int> result;
    for(int i = 0; i < k; i++) {
        result.push_back(diff[i].second);
    }
    
    // Sort the result to match the order in the input array
    sort(result.begin(), result.end());
    
    return result;


    }
};