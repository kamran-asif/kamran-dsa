class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    unordered_map<int, vector<int>> sizeToPeople;
    vector<vector<int>> result;

    // har person ko unke group size wale bucket me daalo
    for (int i = 0; i < groupSizes.size(); ++i) {
        int size = groupSizes[i];
        sizeToPeople[size].push_back(i);

        //agar group size ke barabar log ho gaye, toh group bana ke result me daal do
        if (sizeToPeople[size].size() == size) {
            result.push_back(sizeToPeople[size]);
            sizeToPeople[size].clear(); // us bucket ko reset kar do for next group
        }
    }

    return result; //final result return karo
}

    }
};