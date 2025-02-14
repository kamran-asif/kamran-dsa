class Solution {
public:
int n,m;
int t[501][20001];
int solve(int i,int j,vector<int>& nums1, vector<int>& nums2){
if(i>=m||j>=n){
            return 0;
        }if(t[i][j]!=-1){
            return t[i][j];
        }
        if (nums1[i] == nums2[j]) {
            return t[i][j] = 1 + solve(i + 1, j + 1, nums1, nums2); 
        }else{
            int fix_i=solve(i,j+1,nums1,nums2);
            int fix_j=solve(i+1,j,nums1,nums2);
            return t[i][j]=max(fix_i,fix_j);
                    }
}
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        m=nums2.size();
         for (int i = 0; i < 501; i++) {
            for (int j = 0; j < 20001; j++) {
                t[i][j] = -1;
            }
        }
return solve(0,0,nums1,nums2);
            }
};