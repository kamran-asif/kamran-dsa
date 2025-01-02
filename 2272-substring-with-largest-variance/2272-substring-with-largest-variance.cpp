class Solution {
public:
    int largestVariance(string s) {
        vector<int>count(26,0);
        for(char &ch:s){
            //index nikalne ke lye -a kr rhe hai
            count[ch='a']=1;
              }
        int result=0;
        for(char first='a';first<='z';first++){
                 for(char second='a';second<='z';second++){
                    // agr count m present hi ni hai to continue (age bdh jao)
                    if(count[first-'a']||count[second-'a']==0)
                    continue;
                    int firstcount=0;//f1
                    int secondcount=0;//f2
                    bool pastsecond=false;//peeche dekhne k lye
                    //pure strng m jaoo or freq count kro firstcount or secondcnt ka
                    for(char& ch:s){
                        if(ch==first)
                        firstcount++;
                        if(ch==second)
                        secondcount++;
                        //f1-f2 
                        if(secondcount>0){
                            result=max(result,firstcount-secondcount);
                        }else if(pastsecond==true){
                            result=max(result,firstcount-1);//past m b ko dkha hai to isly -1 kr rhe
                        }
                        if(secondcount>firstcount){
                            secondcount=0;
                            firstcount=0;
                            pastsecond=true;//ye ni smjh aya dubara dkhna
                        }
                    }
        }
        
        }
        return result;
    }
};