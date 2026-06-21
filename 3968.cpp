// You are given a string moves consisting of the characters 'U', 'D', 'L', 'R', and '_'.
// Starting from the origin (0, 0), each character represents one move on a 2D plane:
// 'U': Move up by 1 unit.
// 'D': Move down by 1 unit.
// 'L': Move left by 1 unit.
// 'R': Move right by 1 unit.
// '_': Can be independently replaced with any one of 'U', 'D', 'L', or 'R'.
// Return the maximum Manhattan distance from the origin that can be achieved after all moves have been performed.

class Solution {
public:
    int maxDistance(string moves) {
        int x=0;
        int y=0;
        int dis=0;
        for(char move:moves){
            if(move=='R'){
                x++;
            }
            else if(move=='L'){
                x--;
            }
            else if(move=='U'){
                y++;
            }
            else if(move=='D'){
                y--;
            }
            else{
                dis+=1;
            }
        }
        return abs(x)+abs(y)+dis;
    }
};
