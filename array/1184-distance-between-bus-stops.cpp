// A bus has n stops numbered from 0 to n - 1 that form a circle.
// We know the distance between all pairs of neighboring stops where distance[i] is the distance between the stops number i and (i + 1) % n.
// The bus goes along both directions i.e. clockwise and counterclockwise.
// Return the shortest distance between the given start and destination stops.

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n=distance.size();
        int a=0;
        int b=0;
        int total=0;
        for(int i=0;i<n;i++){
            total+=distance[i];
            if(i<start){
                a+=distance[i];
            }
            if(i<destination){
                b+=distance[i];
            }
        }
        int c=b-a;
        return min(abs(c),total-abs(c));
    }
};
