class Solution {
public:
    vector<string> result;
    void solve(int idx, string &digits, string &temp, unordered_map<char,string> &mp) {
        // base case: if we have generated a combination of required length
        if(idx >= digits.length()) {
            result.push_back(temp);
            return;
        }

        // current digit
        char ch = digits[idx];
        string str = mp[ch];  // get the corresponding letters for this digit

        // iterate through each letter mapped to the current digit
        for(int i = 0; i < str.length(); i++) {
            temp.push_back(str[i]);     // choose a character
            solve(idx+1, digits, temp, mp); // recursively go to the next digit
            temp.pop_back();            // backtrack (remove the last character)
        }
    }

    vector<string> letterCombinations(string digits) {
        // edge case: if digits is empty, return empty result
        if(digits.empty()) return {};
        
        // mapping of digits to letters (like a phone keypad)
        unordered_map<char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        
        // temp string to store the current combination
        string temp = "";
        
        // call the recursive function starting from index 0
        solve(0, digits, temp, mp);
        
        // return the result containing all letter combinations
        return result;
    }
};
