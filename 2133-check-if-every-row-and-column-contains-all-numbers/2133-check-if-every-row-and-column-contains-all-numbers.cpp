class Solution{ 
public:

bool checkValid(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<unordered_set<int>> rows(n), cols(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rows[i].insert(matrix[i][j]);  // ✅ Insert into the correct row
            cols[j].insert(matrix[i][j]);  // ✅ Insert into the correct column
        }
    }

    // ✅ Check each row and column separately after inserting all elements
    for (int i = 0; i < n; i++) {
        if (rows[i].size() != n || cols[i].size() != n) {  
            return false;
        }
    }
    
    return true;
}

int main() {
    vector<vector<int>> matrix1 = {{1, 2, 3}, {3, 1, 2}, {2, 3, 1}};
    vector<vector<int>> matrix2 = {{1, 1, 1}, {1, 2, 3}, {1, 2, 3}};

    cout << (checkValid(matrix1) ? "true" : "false") << endl; 
    cout << (checkValid(matrix2) ? "true" : "false") << endl; 

    return 0;
}
};
