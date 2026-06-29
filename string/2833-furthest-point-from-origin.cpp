// You are given a string moves of length n consisting only of characters 'L', 'R', and '_'.
// The string represents your movement on a number line starting from the origin 0.
// In the ith move, you can choose one of the following directions:
// move to the left if moves[i] = 'L' or moves[i] = '_'
// move to the right if moves[i] = 'R' or moves[i] = '_'
// Return the distance from the origin of the furthest point you can get to after n moves.

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int a=0,b=0,underscore=0;
        int count=0;
        for(char ch:moves){
            if(ch=='L'){
                a++;
            }
            else if(ch=='R'){
                b++;
            }
            else{
                underscore++;
            }
        }
        count=abs(a-b)+underscore;
        return count;
    }
};
