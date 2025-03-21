class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end()); // Sort skills

        int n = skill.size();
        long long sum = skill[0] + skill[n - 1]; // Target sum for each pair
        long long chem = 0;

        int l = 0, r = n - 1;
        while (l < r) {
            if (skill[l] + skill[r] != sum) return -1; 
            chem += (long long)skill[l] * skill[r];
            l++;
            r--;
        }

        return chem;
    }
};