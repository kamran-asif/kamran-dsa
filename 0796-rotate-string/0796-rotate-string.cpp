class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }

        string doubled_s = s + s;

        if (doubled_s.find(goal) != string::npos) {
            return true;
        }

        return false;
    }
};