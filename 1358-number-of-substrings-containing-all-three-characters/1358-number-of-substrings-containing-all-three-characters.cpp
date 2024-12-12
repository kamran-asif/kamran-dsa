class Solution {
public:
    int numberOfSubstrings(string s) {
      int lastseen[3]={-1,-1,-1};
      int count=0;
      int n=s.size();
      for(int start=0;start<n;start++){
          lastseen[s[start]-'a']=start;
          if(lastseen[0]!=-1&&lastseen[1]!=-1&&lastseen[2]!=-1){
            count+=1+min({lastseen[0],lastseen[1],lastseen[2]});
          }
      }  
      return count;
    }
};