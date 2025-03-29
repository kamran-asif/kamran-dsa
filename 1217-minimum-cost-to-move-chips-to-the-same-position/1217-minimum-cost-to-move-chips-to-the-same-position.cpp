class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int evencnt=0;
        int oddcnt=0;
        for(int pos:position){
            if(pos%2==0){
                evencnt++;
            }else{
                oddcnt++;
            }
        }
        return min(evencnt,oddcnt);
    }
};