class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
                int box1 = 0, box2 = 0;
        int ans = 0;

        for (auto a : nums) {
            box1 += a;
            box2 += a;
            ans = max({ans, box1, abs(box2)});

            if (box1 < 0) 
                box1 = 0;

            if (box2 > 0) 
                box2 = 0;
        }
        return ans;
    }
    
};