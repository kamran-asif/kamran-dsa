class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
    //total cards ko groupSize se divide karke dekh lo — evenly divide hona chahiye
    if (hand.size() % groupSize != 0) return false;

    //frequency map banate hain — har card ki count store karenge
    map<int, int> freq;
    for (int card : hand) {
        freq[card]++;
    }

    //map me chhoti value se badi tak iterate karo
    for (auto& [card, count] : freq) {
        if (count > 0) {
            // consecutive group check karo
            for (int i = 1; i < groupSize; ++i) {
                int nextCard = card + i;

                // agar next consecutive card nahi mila ya insufficient frequency hai
                if (freq[nextCard] < count) {
                    return false;
                }

                // frequency reduce karo
                freq[nextCard] -= count;
            }
        }
    }
    return true;
}

   
    
};