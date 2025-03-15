class Solution {
public:
    int countNumbersWithUniqueDigits(int n){
    if (n == 0) return 1;
      int total=10;//f(1)=10(digt 0->9)
        int product=9,availableDigits=9;
        for (int i=2;i<=n;i++){
            product*=availableDigits;
            availableDigits--;// rdce avilble chics
            total+=product;
        }
        return total;
    }
};
