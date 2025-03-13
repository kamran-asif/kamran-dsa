class Solution {
public:
    bool judgeCircle(string moves) {
        int updwn=0,lftright=0;
        for(char move:moves){
            if(move=='U')updwn++;
              else if(move=='D')updwn--;
                else if(move=='L')lftright++;
                  else if(move=='R')lftright--;
        }
       return updwn==0&&lftright==0;
    }
};