class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xor_result=start^goal;
        int cnt=0;
        while(xor_result){
            cnt+=xor_result&1;
           xor_result>>=1;
        }
        return cnt;
    }
};