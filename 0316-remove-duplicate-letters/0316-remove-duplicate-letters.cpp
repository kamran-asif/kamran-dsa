class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }

        stack<char> st;
        vector<bool> seen(26, false);

        for (int i = 0; i < s.size(); i++) {
            if (seen[s[i] - 'a']) { // Fix: Correct condition
                freq[s[i] - 'a']--;
                continue;
            }
            while (!st.empty() && st.top() > s[i] && freq[st.top() - 'a'] > 0) {
                seen[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            seen[s[i] - 'a'] = true;
            freq[s[i] - 'a']--;
        }

        string ans = "";
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
