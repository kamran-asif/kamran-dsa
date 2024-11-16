class Solution {
public:
    bool isPalindrome(string s) {

        string orig = "";
        string revstr = "";
        // remove unnecessary
        for (auto it : s) {
            
            if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <=                 'Z') || (it >= '0' && it <= '9')) {
                orig += it;
            }
        }
        //make small
        for (int itr = 0; itr < orig.size(); itr++) {

            char curr = orig[itr];
            if ((curr >= 'A' && curr <= 'Z')) {
                orig[itr] = curr - 'A' + 'a';
            }
        } 

        // reverse
        for (int i = orig.size() - 1; i >= 0; i--) {
            revstr += orig[i];
        }
        // compare
        if (revstr != orig)
            return false;
        return true;
    }
};