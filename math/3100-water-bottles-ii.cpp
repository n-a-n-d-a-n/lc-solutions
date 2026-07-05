class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int bDrunk=0;
        int eBottles=0;
        while(numBottles>0){
            bDrunk+=numBottles;
            eBottles+=numBottles;
            numBottles=0;
            while(eBottles>=numExchange){
                eBottles-=numExchange;
                numBottles++;
                numExchange++;
            }
        }
        return bDrunk;
    }
};
