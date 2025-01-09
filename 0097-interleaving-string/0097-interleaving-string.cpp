class Solution {
public:
    int m, n, N;
    int t[101][101][201];//{-1,0,1} is t m kya kya ho skta hai -1 hai to false hai 0 mtb nhi bhai orsnt 1 mtb true

    bool solve(int i, int j, int k, string &s1, string &s2, string &s3) {
        // base case agr sare hi chrctrs use hogye ho s1,s2,s3 ke
        if (i == m && j == n && k == N) {
            return true;
        }
        // agr k exceeds krjaye s3 ki length ya i/j exceed krjaye s1/2 ki length se
        if (k >= N || i > m || j > n) {
            return false;
        }
        
        if (t[i][j][k] != -1) {//agr result phle s compute hai
            return t[i][j][k];
        }

        bool result = false;
        if (i < m && s1[i] == s3[k]) {// agr crrnt chrctr s1 matchs s3
            result =solve(i + 1, j, k + 1, s1, s2, s3);
        }
           // agr crrnt chrctr s2 mtchs s3 
        if (j < n && s2[j] == s3[k]) {
            result = solve(i, j + 1, k + 1, s1, s2, s3);
        }
        return t[i][j][k] = result;
    }

    bool isInterleave(string s1, string s2, string s3) {
        m = s1.length();
        n = s2.length();
        N = s3.length();

        if (m + n != N) {// agr combine length s1 and s2 k mtch ni kya s3 s
            return false;
        }

      //initialize kr rhe hai
        memset(t, -1, sizeof(t));

        return solve(0, 0, 0, s1, s2, s3);// strt solving frm the begining of strng 
    }
};
