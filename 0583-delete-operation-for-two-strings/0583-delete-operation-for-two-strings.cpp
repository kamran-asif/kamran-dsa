class Solution {
public://bottom up h isly last s n-1 or m-1 s strt kr rhe h
int n,m;
int t[501][501];
int solve(string words1, string words2,int i,int j){
    if(i<0)
    return j+1;
    if(j<0)
    return i+1;
    if(t[i][j]!=-1)
    return t[i][j];
    if(words1[i]==words2[j])
    return solve(words1,words2,i-1,j-1);
    else{
        return t[i][j]=1+min(solve(words1,words2,i-1,j),solve(words1,words2,i,j-1));
    }
}
    int minDistance(string words1, string words2) {
        n=words1.length();
        m=words2.length();
        memset(t,-1,sizeof(t));
    return solve(words1,words2,n-1,m-1);
    }
};