class Solution {
public://asaan tha
    int numRescueBoats(vector<int>& people, int limit) {
      //array-people,weight-people[i],hr ek boat k max weight =limit ,atmost 2people-each boat same time unless sum of weight people atmost <=limit, return max no of boats 
    int n=people.size();
    sort(people.begin(),people.end());
    int i=0,j=n-1;
    int boats=0;
    while(i<=j){
        if(people[i]+people[j]==limit){
            i++;
            j--;
           
        }else{
            j--;
        }
        boats+=1;
    }
    return boats;
    }
};