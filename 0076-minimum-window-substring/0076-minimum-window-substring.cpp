#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // need array se har character ki t me kitni baar zaroorat hai track karenge
        vector<int> need(128, 0);
        for (char c : t) {
            need[c]++;  // t ke har char ki frequency count karo
        }

        int missing = t.size();   // abhi tak kitne chars match hone baaki hain
        int left = 0;             // sliding window ka left pointer
        int start = 0, len = INT_MAX;  // best window ka start index aur length

        // right pointer se window expand karenge
        for (int right = 0; right < s.size(); right++) {
            // agar current char ki zaroorat hai (need>0), toh missing ghat jayega
            if (need[s[right]] > 0) {
                missing--;
            }
            // need se count hamesha update karo chahe extra char ho
            need[s[right]]--;

            // jab missing==0, matlab window valid hai sab chars cover hue
            while (missing == 0) {
                // agar current window chhota hai previous best se, update karo
                if (right - left + 1 < len) {
                    start = left;
                    len = right - left + 1;
                }
                // ab left se shrink karne ki koshish
                need[s[left]]++;         // jo char remove ho raha, uski count wapas badhao
                if (need[s[left]] > 0) {
                    // agar ye char waapas required hua, toh window invalid ho jayega
                    missing++;
                }
                left++;  // window shrink
            }
        }

        // agar len update nahi hua, toh koi valid window nahi mila
        return (len == INT_MAX) ? "" : s.substr(start, len);
    }
};
