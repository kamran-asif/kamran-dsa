class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        priority_queue<int>pq;
        int n=reward1.size(),ans=0;
        for(auto x:reward2){
            ans+=x;
        }
        for(int i=0;i<n;i++){
            pq.push(reward1[i]-reward2[i]);
        }
        int curr=ans;
        for(int i=0;i<k;i++){
          auto x=pq.top();
          pq.pop();
          curr+=x;
        }
        return curr;
    }
};