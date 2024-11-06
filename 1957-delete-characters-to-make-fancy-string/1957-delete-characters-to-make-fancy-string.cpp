class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        if (n == 0) return ""; // Handle empty string case

        string result = "";
        result.push_back(s[0]); // Add the first character
        int cnt = 1; // Initialize the count for the first character

        for (int i = 1; i < n; i++) {
            
            if (s[i] == result.back()) {
                                cnt++;
            if (cnt < 3) {
          
                result.push_back(s[i]);
            }
            }else {
                result.push_back(s[i]);
                cnt = 1;        
        }
        }
        return result;
    }
};
