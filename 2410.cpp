// You are given a 0-indexed integer array players, where players[i] represents the ability of the ith player.
// You are also given a 0-indexed integer array trainers, where trainers[j] represents the training capacity of the jth trainer.
// The ith player can match with the jth trainer if the player's ability is less than or equal to the trainer's training capacity.
// Additionally, the ith player can be matched with at most one trainer, and the jth trainer can be matched with at most one player.
// Return the maximum number of matchings between players and trainers that satisfy these conditions.

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n=players.size();
        int o=trainers.size();
        int l=0;
        int r=0;
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        while(l<o&&r<n){
            if(players[r]<=trainers[l]){
                r++;
            }
            l++;
        }
        return r;
    }
};
