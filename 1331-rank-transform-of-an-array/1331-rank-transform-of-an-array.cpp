class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Create a copy of arr for sorting
        vector<int> sortedArr = arr;
        
        // Sort the copied array
        sort(sortedArr.begin(), sortedArr.end());
        
        // Map to store the rank of each unique element
        unordered_map<int, int> rankmap;
        int rank = 1;
        
        // Assign ranks to each unique element in sortedArr
        for (int num : sortedArr) {
            // If the number is not already in rankmap, assign it a rank
            if (rankmap.find(num) == rankmap.end()) {
                rankmap[num] = rank++;
            }
        }
        
        // Replace elements in the original array with their rank
        vector<int> result;
        for (int num : arr) {
            result.push_back(rankmap[num]);
        }
        
        return result;
    }
};
