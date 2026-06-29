// A shop is selling candies at a discount. For every two candies sold, the shop gives a third candy for free.
// The customer can choose any candy to take away for free as long as the cost of the chosen candy is less than or equal to the minimum cost of the two candies bought.
// For example, if there are 4 candies with costs 1, 2, 3, and 4, and the customer buys candies with costs 2 and 3, they can take the candy with cost 1 for free, but not the candy with cost 4.
// Given a 0-indexed integer array cost, where cost[i] denotes the cost of the ith candy, return the minimum cost of buying all the candies.

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        sort(cost.begin(),cost.end());
        int ans=0;
        int count=1;
        for(int i=n-1;i>=0;i--){
            if(count%3!=0){
                ans+=cost[i];
            }
            count++;
        }
        return ans;
    }
};
