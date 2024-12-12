class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //taking a map size 256
        vector<int>mp(256,-1);
        //2pointer
        int left=0,right=0;
        int n=s.size();
        int len=0;
        // iterating over map
        while(right<n){
            //if the s[right] is seen then perform the task
            if(mp[s[right]]!=-1)
            //update left max(s[right]+1,left)
                left=max(mp[s[right]]+1,left);
                //right into the map in position of s[right]
                mp[s[right]]=right;
                //update len max(len,right-left+1)
                len=max(len,right-left+1);
                //right ko bdhao
                right++;
            
        }
        return len;
    }
};