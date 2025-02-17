class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool>visited(arr.size(),false);
     return helper(arr,start,visited);   
    }
    private:
    bool helper(vector<int>& arr,int i,vector<bool>&visited){
        if(i<0||i>=arr.size())
        return false;
        if (arr[i] == 0) return true;
        if(visited[i])
        return false;
        visited[i]=true;
return helper(arr,i+arr[i],visited)||helper(arr,i-arr[i],visited);

    }
};