class Solution {
public://binary search
int cntlessequal(const vector<vector<int>>&matrix,int mid,int n){
int cnt=0;
        int row=n-1;
        int col=0;
        //strt from bottom-left crnr
        while(row>=0&&col<n){
            if(matrix[row][col]<=mid){
                cnt+=(row+1);//all elements in this column above crrnt row are<=mid
                col++;

            }else{
                row--;//uppr jao
            }
        }
        return cnt;
}
    int kthSmallest(vector<vector<int>>& matrix, int k) {
     int n=matrix.size();
     int low=matrix[0][0];//smallest element
     int high=matrix[n-1][n-1];//largest element
     while(low<high){
        int mid=low+(high-low)/2;
        int cnt=cntlessequal(matrix,mid,n);
        if(cnt<k){
            low=mid+1;

        }else{
            high=mid;
        }
     }   
     return low;
    }
}; 