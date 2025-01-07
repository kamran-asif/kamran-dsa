class Solution {
public:
//palindrome hota hai jiska 1st hlf 2nd hlf k equal ho jo bi odd elmnt hai usko beech m daldo           
//palindrome chck krne k lye phle lft or ri8 ko chck krte hai agr apas m eql ni hai to do pointer lete hai  or 1st hlf k crsponding 2nd hlf ko bdhana hai
    int minMovesToMakePalindrome(string s) {
        int n=s.size();
        int result=0;
        
        while(!s.empty()){
           
           int i=s.find(s.back());//index of 1st occurunces of last chrctr strng k dhund rhe hai
//chck kro ki last chrctr unique hai ki ni(i.e.no matching character exists).ye true tb hai jbchrctr k index i jo hai vo last index ho strng m
           if(i==s.size()-1){
            
            result+=i/2; //agr chrctr unique hai to hmlog no of move nikalnge take vo cntr m aa ske ye hoga hmlog uska positon ko divide krenge 2 se
         }else{ 
             // ye tbhi execute hoga jb lst chrctr k pass matchng chrctr ho strng m
            
            result+=i;    // Adds the index of the matched character (i) to res, representing the number of moves required to bring the matched character next to the last character.
            s.erase(s.begin()+i);// remve kr rha hai match chrctr strng s
           }
           s.pop_back();// last chrctr ko remve kr rha hai strng s handle krne k baad(ya to unique chrctr ya fir as a pair)
        }
        return result;
    }
};