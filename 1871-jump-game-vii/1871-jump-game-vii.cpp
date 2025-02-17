class Solution {
public:
// sbse phle tree diagram bnao uske baad jb tree diagra bnaoge to ta lgega ki  destination pr phunchna h to bfs use krnge 
// bfs k liy queue chaye or queu m index add krnge
    bool canReach(string s, int minJump, int maxJump) {
        queue<int>que;
        que.push(0);
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                while(!que.empty()&&que.front()<i-maxJump){
                    que.pop();
                }
                if(que.empty())return false;
                int prev=que.front();
                if(prev+maxJump>=i&&prev+minJump<=i){
                    que.push(i);
                    if(i==n-1)return true;
                }
            }
        }
        return false;
    }
};