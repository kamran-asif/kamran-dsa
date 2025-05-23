class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
long long sum=0;
vector<long long>res;//store net gain for each node if it is xored with k
//calculate the base sum and possible gain/loss for flipping node using xor k
for(int x:nums){
    sum+=x;//add the original value of node to the total sum
    int y=x^k;//calculate the value of xor with k
    res.push_back(y-x);//store the gain os loss from flipping this node
}
//sort the gain/loss values in descending order to priotize gains
sort(res.begin(),res.end());//sort in ascending order
reverse(res.begin(),res.end());//then reverse it first to get descending order
//to apply top gains in pairs
for(int i=0;i<res.size()-1;i+=2){
    //if the sum of a pair of gains is not beneficial,stop applying operations
    if(res[i]+res[i+1]<=0)break;
    //otherwise,apply this pair of operation by adding thier combined gain to the sum
    sum+=res[i]+res[i+1];
    }
    //return the final sum
    return sum;
    }
};