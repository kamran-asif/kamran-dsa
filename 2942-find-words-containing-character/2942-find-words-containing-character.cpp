class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>result;
 //check if the chrctr x exists in the crrnt wrd
        for(int i=0;i<words.size();i++){
              //string npos not found
          if(words[i].find(x)!=string::npos){
            //string npos not found
// if chrctr x is found ,
            result.push_back(i);
          }
        } 
        
        return result;   
    }
};