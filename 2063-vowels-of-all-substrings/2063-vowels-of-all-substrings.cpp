class Solution {
public:
    
    bool isvowel(char ch){
        return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
    }
    long long countVowels(string word) {
        long long sum = 0;
        int n = word.length();
        for(int i=0; i<n; i++){
            if(isvowel(word[i])){
                long long left = i+1;
                long long right = n-i;
                long long contribution = left * right;
                sum += contribution;
            }
        }
        return sum;
    }
};
