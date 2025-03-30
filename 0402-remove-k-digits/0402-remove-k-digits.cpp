class Solution {
public:
    string removeKdigits(string num, int k) {
          if (k == num.size()) return "0";
    
    stack<char> st;
    
    for (char digit : num) {
        while (!st.empty() && k > 0 && st.top() > digit) {
            st.pop();
            k--;
        }
        st.push(digit);
    }
    
    while (k > 0 && !st.empty()) {
        st.pop();
        k--;
    }
    
    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    
    reverse(result.begin(), result.end());
    
    int start = 0;
    while (start < result.size() && result[start] == '0') {
        start++;
    }
    result = result.substr(start);
    
    return result.empty() ? "0" : result;
}
};