class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0,cows=0;
        unordered_map<char,int> secretmap, guessmap;
        
        //bullscnt and non bull chrctr
        for(int i=0;i<secret.size();i++){
              if(secret[i]==guess[i]){
                bulls++;
              }else{
                secretmap[secret[i]]++;
                guessmap[guess[i]]++;
              }
        }
        
        //cws cnt
        for(auto &entry:guessmap){ 
            char digit=entry.first;
            cows+=min(entry.second,secretmap[digit]);
        }
        
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};
