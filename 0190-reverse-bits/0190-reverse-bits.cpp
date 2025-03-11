class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result=0;
        for(int i=0;i<32;i++){
          result<<=1;//==mltpy by 2// means space dal rhe h
          result|=(n&1);// result m or operation kr rhe h 1 k sath
        n>>=1;
        }
        return result;
    }
};