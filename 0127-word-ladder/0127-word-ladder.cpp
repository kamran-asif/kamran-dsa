class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //phle chck kro ki ednword wordlist m hai ya ni
        bool found = false;
        for (auto &w : wordList) {
            //hr word s cmpare krte h
            if (w == endWord) {
                found = true;//agr match milgya to flag true
                break;//aur loop s bhar nkl jao
            }
        }
        if (!found) return 0;//agr endword list m ni h to return 0

        int L = beginWord.length();//l m beginword ki length store kro
//preprocessing hr word ke genric forms banao aur map kro


//jaise"hot" ke liy"*ot","h*t","ho"        
        unordered_map<string, vector<string>> allComboDict;
        for (auto &word : wordList) {
            for (int i = 0; i < L; ++i) {
                string generic = word.substr(0, i) + '*' + word.substr(i+1);
                allComboDict[generic].push_back(word);
            }
        }

        
        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        unordered_set<string> visited;
        visited.insert(beginWord);

        while (!q.empty()) {
            auto [current, level] = q.front();
            q.pop();

            for (int i = 0; i < L; ++i) {
                string generic = current.substr(0, i) + '*' + current.substr(i+1);

                for (auto &adjWord : allComboDict[generic]) {
                    if (adjWord == endWord) {
                        return level + 1;
                    }
                    if (!visited.count(adjWord)) {
                        visited.insert(adjWord);
                        q.push({adjWord, level + 1});
                    }
                }

                allComboDict[generic].clear();
            }
        }

        return 0;
    }
};
