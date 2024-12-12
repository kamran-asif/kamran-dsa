class Solution {
public:

    
    int maxScore(vector<int>& cardPoints, int k) {
     int leftsum=0,rightsum=0,maxsum=0;
    int n=cardPoints.size();
    for(int start=0;start<k;start++){
        leftsum+=cardPoints[start];
        maxsum=leftsum;
    }
       int rightindex=n-1;
        for(int start=k-1;start>=0;start--){
          leftsum-=cardPoints[start];
          rightsum=rightsum+cardPoints[rightindex];
          rightindex--;
          maxsum=max(maxsum,leftsum+rightsum);
        }
    
    return maxsum;
    }
};