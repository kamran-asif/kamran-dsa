class Solution {
public:
int n,m;
  int t[501][501];
  void solve(string &s1,string&s2,int i,int j){
           if(i==m){
            return n-j;//insert in s1
           }else if(j==n){
                   return m-1;// delete from s2 
           }
           if(s1[i]==s2[j]){
            return solve(s1,s2,i+1,j+1);
           }else{
            int insertc=1+solve(s1,s2,i,j+1);
            int insertc=1+solve(s1,s2,i,j+1);
           }

  }
    int minDistance(string word1, string word2) {
     

    }
};