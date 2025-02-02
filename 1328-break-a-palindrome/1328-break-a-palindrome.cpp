class Solution {
public:
// pakindrome-string,replace 1 ch to lowercase,resltng strng palindrome na ho joki dictionory k accrdng ho smallest possible ho ,return result strng ,koi ni hai aisa to emnpty return 

// string a lexicographically< string b 1st a or b differ kr rha ,a <b charctr string a-abcc<string b-abcd 
//sbse smllst lexicographically chota kon hota hai a uske baad b so on
     string breakPalindrome(string palindrome) {
        //length
        int n=palindrome.length();
        if(n==1)
        return "";
        for(int i=0;i<n/2;i++){
            if(palindrome[i]!='a'){
            palindrome[i]='a';
            return palindrome;
        }

        }
        palindrome[n-1]='b';
        return palindrome;
    }
};