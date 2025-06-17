class Solution {
public://classic quesn revisit
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        //if tomato is even
     if(tomatoSlices%2!=0){
        //odd no valo tomato slices s kbhi 2 ya 4 burger ni bn skta
     return{};
     }
     //x=no of jumbo burgers(4 tomato, 1cheese)
      int x=(tomatoSlices-2*cheeseSlices)/2;
      // no of small burgers(2tomato ,1cheese)
        int y= cheeseSlices-x;
        ///validity checks(-ve burger cnt is invalid)
        if(x<0||y<0){
            return{};
            
            
                    }
                    // val combination
                    return {x,y};
    }
};