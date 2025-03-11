class Solution {
public:
    int hammingWeight(int n) {
    int count = 0;
    while (n > 0) {
        count += n & 1; // check the last bit
        n >>= 1;        // ight shift to check the next bit
    
    return count;
}

    
};