class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // we are supposed to buy and sell only when the prices are in increasing order
        int n = prices.size();
        
        int l = 0;
        int r = 1;

        int profit = 0;

        while(r < n){
            if(prices[r] > prices[l]){
                profit += prices[r] - prices[l];
            }
            l = r;
            r = r+1;            
        }
        return profit;  
    }
};