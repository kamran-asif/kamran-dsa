class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;                             // result store karne ke liye
        int n = s.size();                            // s ki total length
        int m = words.size();                        // words me kitne strings hain
        if (n == 0 || m == 0) return res;            // base case: agar s ya words khaali ho to return
        
        //concept 1: Hash-Map for Frequency Counting
        int wordlen = words[0].size();               // har word ka length (sab same length ke hain)
        int totalLen = wordlen * m;                  // concatenated substring ki total length
        if (n < totalLen) return res;                // agar s ka size chhota ho to koi match nahi
        unordered_map<string,int> freq;              // words ki expected frequency store karne ke liye
        for (auto &w : words) freq[w]++;
        
        //concept 2: Multiple Offsets (Staggered Sliding Windows) ====
        // har possible starting offset jisse word boundaries align ho
        for (int offset = 0; offset < wordlen; offset++) {
            int left = offset, cnt = 0;               // window left pointer aur matched words count
            unordered_map<string,int> window;        // current window ki observed frequency
            
            //concept 3: Fixed-Size Sliding Window with Two-Pointer Technique ====
            for (int right = offset; right + wordlen <= n; right += wordlen) {
                string w = s.substr(right, wordlen); // next chunk extract
                
                if (freq.count(w)) {
                    //concept 4: Expand Window and Count ====
                    window[w]++;
                    cnt++;
                    
                    //concept 5: Shrink Window When Overfull ====
                    while (window[w] > freq[w]) {
                        string lw = s.substr(left, wordlen);
                        window[lw]--;
                        left += wordlen;
                        cnt--;
                    }
                    
                    // concept 6: Greedy Accept & Release on Full Match ====
                    if (cnt == m) {
                        res.push_back(left);            // pura sequence match hua, index add
                        // ab ek word release karke aage badho (slide window)
                        string lw = s.substr(left, wordlen);
                        window[lw]--;
                        left += wordlen;
                        cnt--;
                    }
                } else {
                    // concept 7: Reset Window on Invalid Word ====
                    window.clear();                  // pura window reset
                    cnt = 0;
                    left = right + wordlen;         // next candidate start
                }
            }
        }
        return res;                                  
    }
};
