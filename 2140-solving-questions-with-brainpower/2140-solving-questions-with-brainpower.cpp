class Solution {
public:
  
  // recursive function with memoization to find max points
  long long findMaxPoints(vector<vector<int>>& questions, int pos, vector<long long>& mem) {
        if (pos >= questions.size())  // base case: out of bounds
            return 0;
        
        if (mem[pos] != -1)  // return if already computed
            return mem[pos];

        long long exclude = findMaxPoints(questions, pos + 1, mem); // skip
        long long include = questions[pos][0] + findMaxPoints(questions, pos + questions[pos][1] + 1, mem); // take

        return mem[pos] = max(exclude, include); // store result
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> mem(n, -1); // dp table
        return findMaxPoints(questions, 0, mem); // start from 0
    }
};
