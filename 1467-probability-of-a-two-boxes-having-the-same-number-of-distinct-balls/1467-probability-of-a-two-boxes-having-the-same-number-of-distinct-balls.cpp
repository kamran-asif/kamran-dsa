class Solution {
public:
   long double total=0;//ttl combnitn cnt 
   long double valid=0;//valid cmbnt cnt jsme dono box sme no of dstnct colors ke ho
   long double fact[49];//factorial ko precompute krne k liy array h or max sum of balls 48 h
  void initFactorial() {//ye func factorial ko precompute kr rha h o(n)time m
    fact[0]=1;
    for(int i=1;i<=48;i++){//why we start from i=1 kyuki i-1 =-ve m chla jayega isly
        fact[i]=fact[i-1]*i;

    }
   }
   //kch ni dfs func use kr rhe sare distrbtn ko explore krne k liy recursvly
   void dfs(const vector<int>&balls,int idx,int leftcount,int rightcount,int leftcolors,int rightcolors,vector<int>&left,vector<int>&right){
         //basecase sbhi clrs dkh liy
         if(idx==balls.size()){
            //agr ball k cnt match ni krta to ignore
            if(leftcount!=rightcount)return;
            //permutation calculate kro dono boxes k liy
            double leftprem=fact[leftcount];
            double rightprem=fact[rightcount];
            for(int i=0;i<balls.size();i++){
              leftprem/=fact[left[i]];
              rightprem/=fact[right[i]];
            }
            double ways=leftprem*rightprem;
            total+=ways;
//distnct colors equal h dono boxes m to valid combnt 
            if(leftcolors==rightcolors){
                valid+=ways;
            }
            return;
         }
         //hr colors k box ko distribute kro 0->leke balls[idx]tk
          for(int i=0;i<=balls[idx];i++){
            left[idx]=i;
            right[idx]=balls[idx]-i;
            // cnt colors agr kisi box m us color k ek bhi ball gya ho
            int newleftcolors=leftcolors+(i>0?1:0);
            int newrightcolors=rightcolors+(right[idx]>0?1:0);
            dfs(balls,idx+1,leftcount+i,rightcount+right[idx],newleftcolors,newrightcolors,left,right);
          }

   }
    double getProbability(vector<int>& balls) {
        initFactorial();
        int k=balls.size();
        vector<int>left(k),right(k);//crrnt distribution
        dfs(balls,0,0,0,0,0,left,right);
        return valid/total;
    }
};