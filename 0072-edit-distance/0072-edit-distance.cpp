class Solution {
public:
int n,m;
  int t[501][501];
  int solve(string &s1,string&s2,int i,int j){
           if(i==m){
            return n-j;//insert in s1
           }else if(j==n){
                   return m-i;// delete from s2 
           }
           if(t[i][j]!=-1){
           return t[i][j];
           }
           if(s1[i]==s2[j]){
            return t[i][j]=solve(s1,s2,i+1,j+1);
           }else{
            int insertc=1+solve(s1,s2,i,j+1);
            int deletec=1+solve(s1,s2,i+1,j);
            int replacec=1+solve(s1,s2,i+1,j+1);
            return t[i][j]=min({insertc,deletec,replacec});
           }
           return -1;

  }
    int minDistance(string s1, string s2) {
     
m=s1.length();
n=s2.length();
memset(t,-1,sizeof(t));
return solve(s1,s2,0,0);


    }
};