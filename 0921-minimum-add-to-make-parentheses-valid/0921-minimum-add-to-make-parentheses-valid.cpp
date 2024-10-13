class Solution {
public:
    int minAddToMakeValid(string s) {
        int khula = 0;
        int band = 0;

        for (char c : s) {
            if (c == '(') {
                khula++;
            } else {

                if (khula > 0) {
                    khula--;
                } else {
                    band++; 
                }
            }
        }
        return khula+ band;
    }
};