class Solution {
public:
    int minimumChairs(string s) {
        int crrpple=0,mxchair=0;
        for(char c:s){
            if(c=='E'){
                crrpple++;
                mxchair=max(mxchair,crrpple);
            }else{
                crrpple--;
            }
        }
        return mxchair;
    }
};